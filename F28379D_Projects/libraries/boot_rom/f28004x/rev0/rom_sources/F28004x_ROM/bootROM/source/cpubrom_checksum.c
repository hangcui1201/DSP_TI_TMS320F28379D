//###########################################################################
//
// FILE:    checksum.c
//
// TITLE:   boot ROM checksum generator
//
// Functions:
//
//
// Notes:
//
//###########################################################################
// $TI Release: F28004x Boot ROM V1.0 $
// $Release Date: July 2015 $
//###########################################################################

#include "bootrom.h"

typedef struct {
       unsigned long firstAddr;
       unsigned long lastAddr;
       unsigned short mem_attribute;	//initialized to 0 for reserved locations and 1 for valid data locations
} memblock;


// Use 4 32-bit values to represent the 64-bit checksum.
// This is done such that overflow can be monitored at
// each step in the summation.   If overflow from the lower
// 16-bits occurs, then the overflow is added to the next
// significant word.

typedef struct {
       unsigned long highHalfMSW;
       unsigned long highHalfLSW;
       unsigned long lowHalfMSW;
       unsigned long lowHalfLSW;
} ui64;

typedef struct checksum_data
{
	unsigned long total_ones;
	unsigned long bit_column_cksum[8][3];
	ui64 row_weight_sum;
	ui64 fact_weight_sum;
}composite_checksum_t;

#pragma DATA_SECTION(pbist_csum_rom, ".PBIST_CKSUMLOC");
const composite_checksum_t pbist_csum_rom = {
		0x00028BF7,	//total_ones
		0x0000B751, 0x00000C85, 00000000,	//bit_column_cksum[0][3];
		0x0000FF9F, 0x00001142, 00000000,	//bit_column_cksum[1][3];
		0x0000A1D9, 0x0000101F, 00000000,	//bit_column_cksum[2][3];
		0x00002168, 0x00000DF3, 00000000,	//bit_column_cksum[3][3];
		0x00003691, 0x00000CA0, 00000000,	//bit_column_cksum[4][3];
		0x000052C6, 0x00000C35, 00000000,	//bit_column_cksum[5][3];
		0x000078DF, 0x00000C05, 00000000,	//bit_column_cksum[6][3];
		0x0000CD43, 0x00000CB1, 00000000,	//bit_column_cksum[7][3];
		0x00000000, 0x00000003, 0x00006B36, 0x0000746A,//row_weight_sum
		0x00000000, 0x00001D0A, 0x0000E0AD, 0x0000E60A	//fact_weight_sum
};

#pragma DATA_SECTION(csum_rom, ".CKSUMLOC");
const composite_checksum_t csum_rom = {
		0x001374E7,	//total_ones
		0x000069DD, 0x00006AAB, 0x00000002,	//bit_column_cksum[0][3];
		0x0000DECB, 0x0000AB05, 0x00000002,	//bit_column_cksum[1][3];
		0x0000B8C6, 0x0000AF6C, 0x00000002,	//bit_column_cksum[2][3];
		0x00009AA0, 0x00006F29, 0x00000002,	//bit_column_cksum[3][3];
		0x00007E4A, 0x00008C17, 0x00000002,	//bit_column_cksum[4][3];
		0x0000346D, 0x0000D721, 0x00000002,	//bit_column_cksum[5][3];
		0x0000C41C, 0x000092AC, 0x00000002,	//bit_column_cksum[6][3];
		0x00007CEA, 0x00007691, 0x00000002,	//bit_column_cksum[7][3];
		0x00000000, 0x000000A5, 0x0000059C, 0x0000B146,//row_weight_sum
		0x00000000, 0x00009F32, 0x00000ED1, 0x00000AF3	//fact_weight_sum
};

#if 1/// no stable compiler available

#pragma CODE_SECTION(verify_pbist_checksum_onROM, ".CKSUMFUNCS");
unsigned short verify_pbist_checksum_onROM();

#pragma CODE_SECTION(calculate_composite_checksum_on_rom, ".CKSUMFUNCS");
unsigned short calculate_composite_checksum_on_rom(composite_checksum_t *cksum, memblock *mblock, unsigned int total_mblocks);

#pragma CODE_SECTION(add_to_factorial_sum, ".CKSUMFUNCS");
void add_to_factorial_sum(unsigned long fact_weight, composite_checksum_t *cksum);

#pragma CODE_SECTION(add_to_row_weight_sum, ".CKSUMFUNCS");
void add_to_row_weight_sum(unsigned long ones_weight, composite_checksum_t *cksum);

#pragma CODE_SECTION(add_to_bitcolumn_checksum, ".CKSUMFUNCS");
unsigned long add_to_bitcolumn_checksum(unsigned long bitcolumn, unsigned long bit_weight, composite_checksum_t *cksum);

#pragma CODE_SECTION(compare_two_composite_checksums, ".CKSUMFUNCS");
unsigned short compare_two_composite_checksums(const composite_checksum_t *goldsum, composite_checksum_t *compsum);

#pragma CODE_SECTION(calculate_checksum, ".CKSUMFUNCS");
unsigned long calculate_checksum(unsigned long start, unsigned long end, unsigned long offset, composite_checksum_t *cksum);

#pragma CODE_SECTION(test_reserved_memory, ".CKSUMFUNCS");
unsigned short test_reserved_memory(unsigned long start, unsigned long end);


unsigned short test_reserved_memory(unsigned long start, unsigned long end)
{
	if(start & ~(0x3FFFFF))	//address beyond 22 bits
	{
		while(start <=end )
		{
			if(__addr32_read_uint16(start++) != (unsigned long)0xFFFF)
			{
				return 0xFFFF;	//error
			}
		}
	}
	else
	{
		while(start <=end )
		{
			if(* (volatile unsigned short *)start++ != (unsigned long)0xFFFF)
			{
				return 0xFFFF;	//error
			}
		}
	}
	return 0;
}

// This main function performs a very simple 64 bit checksum routine.
// 4 32-bit values are used to calculate the checksum.  This is done so that
// no overflow is lost.  After each addition, the value is checked to see if
// it has overflowed the lower 16-bits.  If it has, then the overflow portion
// in the upper 16-bits is added to the next most significant portion of the
// checksum.
//
// When the routine completes, the upper 16-bits of each portion of the checksum
// will be 0x000 - this portion should be discarded as it was only used to check
// for overflow and the checksum is then formed from the lower 16-bits.
//
// For example:
//     lowHalfLSW  = 0x00001111
//     lowHalfMSW  = 0x00002222
//     highHalfLSW = 0x00003333
//     highHalfMSW = 0x00004444
//
//     would result in a 64-bit checksum of 0x44443333 22221111

unsigned short calculate_composite_checksum_on_rom(composite_checksum_t *cksum, memblock *mblock, unsigned int total_mblocks)
{
      unsigned short i;
      unsigned long offset = 0;
      memblock *lmblock = (void *)0;
      unsigned short result = 0;

      cksum->row_weight_sum.highHalfMSW = 0;
      cksum->row_weight_sum.highHalfLSW = 0;
      cksum->row_weight_sum.lowHalfLSW = 0;
      cksum->row_weight_sum.lowHalfMSW = 0;

      cksum->fact_weight_sum.highHalfMSW = 0;
      cksum->fact_weight_sum.highHalfLSW = 0;
      cksum->fact_weight_sum.lowHalfLSW = 0;
      cksum->fact_weight_sum.lowHalfMSW = 0;
      
      cksum->total_ones = 0;
   
      cksum->bit_column_cksum[0][0] = cksum->bit_column_cksum[1][0] = cksum->bit_column_cksum[2][0] = cksum->bit_column_cksum[3][0] = 0;
      cksum->bit_column_cksum[4][0] = cksum->bit_column_cksum[5][0] = cksum->bit_column_cksum[6][0] = cksum->bit_column_cksum[7][0] = 0;
   
      cksum->bit_column_cksum[0][1] = cksum->bit_column_cksum[1][1] = cksum->bit_column_cksum[2][1] = cksum->bit_column_cksum[3][1] = 0;
      cksum->bit_column_cksum[4][1] = cksum->bit_column_cksum[5][1] = cksum->bit_column_cksum[6][1] = cksum->bit_column_cksum[7][1] = 0;
   
      cksum->bit_column_cksum[0][2] = cksum->bit_column_cksum[1][2] = cksum->bit_column_cksum[2][2] = cksum->bit_column_cksum[3][2] = 0;
      cksum->bit_column_cksum[4][2] = cksum->bit_column_cksum[5][2] = cksum->bit_column_cksum[6][2] = cksum->bit_column_cksum[7][2] = 0;

      for(i = 0; i < total_mblocks; i++) {
    	  lmblock = (memblock *)(&mblock[i]);
		   if (lmblock->mem_attribute == 0)
		   {
				result = test_reserved_memory((unsigned long)(lmblock->firstAddr), (unsigned long)(lmblock->lastAddr));
				if(result == 0xFFFF)
					return 0xFFFF;
		   }
		   else if(lmblock->mem_attribute == 1)
		   {
			   offset = calculate_checksum((unsigned long)(lmblock->firstAddr), (unsigned long)(lmblock->lastAddr), offset, cksum);
		   }
	  }
    return 0;
} 


void add_to_factorial_sum(unsigned long fact_weight, composite_checksum_t *cksum)
{
	   // Add in LSW
	    cksum->fact_weight_sum.lowHalfLSW += (fact_weight & (unsigned long)0x0000FFFF);

	   // Check for overflow
	   if(cksum->fact_weight_sum.lowHalfLSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->fact_weight_sum.lowHalfMSW += cksum->fact_weight_sum.lowHalfLSW >> 16;
		   cksum->fact_weight_sum.lowHalfLSW &= (unsigned long)0x0000FFFF;
	   }
   
	   if(cksum->fact_weight_sum.lowHalfMSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->fact_weight_sum.highHalfLSW += cksum->fact_weight_sum.lowHalfMSW >> 16;
		   cksum->fact_weight_sum.lowHalfMSW &= (unsigned long)0x0000FFFF;
	   }

	   if(cksum->fact_weight_sum.highHalfLSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->fact_weight_sum.highHalfMSW += cksum->fact_weight_sum.lowHalfLSW >> 16;
		   cksum->fact_weight_sum.highHalfLSW &= (unsigned long)0x0000FFFF;
	   }

	   // Add in MSW
	   cksum->fact_weight_sum.lowHalfMSW += (fact_weight >> 16);
	   // Check for overflow
	   if(cksum->fact_weight_sum.lowHalfMSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->fact_weight_sum.highHalfLSW += cksum->fact_weight_sum.lowHalfMSW >> 16;
		   cksum->fact_weight_sum.lowHalfMSW &= (unsigned long)0x0000FFFF;
	   }

	   if(cksum->fact_weight_sum.highHalfLSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->fact_weight_sum.highHalfMSW += cksum->fact_weight_sum.lowHalfLSW >> 16;
		   cksum->fact_weight_sum.highHalfLSW &= (unsigned long)0x0000FFFF;
	   }
}

void add_to_row_weight_sum(unsigned long ones_weight, composite_checksum_t *cksum)
{
	   // Add in LSW
	   cksum->row_weight_sum.lowHalfLSW += (ones_weight & (unsigned long)0x0000FFFF);

	   // Check for overflow
	   if(cksum->row_weight_sum.lowHalfLSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->row_weight_sum.lowHalfMSW += cksum->row_weight_sum.lowHalfLSW >> 16;
		   cksum->row_weight_sum.lowHalfLSW &= (unsigned long)0x0000FFFF;
	   }
   
	   if(cksum->row_weight_sum.lowHalfMSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->row_weight_sum.highHalfLSW += cksum->row_weight_sum.lowHalfMSW >> 16;
		   cksum->row_weight_sum.lowHalfMSW &= (unsigned long)0x0000FFFF;
	   }

	   if(cksum->row_weight_sum.highHalfLSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->row_weight_sum.highHalfMSW += cksum->row_weight_sum.lowHalfLSW >> 16;
		   cksum->row_weight_sum.highHalfLSW &= (unsigned long)0x0000FFFF;
	   }

	   // Add in MSW
	   cksum->row_weight_sum.lowHalfMSW += (ones_weight >> 16);
	   // Check for overflow
	   if(cksum->row_weight_sum.lowHalfMSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->row_weight_sum.highHalfLSW += cksum->row_weight_sum.lowHalfMSW >> 16;
		   cksum->row_weight_sum.lowHalfMSW &= (unsigned long)0x0000FFFF;
	   }

	   if(cksum->row_weight_sum.highHalfLSW >= (unsigned long)0x0000FFFF)
	   {
		   cksum->row_weight_sum.highHalfMSW += cksum->row_weight_sum.lowHalfLSW >> 16;
		   cksum->row_weight_sum.highHalfLSW &= (unsigned long)0x0000FFFF;
	   }
}

//returns ones weight of the bit just added - ones weight = 8*(bitweight-1)+bitcolumn.
unsigned long add_to_bitcolumn_checksum(unsigned long bitcolumn, unsigned long bit_weight, composite_checksum_t *cksum)
{
	   // Add in LSW
	   cksum->bit_column_cksum[bitcolumn][0] += (bit_weight & (unsigned long)0x0000FFFF);

	   // Check for overflow
	   if(cksum->bit_column_cksum[bitcolumn][0] >= (unsigned long)0x0000FFFF)
	   {
		   cksum->bit_column_cksum[bitcolumn][1] += cksum->bit_column_cksum[bitcolumn][0] >> 16;
		   cksum->bit_column_cksum[bitcolumn][0] &= (unsigned long)0x0000FFFF;
	   }
   
	   if(cksum->bit_column_cksum[bitcolumn][1] >= (unsigned long)0x0000FFFF)
	   {
		   cksum->bit_column_cksum[bitcolumn][2] += cksum->bit_column_cksum[bitcolumn][1] >> 16;
		   cksum->bit_column_cksum[bitcolumn][1] &= (unsigned long)0x0000FFFF;
	   }

	   // Add in MSW
	   cksum->bit_column_cksum[bitcolumn][1] += (bit_weight >> 16);
	   // Check for overflow
	   if(cksum->bit_column_cksum[bitcolumn][1] >= (unsigned long)0x0000FFFF)
	   {
		   cksum->bit_column_cksum[bitcolumn][2] += cksum->bit_column_cksum[bitcolumn][1] >> 16;
		   cksum->bit_column_cksum[bitcolumn][1] &= (unsigned long)0x0000FFFF;
	   }

	  return (unsigned long)(8*(bit_weight-1) + bitcolumn);
}

unsigned long calculate_checksum(unsigned long start, unsigned long end, unsigned long offset, composite_checksum_t *cksum)
{
	volatile unsigned short data = 0x0000;
	volatile unsigned short byte_value = 0;
	volatile unsigned short byte_count = 0;
	volatile unsigned long byte_offset = 0;
	volatile unsigned long ones_weight = 0;
	volatile unsigned long ones_fact_weight = 0; 
	volatile unsigned long nibble_count = 0;
	volatile unsigned int nibble_offset = 0;

	while(start <= end)
	{
		if(start & ~(0x3FFFFF))	//address beyond 22 bits
		{
				data = __addr32_read_uint16(start++);
		}
		else
		{
			data = *(volatile unsigned short *)start++;	//pointer to a 16 bit value
		}
		//each offset has 2 bytes of data on C28x CPUs
		for(byte_count = 1; byte_count < 3; byte_count++)
		{
			byte_offset = byte_count+(offset);
			ones_fact_weight = 1;
			//get the byte from word
			byte_value = (data & (0xFF));
			data = (data >> 8);
			ones_weight = 0;			
			//seperate the byte into two nibbles
			for(nibble_offset = 0;  nibble_offset <= 4; nibble_offset+=4)
			{
				nibble_count++;
				if((byte_value & 0xF) == 0)
				{
					;
				}
				else if ((byte_value & 0xF) == 1)
				{
					cksum->total_ones += 1;
				    ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
			    	ones_fact_weight = (nibble_count -1)*(nibble_count + 1);
				}
				else if ((byte_value & 0xF) == 2)
				{
					cksum->total_ones += 1;
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_fact_weight = (nibble_count -1)*(nibble_count + 2) ;
				}
				else if ((byte_value & 0xF) == 3)
				{
					cksum->total_ones += 2;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 2);
				}
				else if ((byte_value & 0xF) == 4)
				{
					cksum->total_ones += 1;
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);

					ones_fact_weight = (nibble_count -1)*(nibble_count + 3);

				}
				else if ((byte_value & 0xF) == 5)
				{
					cksum->total_ones += 2;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 3);
				}
				else if ((byte_value & 0xF) == 6)
				{
					cksum->total_ones += 2;
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 2);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 3);
				}
				else if ((byte_value & 0xF) == 7)
				{
					cksum->total_ones += 3;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 2);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 3);
				}
				else if ((byte_value & 0xF) == 8)
				{
					cksum->total_ones += 1;
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = (nibble_count -1)*(nibble_count + 4);

				}
				else if ((byte_value & 0xF) == 9)
				{
					cksum->total_ones += 2;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				}

				else if ((byte_value & 0xF) == 10)
				{
					cksum->total_ones += 2;
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 2);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				}
				else if ((byte_value & 0xF) == 11)
				{
					cksum->total_ones += 3;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 2);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				}
				else if ((byte_value & 0xF) == 12)
				{
					cksum->total_ones += 2;
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 3);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				}
				else if ((byte_value & 0xF) == 13)
				{
					cksum->total_ones += 3;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 3);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				}
				else if ((byte_value & 0xF) == 14)
				{
					cksum->total_ones += 3;
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 2);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 3);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				    	 
				}
				else if ((byte_value & 0xF) == 15)
				{
					cksum->total_ones += 4;
					ones_weight += add_to_bitcolumn_checksum(0+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(1+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(2+nibble_offset,byte_offset, cksum);
					ones_weight += add_to_bitcolumn_checksum(3+nibble_offset,byte_offset, cksum);

					ones_fact_weight = ones_fact_weight *(nibble_count + 1);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 2);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 3);
					ones_fact_weight = ones_fact_weight *(nibble_count%2 + 4);
				    	 
				}
				add_to_factorial_sum(ones_fact_weight, cksum);
				ones_fact_weight = 1;
				//get the next nibble from byte
				byte_value = byte_value >> 4;
			}//for loop on nibble.
			add_to_row_weight_sum(ones_weight, cksum);
	    } // for loop on bytes in word.
			offset++;
	}//while		
	return offset;
}

unsigned short compare_two_composite_checksums(const composite_checksum_t *goldsum, composite_checksum_t *compsum)
{

	if((goldsum == (void *)0) || (compsum == (void *)0))
		return 0xFFFF;

	if(goldsum->total_ones != compsum->total_ones )
		return 0xFFFE;

	if((goldsum->fact_weight_sum.highHalfMSW != compsum->fact_weight_sum.highHalfMSW )
			|| (goldsum->fact_weight_sum.highHalfLSW != compsum->fact_weight_sum.highHalfLSW )
			|| (goldsum->fact_weight_sum.lowHalfMSW != compsum->fact_weight_sum.lowHalfMSW )
			|| (goldsum->fact_weight_sum.lowHalfLSW != compsum->fact_weight_sum.lowHalfLSW ))
	{
		return 0xFFFD;
	}

	if((goldsum->row_weight_sum.highHalfMSW != compsum->row_weight_sum.highHalfMSW )
			|| (goldsum->row_weight_sum.highHalfLSW != compsum->row_weight_sum.highHalfLSW)
			|| (goldsum->row_weight_sum.lowHalfMSW != compsum->row_weight_sum.lowHalfMSW)
			|| (goldsum->row_weight_sum.lowHalfLSW != compsum->row_weight_sum.lowHalfLSW))
	{
		return 0xFFFC;
	}

	if((goldsum->bit_column_cksum[7][2] != compsum->bit_column_cksum[7][2])
			|| (goldsum->bit_column_cksum[7][1] != compsum->bit_column_cksum[7][1])
			|| (goldsum->bit_column_cksum[7][0] != compsum->bit_column_cksum[7][0]))
	{
		return 0xFFFB;
	}

	if((goldsum->bit_column_cksum[6][2] != compsum->bit_column_cksum[6][2])
			|| (goldsum->bit_column_cksum[6][1] != compsum->bit_column_cksum[6][1])
			|| (goldsum->bit_column_cksum[6][0] != compsum->bit_column_cksum[6][0]))
	{
		return 0xFFFA;
	}

	if((goldsum->bit_column_cksum[5][2] != compsum->bit_column_cksum[5][2])
			|| (goldsum->bit_column_cksum[5][1] != compsum->bit_column_cksum[5][1])
			|| (goldsum->bit_column_cksum[5][0] != compsum->bit_column_cksum[5][0]))
	{
		return 0xFFF9;
	}

	if((goldsum->bit_column_cksum[4][2] != compsum->bit_column_cksum[4][2])
			|| (goldsum->bit_column_cksum[4][1] != compsum->bit_column_cksum[4][1])
			|| (goldsum->bit_column_cksum[4][0] != compsum->bit_column_cksum[4][0]))
	{
		return 0xFFF8;
	}

	if((goldsum->bit_column_cksum[3][2] != compsum->bit_column_cksum[3][2])
			|| (goldsum->bit_column_cksum[3][1] != compsum->bit_column_cksum[3][1])
			|| (goldsum->bit_column_cksum[3][0] != compsum->bit_column_cksum[3][0]))
	{
		return 0xFFF7;
	}

	if((goldsum->bit_column_cksum[2][2] != compsum->bit_column_cksum[2][2])
			|| (goldsum->bit_column_cksum[2][1] != compsum->bit_column_cksum[2][1])
			|| (goldsum->bit_column_cksum[2][0] != compsum->bit_column_cksum[2][0]))
	{
		return 0xFFF6;
	}

	if((goldsum->bit_column_cksum[1][2] != compsum->bit_column_cksum[1][2])
			|| (goldsum->bit_column_cksum[1][1] != compsum->bit_column_cksum[1][1])
			|| (goldsum->bit_column_cksum[1][0] != compsum->bit_column_cksum[1][0]))
	{
		return 0xFFF5;
	}

	if((goldsum->bit_column_cksum[0][2] != compsum->bit_column_cksum[0][2])
			|| (goldsum->bit_column_cksum[0][1] != compsum->bit_column_cksum[0][1])
			|| (goldsum->bit_column_cksum[0][0] != compsum->bit_column_cksum[0][0]))
	{
		return 0xFFF4;
	}

	return 0;
}

unsigned short verify_pbist_checksum_onROM()
{
	composite_checksum_t rom_cksum;
	memblock mblock_rom[6];


	SysCtl_disableWatchdog();

	//skipping 3E8000 to 3F7200 (reserved)

	mblock_rom[0].firstAddr = 0x003F7200;
	mblock_rom[0].lastAddr =  0x003FC899;
	mblock_rom[0].mem_attribute = 1;	//data is present

	mblock_rom[1].firstAddr = 0x003fC89A;
	mblock_rom[1].lastAddr =  0X003fE9CF;
	mblock_rom[1].mem_attribute = 0;	//data is NOT present

	//skipping :- 3FE9D0 to 3FEB22 (not used or (reserved))

	mblock_rom[2].firstAddr = 0x003feb22;  //flash api - future
	mblock_rom[2].lastAddr =  0x003fff21;
	mblock_rom[2].mem_attribute = 0;	//data is NOT present

	mblock_rom[3].firstAddr = 0x003fff22;
	mblock_rom[3].lastAddr =  0x003fff7b;
	mblock_rom[3].mem_attribute = 1;	//data is present

	mblock_rom[4].firstAddr = 0x003fffbe;
	mblock_rom[4].lastAddr =  0x003fffff;
	mblock_rom[4].mem_attribute = 1;	//data is present


	mblock_rom[5].firstAddr = 0x003fffbe;
	mblock_rom[5].lastAddr =  0x003fffff;
	mblock_rom[5].mem_attribute = 1;	//data is present

	if ( 0xFFFF == calculate_composite_checksum_on_rom(&rom_cksum, &mblock_rom[0], 6))
		return 0xFFF2;

	return compare_two_composite_checksums(&pbist_csum_rom, &rom_cksum);
}


// EOF --------
#endif //no stable compiler available

//###########################################################################
//
// FILE:    cla_data_rom_lnk.cmd
//
// TITLE:   CLA data rom linker command file
//
//###########################################################################
// $TI Release:  $ 
// $Release Date:  $ 
//###########################################################################

--retain '(.CLA1fftTables)'
--retain '(CLA1mathTables)'
--retain '(.CROMVersion)'

MEMORY
{

   CLA1_DATAROM_RESERVED	: origin = 0x01001000, length = 0x000070 //, fill = 0xFFFF
   CLA1_FFT_TABLES			: origin = 0x01001070, length = 0x000800  //, fill = 0xFFFF
   CLA1_DATAROM         	: origin = 0x01001870, length = 0x00078a //, fill = 0xFFFF
   CROM_VERSION    			: origin = 0x01001FFA, length = 0x000006 //, fill = 0xFFFF

   CLA1_DATAROM_RESERVED_RUN	: origin = 0x0000F000, length = 0x000070
   CLA1_FFT_TABLES_RUN			: origin = 0x0000F070, length = 0x000800
   CLA1_DATAROM_RUN         	: origin = 0x0000F870, length = 0x00078a
   CROM_VERSION_RUN    			: origin = 0x0000FFFA, length = 0x000006

   
/*   CLA1_DATAROM         : origin = 0x01001000, length = 0x001000*/
}


SECTIONS
{
	.CLA1fftTables		: load = CLA1_FFT_TABLES, ALIGN(2) //, run = CLA1_FFT_TABLES_RUN , ALIGN(2)
	CLA1mathTables		: load = CLA1_DATAROM//, run = CLA1_DATAROM_RUN
	.CROMVersion    	: load = CROM_VERSION//, run = CROM_VERSION_RUN

}

/*
//===========================================================================
// End of file.
//===========================================================================
*/

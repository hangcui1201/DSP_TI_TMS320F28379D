//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Sorts a real array
//! \author David M. Alter (original), Vishal Coelho (adaptated version here)
//! \date   30-Sep-2015 (original code written 07/01/11)
//! 
//
//  Group:            C2000
//  Target Family:    $DEVICE$
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################


//*****************************************************************************
// the includes
//*****************************************************************************
#include "vector.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(18)

//*****************************************************************************
// prototypes
//*****************************************************************************
static inline void swap_item(fsize_t *, fsize_t *);

//*****************************************************************************
// VECTOR_qsortRV
//*****************************************************************************
void VECTOR_qsortRV(void *base, const uint16_t nmemb)
{
    char   *basep  = base;              // POINTER TO ARRAY OF ELEMENTS 
    uint16_t  i    = 0;                 // left scan index
    // right scan index
    uint16_t  j    = sizeof(fsize_t)*(nmemb - 1);
    // Want closest even value
    uint16_t pivot = (nmemb & 0xFFFE)*(sizeof(fsize_t) / 2);    
    char   *pivp   = basep + pivot ;
   
    if (nmemb <= 1) return;

    while( i < j )
    {
        while(*(fsize_t*)(basep + i) < *(fsize_t*)pivp) 
        {
            i=i+sizeof(fsize_t);
        }
        while(*(fsize_t*)(basep + j) > *(fsize_t*)pivp)
        {
            j=j-sizeof(fsize_t);
        }

        if( i < j )
        {
            swap_item((fsize_t*)(basep + i), (fsize_t*)(basep + j));
            if ( pivot == i ) 
            {
                pivot = j; 
                pivp = basep + pivot; 
            }
            else if( pivot == j ) 
            {
                pivot = i; 
                pivp = basep + pivot; 
            }
            i=i+sizeof(fsize_t); 
            j=j-sizeof(fsize_t);
        }
        else if ( i == j ) 
        {
            i=i+sizeof(fsize_t); 
            j=j-sizeof(fsize_t);  
            break; 
        }
    }

    if(j > 0) 
    {
        VECTOR_qsortRV(basep, (j/sizeof(fsize_t) + 1U)); 
    }
    if((i/sizeof(fsize_t)) < (nmemb - 1))
    {
        VECTOR_qsortRV(basep + i, nmemb - (i/sizeof(fsize_t)));
    }

}

//*****************************************************************************
// swap_item
//*****************************************************************************
static inline void swap_item(fsize_t *src, fsize_t *dest)
{
    fsize_t temp;

    temp = *src;
    *src  = *dest;
    *dest = temp;

}

// End of File

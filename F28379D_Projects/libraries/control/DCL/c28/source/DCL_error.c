/* DCL_error.c */

#include "DCL.h"

void DCL_runErrorHandler(DCL_CSS *p)
{
    if (ERR_NONE != p->err)
    {
#ifdef __TMS320C28XX__
        asm(" ESTOP0");
#else
        while(1);
#endif
    }
}

/* end of file */

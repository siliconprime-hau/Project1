#include <stdlib.h>
#include <stdio.h>
#include "esUtil.h"

void esLogMessage ( const char *formatStr, ... )
{
#ifdef __WINDOW__
    va_list params;
    char buf[BUFSIZ];

    va_start ( params, formatStr );
    vsprintf_s ( buf, sizeof(buf),  formatStr, params );
    
    printf ( "%s", buf );
    
    va_end ( params );
#endif
}

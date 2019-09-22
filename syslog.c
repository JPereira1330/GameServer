//
// Created by nyex on 21/09/2019.
//

#include <stdio.h>
#include <stdarg.h>
#include "syslog.h"

void print_log_i(const char *filename, int line, const char *format, ...){

    if(DEBUG){
        char buffer[1024];
        va_list v1;
        va_start(v1, format);

        vsnprintf(buffer, sizeof(buffer), format, v1);
        printf("%s --> %s : %d \n", buffer, filename, line);
        va_end(v1);
    }

}
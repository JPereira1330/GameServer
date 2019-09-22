//
// Created by nyex on 21/09/2019.
//

#ifndef SERVER_GAME_SYSLOG_H
#define SERVER_GAME_SYSLOG_H

#include <stdio.h>

#ifndef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

#define print_log(D_FORMAT, ...) print_log_i(__FILE__, __LINE__, D_FORMAT, #__VA_ARGS__)

void print_log_i(const char *filename, int line, const char *format, ...);

#endif //SERVER_GAME_SYSLOG_H

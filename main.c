#include <stdio.h>

#include "SocketServer.h"
#include "syslog.h"

#define PORT 3666

int main() {

    print_log("Iniciando servidor");
    serverStart(PORT);

    return 0;
}
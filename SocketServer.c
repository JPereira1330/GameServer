//
// Created by nyex on 21/09/2019.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "syslog.h"
#include "SocketServer.h"

#define SOCK_SUCESSO 1
#define SOCK_ERROR -1

int serverStart(int port){

    // Variaveis do sistema
    int ret;
    char buffer[1024];
    int server_fd, cli_handle;
    struct sockaddr_in addr;

    // Endereço de conexao
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    // Criando socket
    server_fd = gs_socket(AF_INET, SOCK_STREAM, 0);

    //
    ret = bind(server_fd, (struct sockaddr *) &addr, sizeof(addr));
    if(ret < 0){
        printf("Ocorreu um erro ao abrir socket");
        return -1;
    }

    // Escutando na porta
    ret = gs_listen(server_fd, 3);

    while(1) {
        // Zerando memoria
        memset(buffer, 0, sizeof(buffer));

        cli_handle = gs_accept(server_fd, (struct sockaddr *) &addr, (socklen_t *) &addr);
        print_log("Cliente: %d", cli_handle);

        while(1) {
            ret = recv(cli_handle, buffer, sizeof(buffer), 0);
            printf("%s\n", buffer);

            if(!ret){
                break;
            }

            send(cli_handle, buffer, strlen(buffer), 0);
            printf("Hello message sent\n");
        }
    }

    return 0;
}

int gs_socket(int domain, int type, int protocol){

    int handle;

    handle = socket(domain, type, protocol);
    if(handle < 0){
        print_log("Erro ao gerar handle[%d] ", handle);
        return -1;
    }
    print_log("Handle gerado: %d", handle);

    return  handle;
}

int gs_listen(int fd, int n){

    print_log("Listen Ativo");
    int ret = listen(fd, n);

    if(ret < 0){
        print_log("Ocorreu um erro ao escutar na porta");
        return -1;
    }

    return ret;
}

int gs_accept(int fd, struct sockaddr *addr, socklen_t *restrict addr_len){

    int cli;
    cli = accept(fd, (struct sockaddr *) &addr, (socklen_t *) &addr);

    if(cli < 0){
        print_log("Ocorreu um erro ao escutar na porta");
        return -1;
    }

    return cli;
}
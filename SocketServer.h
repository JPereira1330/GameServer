//
// Created by nyex on 21/09/2019.
//

#ifndef SERVER_GAME_SOCKETSERVER_H
#define SERVER_GAME_SOCKETSERVER_H

#include <sys/socket.h>
#include <netinet/in.h>

int serverStart(int port);

/**
 * @brief Funcao responsavel de criar o socket
 * @param domain
 * @param type
 * @param protocol
 * @return Handle gerado
 */
int gs_socket(int domain, int type, int protocol);

/**
 * @brief Escuta na porta
 * @param fd
 * @param n
 * @return
 */
int gs_listen(int fd, int n);

/**
 * @brief Aceitando conexao
 * @param fd
 * @param addr
 * @param addr_len
 * @return
 */
int gs_accept(int fd, struct sockaddr *addr, socklen_t *restrict addr_len);

#endif //SERVER_GAME_SOCKETSERVER_H

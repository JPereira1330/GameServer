cmake_minimum_required(VERSION 3.14)
project(server_game C)

set(CMAKE_C_STANDARD 99)

add_executable(server_game main.c SocketServer.c SocketServer.h syslog.c syslog.h)
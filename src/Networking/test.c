#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Server.h"

void launch(struct Server *server) {
    #define buffer_size 30000
    char buffer[buffer_size];
    while(1) {
        printf("===== WAITING FOR CONNECTION =====\n");
    
        int address_length = sizeof(server->address);
        int new_socket = accept(server->socket ,
                                (struct sockaddr *)&server->address,
                                (socklen_t *)&address_length);
        //test for connection success
        read(new_socket , buffer , buffer_size);
    
        printf("%s\n" , buffer);

        char *hello = "HTTP/1.1 200 OK\nDate: 28 Dec 2023\nServer: JHB c server\nContent-Length: 88\nContent-Type: text/html\nConnection: Closed\n<html><body><h1>Hello, World !</h1></body></html>";
    
        write(new_socket, hello , strlen(hello));
        close(new_socket);
    } 
}

int main() {

    struct Server server = server_constructor(AF_INET , SOCK_STREAM , 0 ,
                                              INADDR_ANY , 80 , 10, launch);
    server.launch(&server);
}

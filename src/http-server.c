#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "Networking/Server.h"

void launch(struct Server *server) {
    #define buffer_size 30000
    char buffer[buffer_size];

    char *http_content = "HTTP/1.1 200 OK\nServer: JHB_c_Server\nContent-Type: text/html\nConnection: Closed\n\n";
    
    char *html_content = "<html><body><h1>Hello , Die is Jan-Hendrik se HTTP Server !</h1></body></html>";
    
    int content_length = strlen(http_content) + strlen(html_content);
    char *content = (char*)malloc(content_length * sizeof(char));
    strcpy(content, http_content);
    strcat(content, html_content);

    printf("\n\n%s\n\n",content);

    int address_length = sizeof(server->address);
    int new_socket;

    while(1) {
        printf("===== WAITING FOR CONNECTION =====\n");
    
        new_socket = accept(server->socket ,
                                (struct sockaddr *)&server->address,
                                (socklen_t *)&address_length);

        if(new_socket > 0) {
            printf("===== CONNECTION SUCCESS =====\n");
        }
        //test for connection success
        read(new_socket , buffer , buffer_size);
    
        //printf("%s" , buffer);

        write(new_socket, content , strlen(content));
        close(new_socket);
    }
    free(content);
}

int main() {

    struct Server server = server_constructor(AF_INET , SOCK_STREAM , 0 ,
                                              INADDR_ANY , 80 , 10, launch);
    server.launch(&server);
}

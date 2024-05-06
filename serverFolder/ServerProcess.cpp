//
// Created by sanvm on 12/31/22.
//

#include "ServerProcess.h"

void handle_client(int client_sock, int server_port) {

    ClientData cd(client_sock, server_port);
    SocketIO SIO(client_sock);
    CLI cli(cd, &SIO);
    cli.clientServer();
}

//runs the server infinitely
void ServerProcess::runProcess(int server_port) {
    //creates a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //binds socket with sockaddr_in
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    //the programs stops till it receives input
    if (listen(sock, 40) < 0) {
        perror("error listening to a socket");
    }
    //if we got here it means that we successfully connected the sockets.


    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        thread client_thread(handle_client,client_sock, server_port);
        client_thread.detach();
    }
    close(sock);

}



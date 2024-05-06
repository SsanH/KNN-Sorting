
#ifndef SAN_YNON_EX2NEW_CLIENTPROCESS_H
#define SAN_YNON_EX2NEW_CLIENTPROCESS_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void connectToServer(int sock, const char* ipAdress, int portNo);
void sendMessage(int sock, const char* message);
string receiveMessage(int sock);


#endif //SAN_YNON_EX2NEW_CLIENTPROCESS_H

//
// Created by ynon on 19/01/23.
//

#include "SocketIO.h"

SocketIO::SocketIO(int socket) {
    this->socket = socket;
}

string SocketIO::read() {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->socket, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        cout << "connection is closed" << endl;

    } else if (read_bytes < 0) {
        perror("error receiving message");
    } else {
        string str(buffer);
        return str;
    }
    return "";
}

void SocketIO::write(string input) {
    int data_len = strlen(input.data());
    int sent_bytes = send(this->socket, input.data(), data_len, 0);
    if (sent_bytes < 0) {
        perror("error sending message");
    }
}
#include "clientProcess.h"

using namespace std;

/**
 * gets a socket, an ip address and a port and connects the socket to the server.
 * @param sock
 * @param ipAdress
 * @param portNo
 */
void connectToServer(int sock, const char* ipAdress, int portNo) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ipAdress);
    sin.sin_port = htons(portNo);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

/**
 * gets a socket and a char* and sends a message to the server
 * @param sock
 * @param message
 */
void sendMessage(int sock, const char* message) {
    int data_len = strlen(message);
    int sent_bytes = send(sock, message, data_len, 0);
    if (sent_bytes < 0) {
        perror("error sending message");
    }
}

/**
 * gets a socket and returns a message from the server
 * @param sock
 * @return
 */
string receiveMessage(int sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
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

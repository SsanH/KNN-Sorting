//
// Created by ynon on 19/01/23.
//

#ifndef SAN_YNON_EX2NEW_SOCKETIO_H
#define SAN_YNON_EX2NEW_SOCKETIO_H

#include "DefaultIO.h"
#include <sys/socket.h>
#include <string.h>
#include <iostream>

class SocketIO: public DefaultIO{
private:
    int socket;

public:
    SocketIO(int socket);
    string read();
    void write(string input);
};


#endif //SAN_YNON_EX2NEW_SOCKETIO_H

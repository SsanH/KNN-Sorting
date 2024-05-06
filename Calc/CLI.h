//
// Created by sanvm on 1/19/23.
//

#ifndef SAN_YNON_EX2NEW_CLI_H
#define SAN_YNON_EX2NEW_CLI_H

#include "ClientData.h"
#include "../Commands/Command.h"
#include "../Commands/ServerCommands/ReturnAnswerCommand.h"
#include "../Commands/ServerCommands/RunKNNCommand.h"
#include "../Commands/ServerCommands/ServerDownloadCommand.h"
#include "../Commands/ServerCommands/ServerUploadCommand.h"
#include "../Commands/ServerCommands/SettingsCommand.h"
#include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

using namespace std;


class CLI {
private:
    ClientData cd;
    Command *c[6];
    DefaultIO *dio;
public:

    CLI(ClientData cd1, DefaultIO *dio);

    void printMenu();

    void chooseCommand(int commandNum);

    void clientServer();

    ~CLI();

};

#endif //SAN_YNON_EX2NEW_CLI_H

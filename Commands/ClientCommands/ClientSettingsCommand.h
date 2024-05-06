//
// Created by ynon on 23/01/23.
//

#ifndef SAN_YNON_EX2NEW_CLIENTSETTINGSCOMMAND_H
#define SAN_YNON_EX2NEW_CLIENTSETTINGSCOMMAND_H

#include "../Command.h"
#include "iostream"

class ClientSettingsCommand: public Command {
public:
    ClientSettingsCommand(string description, DefaultIO *dio);
    void execute();
};


#endif //SAN_YNON_EX2NEW_CLIENTSETTINGSCOMMAND_H

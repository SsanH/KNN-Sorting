//
// Created by ynon on 19/01/23.
//

#ifndef SAN_YNON_EX2NEW_COMMAND_H
#define SAN_YNON_EX2NEW_COMMAND_H

#include "../inputOutput/DefaultIO.h"

class Command {
protected:
    string description;
    DefaultIO* dio;

public:
    Command(string description, DefaultIO* dio);
    virtual void execute() = 0;
    string getDescription();
};


#endif //SAN_YNON_EX2NEW_COMMAND_H

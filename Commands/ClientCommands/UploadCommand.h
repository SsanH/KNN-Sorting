//
// Created by ynon on 20/01/23.
//

#ifndef SAN_YNON_EX2NEW_UPLOADCOMMAND_H
#define SAN_YNON_EX2NEW_UPLOADCOMMAND_H

#include "../Command.h"
#include "iostream"
#include <fstream>

class UploadCommand: public Command{

public:
    UploadCommand(string description, DefaultIO *dio);
    void execute();

};


#endif //SAN_YNON_EX2NEW_UPLOADCOMMAND_H

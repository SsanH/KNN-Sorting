//
// Created by shonh on 21/01/2023.
//

#ifndef SAN_YNON_EX2NEW_RETURNANSWERCOMMAND_H
#define SAN_YNON_EX2NEW_RETURNANSWERCOMMAND_H


#include "../Command.h"
#include "../../Calc/ClientData.h"
#include "../../inputOutput/DataManager.h"

using namespace std;

class ReturnAnswerCommand: public Command {
private:
    ClientData *clientData;
    DataManager dm;
public:
    ReturnAnswerCommand(ClientData *cd, string description1, DefaultIO *dio1);

    void execute();
};


#endif //SAN_YNON_EX2NEW_RETURNANSWERCOMMAND_H

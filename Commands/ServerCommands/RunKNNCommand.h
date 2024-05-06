//
// Created by san on 21/01/2023.
//

#ifndef SAN_YNON_EX2NEW_RUNKNNCOMMAND_H
#define SAN_YNON_EX2NEW_RUNKNNCOMMAND_H


#include "../../Calc/ClientData.h"
#include "../Command.h"
#include "../../inputOutput/DataManager.h"
#include "../../Calc/KNN.h"

using namespace std;

class RunKNNCommand:public Command {
private:
    ClientData *clientData;
    DataManager dm;
public:
    RunKNNCommand(ClientData *cd,string description, DefaultIO *dio);

    void execute();
};


#endif //SAN_YNON_EX2NEW_RUNKNNCOMMAND_H

//
// Created by sanvm on 1/20/23.
//

#ifndef SAN_YNON_EX2NEW_SETTINGSCOMMAND_H
#define SAN_YNON_EX2NEW_SETTINGSCOMMAND_H

#include "../Command.h"
#include "../../Calc/ClientData.h"
#include "../../inputOutput/DataManager.h"
#include <map>
#include <string>


using namespace std;

class SettingsCommand : public Command {
private:
    ClientData *clientData;
    DataManager dm;
public:

    SettingsCommand(ClientData *cd, string description, DefaultIO *dio);

    void execute();


};


#endif //SAN_YNON_EX2NEW_SETTINGSCOMMAND_H

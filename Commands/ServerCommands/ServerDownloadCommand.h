//
// Created by shonh on 21/01/2023.
//

#ifndef SAN_YNON_EX2NEW_SERVERDOWNLOADCOMMAND_H
#define SAN_YNON_EX2NEW_SERVERDOWNLOADCOMMAND_H

#include "../Command.h"
#include "../../Calc/ClientData.h"
#include "../../inputOutput/DataManager.h"

class ServerDownloadCommand : public Command{
private:
    ClientData* cd;
    DataManager dm;

public:
    ServerDownloadCommand(ClientData *cd1, string description, DefaultIO *dio);
    void execute() override;

};


#endif //SAN_YNON_EX2NEW_SERVERDOWNLOADCOMMAND_H

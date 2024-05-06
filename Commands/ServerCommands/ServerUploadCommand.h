//
// Created by sanvm on 1/21/23.
//

#ifndef SAN_YNON_EX2NEW_SERVERUPLOADCOMMAND_H
#define SAN_YNON_EX2NEW_SERVERUPLOADCOMMAND_H


#include "../Command.h"
#include "../../Calc/ClientData.h"
#include "../../inputOutput/DataManager.h"

class ServerUploadCommand : public Command {
private:
    ClientData* cd;
    DataManager dm;

public:
    ServerUploadCommand(ClientData *cd1, string description, DefaultIO *dio);
    void execute() override;

};


#endif //SAN_YNON_EX2NEW_SERVERUPLOADCOMMAND_H

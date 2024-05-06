//
// Created by ynon on 19/01/23.
//

#ifndef SAN_YNON_EX2NEW_DOWNLOADCOMMAND_H
#define SAN_YNON_EX2NEW_DOWNLOADCOMMAND_H

#include "fstream"
#include <vector>
#include "../../inputOutput/DataPoint.h"
#include "../../inputOutput/DataManager.h"
#include "../Command.h"
#include <thread>

class DownloadCommand: public Command {
private:
    string path;
    DataManager dm;

public:
    DownloadCommand(string description, DefaultIO *dio, string path);
    void execute();
    string getPath();
    void setPath(string path);
};


#endif //SAN_YNON_EX2NEW_DOWNLOADCOMMAND_H

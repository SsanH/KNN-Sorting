//
// Created by sanvm on 1/21/23.
//

#include "ServerUploadCommand.h"

using namespace std;

ServerUploadCommand::ServerUploadCommand(ClientData *cd1, string description, DefaultIO *dio) : Command(description, dio) {
    this->cd = cd1;
}

//server upload command takes path and uploads the vectors to the client's vector, it clears the vector before use.
void ServerUploadCommand::execute() {



    dio->write("Please upload your local train CSV file.");
    
    if (dio->read() == "nofile") {
      return;
    }

    cd->clearVecs();
    while (true){
        string ans = dio->read();
        dio->write("linebreak");
        if (ans == "done") {
            dio->write("Upload complete.\n");
            break;
        }
        DataPoint dp = dm.getDataPoint(ans, ",");;
        cd->addVectorClassified(dp);
    }

    dio->write("Please upload your local test CSV file.");
    
    if (dio->read() == "nofile") {
      return;
    }

    while (true){
        string ans = dio->read();
        dio->write("linebreak");
        if (ans == "done"){
            break;
        }
        DataPoint dp = dm.getDataPoint(ans, ",");
        vector<double> v = dp.getProperties();
        cd->addVectorUnclassified(v);
    }
}

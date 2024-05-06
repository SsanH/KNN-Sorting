//
// Created by shonh on 21/01/2023.
//

#include "ServerDownloadCommand.h"


ServerDownloadCommand::ServerDownloadCommand(ClientData *cd1, string description, DefaultIO *dio) : Command(description,
                                                                                                            dio) {
    this->cd = cd1;
}

//this writes the classified vectors
void ServerDownloadCommand::execute() {

    std::vector<DataPoint> ansVec = this->cd->getAnswerVector();
    int loop = this->cd->getAnswerSize();
    int classifiedSize = this->cd->getDataSize();
    int unclassifiedSize = this->cd->getDataSizeUnclassified();

    if (classifiedSize == 0 || unclassifiedSize == 0) {
        dio->write("1");
        string clean = dio->read();
        string answer = "please upload data";
        dio->write(answer);
        return;
    }

    if (loop == 0){
        dio->write("1");
        string clean = dio->read();
        string answer = "please classify the data";
        dio->write(answer);
        return;
    }

    dio->write("0");
    string clean1 = dio->read();

    for (int i = 0; i < loop; ++i) {
        string answer = to_string(i + 1) + "\t" + ansVec[i].getTag();
        dio->write(answer);
        string clean = dio->read();
    }

    string answer = "end";
    dio->write(answer);
}
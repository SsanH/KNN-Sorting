//
// Created by shonh on 21/01/2023.
//

#include "ReturnAnswerCommand.h"

using namespace std;

ReturnAnswerCommand::ReturnAnswerCommand(ClientData *cd, string description1, DefaultIO *dio1) : Command(description1,
                                                                                                         dio1) {
    this->clientData = cd;
}
/*
 * checks for correctness and returns the answer from sortedvec in client data
 */
void ReturnAnswerCommand::execute() {

    std::vector<DataPoint> ansVec = this->clientData->getAnswerVector();
    int loop = this->clientData->getAnswerSize();
    int classifiedSize = this->clientData->getDataSize();
    int unclassifiedSize = this->clientData->getDataSizeUnclassified();

    if (classifiedSize == 0 || unclassifiedSize == 0) {
        string answer = "please upload data\n";
        dio->write(answer);
        return;
    }

    if (loop == 0){
        string answer = "please classify the data\n";
        dio->write(answer);
        return;
    }

    for (int i = 0; i < loop; ++i) {
        string answer = to_string(i + 1) + "\t" + ansVec[i].getTag();
        dio->write(answer);
        string clean = dio->read();
    }
    dio->write("Done.");
    dio->write("end");
    string clean1 = dio->read();
    dio->write("");
    string clean2 = dio->read();
    dio->write("");
}

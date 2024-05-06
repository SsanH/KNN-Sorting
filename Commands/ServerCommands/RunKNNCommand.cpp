//
// Created by shonh on 21/01/2023.
//

#include "RunKNNCommand.h"

using namespace std;

RunKNNCommand::RunKNNCommand(ClientData *cd, string description, DefaultIO *dio) : Command(description, dio) {
    this->clientData = cd;
}

//this commands sorts the vector in data client
void RunKNNCommand::execute() {
    if (clientData->getDataSize() == 0 || clientData->getDataSizeUnclassified() == 0) {
        dio->write("please upload data\n");
        return;
    }

    std::map<const string, Metric *> m1;

    EuclideanDis AUC;
    CanberraDis CAN;
    ChebyshevDis CHB;
    TaxiCabDis MAN;
    MinkowskiDis MIN;

    m1.emplace(AUC.getName(), &AUC);
    m1.emplace(CAN.getName(), &CAN);
    m1.emplace(CHB.getName(), &CHB);
    m1.emplace(MAN.getName(), &MAN);
    m1.emplace(MIN.getName(), &MIN);

    vector<DataPoint> classifiedVec = clientData->getClassifiedVector();
    vector<vector<double>> unClassifiedVec = clientData->getUnClassifiedVector();
    int k = clientData->getK();
    string metric = clientData->getMetric();
    vector<DataPoint> answerVector;
    int loop = clientData->getDataSizeUnclassified();
    
    clientData->clearAnswer();

    for (int i = 0; i < loop; ++i) {
        KNN knn(m1[metric], unClassifiedVec[i], classifiedVec);
        DataPoint vdp = knn.getClassifiedVec(k);
        clientData->addAnswerVector(vdp);
    }

    string answer = "classifying data complete";
    dio->write(answer);
    string clean = dio->read();

}

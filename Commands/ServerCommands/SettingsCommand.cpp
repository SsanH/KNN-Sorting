//
// Created by sanvm on 1/20/23.
//

#include "SettingsCommand.h"

using namespace std;

SettingsCommand::SettingsCommand(ClientData *cd1, string description, DefaultIO *dio) : Command(description, dio) {
    this->clientData = cd1;
}

//checks if the settings are correct and changes the metrics and k accordingly.
void SettingsCommand::execute() {
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

    bool e1, e2;
    e1 = false;
    e2 = false;

    string answer = "The current KNN parameters are: K = " + to_string(clientData->getK()) + ", distance metric = " +
                    clientData->getMetric();

    dio->write(answer);
    string clean = dio->read();
    string input = dio->read();
    vector <string> vec = dm.parseString(input, " ");
    if (input == "ret") {
        return;
    }
    if (vec.size() != 2) {
        dio->write("invalid input");
        return;
    } else {
        if (0 >= stoi(vec[0]) || stoi(vec[0]) > clientData->getDataSize()) {
            string error = "invalid value for K";
            dio->write(error);
            e1 = true;
        }
        if (m1.find(vec[1]) == m1.end()) {
            string error = "invalid value for metric\n";
            dio->write(error);
            e2 = true;
        }
        if (!e1 && !e2) {
            clientData->changeK(stoi(vec[0]));
            clientData->changeMetric(vec[1]);
        }
    }
}

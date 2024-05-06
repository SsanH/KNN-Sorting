//
// Created by sanvm on 1/19/23.
//

#ifndef SAN_YNON_EX2NEW_CLIENTDATA_H
#define SAN_YNON_EX2NEW_CLIENTDATA_H

#include <vector>
#include "../inputOutput/DataPoint.h"
#include "Metric.h"
#include "../Calc/Metrics/CanberraDis.h"
#include "../Calc/Metrics/ChebyshevDis.h"
#include "../Calc/Metrics/EuclideanDis.h"
#include "../Calc/Metrics/MinkowskiDis.h"
#include "../Calc/Metrics/TaxiCabDis.h"
#include "string.h"

class ClientData {

private:

    int serverPort;
    int sock;
    int k;
    std::vector<std::vector<double>> unClassifiedVec;
    std::vector<DataPoint> classifiedVec;
    string metric;
    std::vector<DataPoint> answerVector;

public:

    ClientData(int sock1, int serverPort1);

    void addVectorClassified(DataPoint v);

    void addVectorUnclassified(std::vector<double> v);

    void addAnswerVector(DataPoint v);

    void changeMetric(string m1);

    void changeK(int k1);

    int getK();

    void clearAnswer();
    
    string getMetric();

    std::vector<DataPoint> getAnswer();

    int getSocket();

    int getDataSize();

    int getDataSizeUnclassified();

    int getAnswerSize();

    vector<DataPoint> getAnswerVector();

    vector<DataPoint> getClassifiedVector();

    vector<vector<double>> getUnClassifiedVector();

    void clearVecs();
};


#endif //SAN_YNON_EX2NEW_CLIENTDATA_H

//
// Created by ynon on 08/12/22.
//

#ifndef SAN_YNON_EX2_DATAMANAGER_H
#define SAN_YNON_EX2_DATAMANAGER_H

#include <istream>
#include <vector>
#include <iostream>
#include "fstream"
#include "DataPoint.h"
#include "RequestDetails.h"

using namespace std;

class DataManager {

public:
    vector<string> parseString(string str, const string& delimiter);

    DataPoint getDataPoint(string input, const string& delimiter = " ");

    vector<double> getVector(istream &inStream, const string& delimiter = " ");

    vector<DataPoint> getDataPoints(istream &inStream, const string& delimiter = ",");

    bool isNum(string s);

    void writeLineCSV(ofstream& outFile, vector<string> output);

    void writeLine(ofstream& outFile, string output);

    RequestDetails getRequest(string data);

};

#endif //SAN_YNON_EX2_DATAMANAGER_H

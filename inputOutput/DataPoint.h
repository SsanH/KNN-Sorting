//
// Created by ynon on 08/12/22.
//

#ifndef SAN_YNON_EX2_DATAPOINT_H
#define SAN_YNON_EX2_DATAPOINT_H

#include <string>
#include <vector>

using namespace std;

class DataPoint {
private:
    string tag;
    vector<double> properties;

public:
    DataPoint(vector<double> properties, string tag);
    string getTag();
    vector<double> getProperties();
    vector<string> getPointText();
};


#endif //SAN_YNON_EX2_DATAPOINT_H

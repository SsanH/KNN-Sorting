//
// Created by ynon on 01/01/23.
//

#ifndef SAN_YNON_EX2NEW_REQUESTDETAILS_H
#define SAN_YNON_EX2NEW_REQUESTDETAILS_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class RequestDetails {
private:
    vector<double> vec;
    string dist;
    int k;
public:
    RequestDetails(vector<double> vec, string dist, int k);
    vector<double> getVec();
    string getDist();
    int getK();
    bool validateReq();
};


#endif //SAN_YNON_EX2NEW_REQUESTDETAILS_H

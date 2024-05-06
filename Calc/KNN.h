
// Created by san on 12/9/2022.


#ifndef NOO_PRO_KNN_H
#define NOO_PRO_KNN_H

#include "Metric.h"
#include "../inputOutput/DataPoint.h"
#include <map>
#include <iostream>
#include <algorithm>

class KNN {
private:
    std::vector<double> vec;
    std::vector<DataPoint> vec1;
    std::vector<std::vector <DataPoint>> sortedVec;

public:
    int q = 0;
    KNN(class Metric* m, std::vector<double> v1, std::vector<DataPoint> v);

    string countOccurrences(unsigned int k);

    static bool compare(std::vector<DataPoint> a, std::vector<DataPoint> b);

    DataPoint getClassifiedVec(int k1);
};


#endif //NOO_PRO_KNN_H

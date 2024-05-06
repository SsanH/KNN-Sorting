#ifndef MAIN_CPP_METRIC_H
#define MAIN_CPP_METRIC_H

#include <vector>
#include <string>
#include <cmath>
#include <iostream>


class Metric {
protected:
    std::string METRIC_NAME;
public:
    virtual const double distance(std::vector<double> v1, std::vector<double> v2, double p = 2) const = 0;

    std::string getName() const ;

    void checkInput(std::vector<double> v1, std::vector<double> v2) const;

};

#endif //MAIN_CPP_METRIC_H

//
// Created by san on 12/8/2022.
//

#ifndef MAIN_CPP_MINKOWSKIDIS_H
#define MAIN_CPP_MINKOWSKIDIS_H


#include "../Metric.h"

class MinkowskiDis : public Metric {
    public:
    const double distance(std::vector<double> v1, std::vector<double> v2, double p = 2) const override;
    MinkowskiDis();
};


#endif //MAIN_CPP_MINKOWSKIDIS_H

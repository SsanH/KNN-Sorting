//
// Created by san on 12/8/2022.
//

#ifndef MAIN_CPP_EUCLIDEANDIS_H
#define MAIN_CPP_EUCLIDEANDIS_H


#include "MinkowskiDis.h"

class EuclideanDis : public Metric {
    protected:
        MinkowskiDis minkDis;
    public:
        const double distance(std::vector<double> v1, std::vector<double> v2,double p) const override;
        EuclideanDis();

};


#endif //MAIN_CPP_EUCLIDEANDIS_H

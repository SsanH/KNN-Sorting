//
// Created by san on 12/8/2022.
//

#ifndef MAIN_CPP_TAXICABDIS_H
#define MAIN_CPP_TAXICABDIS_H


#include "MinkowskiDis.h"

class TaxiCabDis : public Metric{
    protected:
        MinkowskiDis minkDis;

    public:
        const double distance(std::vector<double> v1, std::vector<double> v2, double p) const override;
        TaxiCabDis();
};


#endif //MAIN_CPP_TAXICABDIS_H

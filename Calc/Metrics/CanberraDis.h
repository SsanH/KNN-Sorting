//
// Created by san on 12/8/2022.
//

#ifndef MAIN_CPP_CANBERRADIS_H
#define MAIN_CPP_CANBERRADIS_H


#include "../Metric.h"

class CanberraDis : public Metric {

    public:
      const double distance(std::vector<double> v1, std::vector<double> v2, double p) const override;
      CanberraDis();
};


#endif //MAIN_CPP_CANBERRADIS_H

//
// Created by san on 12/8/2022.
//

#include "TaxiCabDis.h"


/**
 * The function takes two vectors of doubles, v1 and v2, and a sends it to minkowski with p = 1
 * then returns the distance between v1 and v2
 * @param v1 the first vector
 * @param v2 the vector to compare to
 * @param p the p-norm to use
 * @return The distance between two vectors.
 */
const double TaxiCabDis::distance(std::vector<double> v1, std::vector<double> v2, double p) const {
    checkInput(v1, v2);
    return minkDis.distance(v1, v2, 1);
}

/**
 * The constructor for the TaxiCabDis class sets the name of the metric to "MAN".
 */
TaxiCabDis::TaxiCabDis() {
    this->METRIC_NAME = "MAN";
}

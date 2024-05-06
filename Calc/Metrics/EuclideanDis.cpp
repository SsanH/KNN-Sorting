//
// Created by san on 12/8/2022.
//

#include "EuclideanDis.h"


/**
 * It calculates the Euclidean distance between two vectors.
 * @param v1 the first vector
 * @param v2 the vector to be compared with
 * @param p the p-norm to be used in the Minkowski distance
 * @return The Euclidean distance between two vectors.
 */

const double EuclideanDis::distance(std::vector<double> v1, std::vector<double> v2, double p) const {
    checkInput(v1, v2);
    return minkDis.distance(v1, v2, 2);
}


/**
 * The EuclideanDis() function is a constructor that initializes the METRIC_NAME variable to "AUC".
 */
EuclideanDis::EuclideanDis() {
    this->METRIC_NAME = "AUC";
}


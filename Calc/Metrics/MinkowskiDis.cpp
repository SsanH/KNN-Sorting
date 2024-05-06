
#include "MinkowskiDis.h"

/**
 * The Minkowski distance is a generalization of the Euclidean distance and Manhattan distance
 * @param v1 The first vector
 * @param v2 The second vector to compare
 * @param p The p-value of the Minkowski distance.
 *
 * @return The distance between two vectors.
 */
const double MinkowskiDis::distance(std::vector<double> v1, std::vector<double> v2, double p) const {
    double distance = 0;
    checkInput(v1, v2);
    for (int i = 0; i < v1.size(); ++i) {
        distance += pow(std::abs(v1.at(i) - v2.at(i)), p);
    }
    return pow(distance, (1 / p));
}


/**
 * The constructor for the MinkowskiDis class sets the name of the metric to "MIN".
 */
MinkowskiDis::MinkowskiDis() {
    this->METRIC_NAME = "MIN";
}

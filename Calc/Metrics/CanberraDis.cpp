#include "CanberraDis.h"

/**
 * The function takes two vectors of the same size and returns the Canberra distance between them
 * @param v1 the first vector
 * @param v2 The second vector to compare.
 * @param p the power to which the p-norm is computed.
 * @return The distance between two vectors.
 */
const double CanberraDis::distance(std::vector<double> v1, std::vector<double> v2, double p) const {
    double diff = 0;
    double distance = 0;
    checkInput(v1, v2);
    for (int i = 0; i < v1.size(); ++i) {
        diff = (abs(v1[i] - v2[i]));
        if ((v1[i] == v2[i]) && (v1[i] == 0)) {
            distance += 0;
        } else {
            distance += diff / (abs(v1[i]) + abs(v2[i]));
        }
    }
    return distance;
}


/**
 * The CanberraDis class is a subclass of the Distance class. It has a constructor that sets the name of the distance
 * metric to CAN.
 */
CanberraDis::CanberraDis() {
    this->METRIC_NAME = "CAN";
}

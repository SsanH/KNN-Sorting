#include "ChebyshevDis.h"


/**
 * It takes two vectors of doubles and returns the maximum difference between the corresponding elements of the two vectors
 * @param v1 the first vector
 * @param v2 the vector to compare to
 * @param p the power of the Minkowski distance
 *
 * @return The maximum difference between the two vectors.
 */
const double ChebyshevDis::distance(std::vector<double> v1, std::vector<double> v2, double p) const {
    double max = 0;
    double diff = 0;
    checkInput(v1, v2);
    for (int i = 0; i < v1.size(); ++i) {
        diff = abs(v1[i] - v2[i]);
        if (diff - max > 0.0001)
            max = diff;
    }
    return max;
}

/**
 * The constructor for the ChebyshevDis class that sets name of the metric to CHE.
 */
ChebyshevDis::ChebyshevDis() {
    this->METRIC_NAME = "CHB";
}


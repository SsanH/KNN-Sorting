#include "Metric.h"

/**
 * `getName()` returns the name of the metric
 * @return The name of the metric.
 */
std::string Metric::getName() const {
    return METRIC_NAME;
}

/**
 * It checks if the length of the two vectors are equal
 * @param v1 the first vector
 * @param v2 the vector to be compared with
 */
void Metric::checkInput(std::vector<double> v1, std::vector<double> v2) const {
    if (v1.size() != v2.size()) {
        std::cout << "the length's of the vectors are not equals" << std::endl;
        exit(0);
    }
}

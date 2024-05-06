//
// Created by ynon on 01/01/23.
//

#include "RequestDetails.h"

/**
 * initializes a RequestDetails object. this class is used to store the components of a given request to
 * classify a vector, namely the vector itself, the distance metric to be used and the number of neighbours, k.
 * @param vec
 * @param dist
 * @param k
 */
RequestDetails::RequestDetails(vector<double> vec, string dist, int k) {
    this->vec = vec;
    this->dist = dist;
    this->k = k;
}

/**
 * checks if a request is valid according to the format given by instructions.
 * @return
 */
bool RequestDetails::validateReq() {
    if (vec.empty()) {
        return false;
    }
    if (dist.empty()) {
        return false;
    }
    if (k < 0) {
        return false;
    }
    return true;
}

/**
 * returns the vector.
 * @return
 */
vector<double> RequestDetails::getVec() {
    return this->vec;
}

/**
 * returns the distance.
 * @return
 */
string RequestDetails::getDist() {
    return this->dist;
}

/**
 * returns K.
 * @return
 */
int RequestDetails::getK() {
    return this->k;
}
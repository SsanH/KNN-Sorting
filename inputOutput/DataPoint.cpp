
#include "DataPoint.h"

DataPoint::DataPoint(vector<double> properties, std::string tag) {
    this->properties = properties;
    this->tag = tag;
}

/**
 * returns a vector<double> containing the DataPoints properties
 * @return properties
 */
vector<double> DataPoint::getProperties() {
    return properties;
}

/**
 * returns the DataPoints tag
 * @return tag
 */
string DataPoint::getTag() {
    return tag;
}

vector<string> DataPoint::getPointText() {
    vector<string> str;
    for (double x : this->properties) {
        str.push_back(to_string(x));
    }
    str.push_back(tag);
    return str;
}




#include "KNN.h"

/**
 * This function takes in a metric, a vector of doubles, and a vector of DataPoints. It then creates a vector of vectors of
 * DataPoints, where each vector of DataPoints contains a DataPoint with a single property, the distance between the vector
 * of doubles and the DataPoint. It then sorts the vector of vectors of DataPoints by the distance property
 * @param m the metric used to calculate the distance between two points
 * @param v1 the vector we want to classify
 * @param v the vector of properties of the data point we want to classify
 */

KNN::KNN(class Metric *m, std::vector<double> v1, std::vector<DataPoint> v) {

    this->vec = v1;
    this->vec1 = v;
    int size = vec1.size();

    for (int j = 0; j < size; j++) {
        vector<double> v;
        v.push_back(m->distance(vec, vec1[j].getProperties()));
        vector<DataPoint> newVector;
        newVector.push_back(DataPoint(v, vec1[j].getTag()));
        this->sortedVec.push_back(newVector);
    }
    sort(sortedVec.begin(), sortedVec.end(), compare);
}

/**
 * It takes two vectors of DataPoints, and returns true if the first element of the first vector is less than the first
 * element of the second vector, a generic comparison function used to sort the vector of vectors of DataPoints
 * @param a the first vector of DataPoints
 * @param b the vector of vectors of DataPoints that we want to sort
 * @return a boolean value.
 */

bool KNN::compare(std::vector<DataPoint> a, std::vector<DataPoint> b) {
    return a[0].getProperties()[0] < b[0].getProperties()[0];
}

/**
 * It counts the number of occurrences of each tag in the first k elements of the sorted vector, and returns the tag with
 * the most occurrences
 * @param k the number of neighbors to consider
 * @return The tag with the most occurrences.
 */

string KNN::countOccurrences(unsigned int k) {
    map<string, int> m1;
    for (int i = 0; i < k; ++i) {
        if (m1.count(KNN::sortedVec.at(i)[0].getTag())) {
            m1[KNN::sortedVec.at(i)[0].getTag()]++;
        } else {
            m1[KNN::sortedVec.at(i)[0].getTag()] = 1;
        }
    }
    int max = 0;
    string maxTag;
    map<string, int>::iterator it;
    for (it = m1.begin(); it != m1.end(); it++) {
        if (it->second > max) {
            max = it->second;
            maxTag = it->first;
        }
    }
    return maxTag;
}

DataPoint KNN::getClassifiedVec(int k1) {
    DataPoint dp = DataPoint(this->vec, countOccurrences(k1));
    return dp;
}

//
// Created by ynon on 19/01/23.
//

#ifndef SAN_YNON_EX2NEW_DEFAULTIO_H
#define SAN_YNON_EX2NEW_DEFAULTIO_H

#include <string>

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(string input) = 0;
};


#endif //SAN_YNON_EX2NEW_DEFAULTIO_H

//
// Created by ynon on 19/01/23.
//

#ifndef SAN_YNON_EX2NEW_STANDARDIO_H
#define SAN_YNON_EX2NEW_STANDARDIO_H


#include "DefaultIO.h"
#include <iostream>

class StandardIO: public DefaultIO {\
public:
    string read();
    void write(string input);
};


#endif //SAN_YNON_EX2NEW_STANDARDIO_H

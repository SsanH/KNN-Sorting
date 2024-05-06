//
// Created by ynon on 19/01/23.
//

#include "Command.h"

Command::Command(string description, DefaultIO* dio) {
    this->description = description;
    this->dio = dio;
}

string Command::getDescription() {
    return this->description;
}



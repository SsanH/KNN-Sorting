//
// Created by ynon on 19/01/23.
//

#include "StandardIO.h"

string StandardIO::read() {
    string str = "";
    getline(cin, str);
    return str;
}

void StandardIO::write(string input) {
    cout << input << endl;
}
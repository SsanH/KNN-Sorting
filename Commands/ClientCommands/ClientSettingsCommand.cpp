//
// Created by ynon on 23/01/23.
//

#include "ClientSettingsCommand.h"

ClientSettingsCommand::ClientSettingsCommand(string description, DefaultIO *dio) : Command(description, dio){
}
/**
 * this function prints the current settings, then asks the user for new setting for the algorithm and send them to server.
 */
void ClientSettingsCommand::execute() {
    string ans;
    cout << dio->read() << endl;
    dio->write("linebreak");
    getline(cin,  ans);
    if (ans.empty()) {
        dio->write("ret");
        return;
    }
    dio->write(ans);
    return;
}
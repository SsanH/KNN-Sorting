//
// Created by sanvm on 1/19/23.
//

#include "CLI.h"

using namespace std;

//CLI constructor.
CLI::CLI(ClientData cd1, DefaultIO *dio) : cd(cd1) {
    this->dio = dio;
    this->cd = cd1;
    c[0] = new ServerUploadCommand(&cd, "Welcome to the KNN Classifier Server. Please choose an option:", dio);
    c[1] = new ServerUploadCommand(&cd, "1. upload an unclassified csv data file", dio);
    c[2] = new SettingsCommand(&cd, "2. algorithm settings", dio);
    c[3] = new RunKNNCommand(&cd, "3. classify data", dio);
    c[4] = new ReturnAnswerCommand(&cd, "4. display results", dio);
    c[5] = new ServerDownloadCommand(&cd, "5. download results", dio);
}
//writes print menu.
void CLI::printMenu() {
    for (int i = 0; i < 6; i++) {
        dio->write(c[i]->getDescription());
        string clean = dio->read();
    }
    dio->write("8. exit");
    string clean = dio->read();
    dio->write("end");
}
//client command interface.
void CLI::chooseCommand(int commandNum) {
    if (0 < commandNum && commandNum < 6) {
        c[commandNum]->execute();
    }
}

//void CLI::freeBlocks(){
//    delete this->c;
//}

//client server running
void CLI::clientServer() {
    //accepts the client and the communication goes through client_sock
    //while client is up.
    DataManager dm;
    int client = 1;
    while (client) {

        this->printMenu();
        string s = dio->read();
        if(s == "linebreak"){
          s = dio->read();
        }
        vector <string> vec = dm.parseString(s, " ");
        //checks input correctness.
        if (vec.size() != 1) {
            dio->write("invalid option\n");
            continue;
        }
        if( !dm.isNum(s)){
            dio->write("invalid option\n");
            continue;
        }

        double commandNum = stod(s);
        if (commandNum < 0 || commandNum > 8) {
            dio->write("invalid option\n");
            continue;
        }
        if (commandNum == 8) {
            client = 0;
            //freeBlocks();
            break;
        }
        if (floor(commandNum) != commandNum){
            dio->write("invalid option\n");
            continue;
        }
        this->chooseCommand(commandNum);
    }
    close(cd.getSocket());
}


CLI::~CLI() {
    delete this->c[0];
    delete this->c[1];
    delete this->c[2];
    delete this->c[3];
    delete this->c[4];
    delete this->c[5];
}
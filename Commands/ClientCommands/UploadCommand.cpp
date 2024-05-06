//
// Created by ynon on 20/01/23.
//

#include "UploadCommand.h"

UploadCommand::UploadCommand(string description, DefaultIO *dio) : Command(description, dio) {

}
/**
 * gets a path to classified data and sends the data to the server. repeats process for unclassified data.
 */
void UploadCommand::execute() {

    string path;

    //print "upload classified csv data" from server
    cout << dio->read() << endl;
    getline(cin, path);

    ifstream classified(path);
    if (classified.fail()) {
      cout << "invalid input" << endl;
      dio->write("nofile");
      return;
    }
    dio->write("ok");
    while (!classified.eof()) {
        string line;
        getline(classified, line);
        dio->write(line);
        string linebreak = dio->read();
    }
    dio->write("done");
    string clean = dio->read();
    classified.close();

    cout << dio->read() << endl;
    getline(cin, path);

    ifstream unClassified(path);
    if (!unClassified.is_open()) {
      cout << "invalid input" << endl;
      dio->write("nofile");
      return;
    }
    dio->write("ok");
    while (!unClassified.eof()) {
        string line;
        getline(unClassified, line);
        dio->write(line);
        string linebreak = dio->read();
    }
    unClassified.close();
    dio->write("done");
    clean = dio->read();

}

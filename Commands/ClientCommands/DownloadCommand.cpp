//
// Created by ynon on 19/01/23.
//

#include "DownloadCommand.h"
#include <thread>

DownloadCommand::DownloadCommand(string description, DefaultIO *dio, string path)
        : Command(description, dio) {

    this->path = path;
}

/**
 * this function gets a path and a vector of strings and writes those strings to a file.
 * @param path
 * @param data
 */
void download(string path, vector<string> data) {

    ofstream  outFile(path);
    outFile.clear();

    for (string s : data) {
        outFile << s << endl;
    }
    outFile.close();
}

/**
 * asks user for a path to a file in which to download the results of the algorithm. then gets the data from the server and
 * downloads it to the file on a different thread.
 */
void DownloadCommand::execute() {
    string path;
    getline(cin, path);

    vector<string> dataForDownload;
    while (true) {
        string line = dio->read();
        dio->write("linebreak");
        if (line == "end") {
            break;
        } else {
            dataForDownload.push_back(line);
        }
    }

    thread new_thread(download, path, dataForDownload);
    new_thread.detach();
}

string DownloadCommand::getPath() {
    return this->path;
}

void DownloadCommand::setPath(string path) {
    this->path = path;
}

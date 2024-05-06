//
// Created by ynon on 20/01/23.
//

#include "Commands/ClientCommands/DownloadCommand.h"
#include "Commands/ClientCommands/UploadCommand.h"
#include "inputOutput/StandardIO.h"
#include <iostream>
#include "inputOutput/DataManager.h"
#include "inputOutput/DataPoint.h"
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "inputOutput/RequestDetails.h"
#include "clientFolder/clientProcess.h"
#include "inputOutput/SocketIO.h"
#include "unistd.h"
#include "Commands/ClientCommands/ClientSettingsCommand.h"


int main(int argc, char* argv[]) {

    string downloadPath = "";

    const char* ipAddress = argv[1];
    const int portNo = stoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0); // creating socket
    if (sock < 0) {
        perror("error creating socket");
    }
    connectToServer(sock, ipAddress, portNo);
    SocketIO sio(sock);

    Command* commands[3] = {new UploadCommand("upload an unclassified csv data file", &sio),
                            new ClientSettingsCommand("desc", &sio),
                            new DownloadCommand("download results", &sio, downloadPath)};

    while (true) {
        string option;
        while (true) {
            string message = sio.read();
            if (message == "end") {
                break;
            }
            sio.write("linebreak");
            cout << message << endl;
        }
        getline(cin, option);
        if (option.empty()) {
            sio.write("ret");
            continue;
        }
        sio.write(option);

        if (option == "1") {
            commands[0]->execute();
        }
        if (option == "2") {
            commands[1]->execute();
        }
        if (option == "5") {
            string cantExecute = sio.read();
            sio.write("linebreak");
            if (cantExecute == "1") {
               // string clean = sio.read();
                continue;
            }
            commands[2]->execute();
        }
        if (option == "8") {
            delete commands[0];
            delete commands[1];
            delete commands[2];
            exit(0);
        }
        else {
            continue;
        }
    }
    return 0;
}
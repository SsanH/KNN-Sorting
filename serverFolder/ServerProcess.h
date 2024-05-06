
#include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>
#include "../Calc/KNN.h"
#include "../Calc/Metrics/CanberraDis.h"
#include "../Calc/Metrics/ChebyshevDis.h"
#include "../Calc/Metrics/TaxiCabDis.h"
#include "../Calc/Metrics/EuclideanDis.h"
#include "../Calc/Metrics/MinkowskiDis.h"
#include "../inputOutput/RequestDetails.h"
#include "../inputOutput/DataManager.h"
#include "../Calc/CLI.h"
#include "../inputOutput/SocketIO.h"
#include <thread>

using namespace std;

class ServerProcess {
    public:
        void runProcess(int port);
};

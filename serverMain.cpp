
#include "serverFolder/ServerProcess.h"
#include <string>
using namespace std;

int main(int argc, char*argv[]) {

    ServerProcess sp;
    sp.runProcess(stoi(argv[1]));

}

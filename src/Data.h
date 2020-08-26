#ifndef DATA_H
#define DATA_H
#include "Instance.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#define LEN          256
#define CPU_BASE_REF 2000

using namespace std;

union Cost {
    int iCost;
    double dCost;
};

class Data {
    string getTime();
    string getOS();
    string getCpuInfo();
    vector< string > argvs;

  public:
    int isOptimal;
    int isRounded;
    int passMark;
    Cost baseSolution;
    Cost bestKnownSolution;
    double baseTimeLimit;
    string competitorName;
    string path;
    string execCommand;
    Instance instance;

    Data() {}
    Data(int argc, char* arguments[]);
    Instance* getInstance() { return &instance; }
    string createHeader();
    string getNameOfOutputFile();
    void separateExecCommands();
    vector< char* > getExecCommandArgvs();
};

#endif
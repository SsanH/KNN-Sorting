//
// Created by sanvm on 1/19/23.
//

#include "ClientData.h"
/**
 * constructor.
 * @param sock1
 * @param serverPort1
 */
ClientData::ClientData(int sock1, int serverPort1) {
    this->serverPort = serverPort1;
    this->sock = sock1;
    this->k = 5;
    this->metric = "AUC";
}
//adds vectors to classified
void ClientData::addVectorClassified(DataPoint v) {
    this->classifiedVec.push_back(v);
}
//gets size of answer vec
int ClientData::getAnswerSize(){
    return this->answerVector.size();
}

void ClientData::addVectorUnclassified(std::vector<double> v) {
    this->unClassifiedVec.push_back(v);
}

void ClientData::addAnswerVector(DataPoint v){
    this->answerVector.push_back(v);
}

void ClientData::changeMetric(string m1) {
    this->metric = m1;
}

void ClientData::changeK(int k1) {
    this->k = k1;
}

int ClientData::getK() {
    return this->k;
}

string ClientData::getMetric() {
    return this->metric;
}

std::vector<DataPoint> ClientData::getAnswer() {
    return this->answerVector;
}

int ClientData::getSocket() {
    return this->sock;
}

int ClientData::getDataSize() {
    return this->classifiedVec.size();
}

int ClientData::getDataSizeUnclassified() {
    return this->unClassifiedVec.size();
}


vector<DataPoint> ClientData::getAnswerVector(){
    return this->answerVector;
}

vector<DataPoint> ClientData::getClassifiedVector(){
    return this->classifiedVec;
}

vector<vector<double>> ClientData::getUnClassifiedVector(){
    return this->unClassifiedVec;
}
//clears vec
void ClientData::clearVecs(){
    this->classifiedVec.clear();
    this->unClassifiedVec.clear();
    this->answerVector.clear();
}


void ClientData::clearAnswer(){
    this->answerVector.clear();
}

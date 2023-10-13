#include "../include/Server.h"
#include <iostream>
#include <fstream>

Server::Server(){
    this->nbrOfSensors = 4;
    this->fileLogging = true;
    this->consoleLogging = false;
    this->lsData = false;
    this->ssData = 0;
    this->tsData = 0.f;
    this->hsData = 0.f;
}

Server::Server(const Server &other) {
    this->nbrOfSensors = other.nbrOfSensors;
    this->fileLogging = other.fileLogging;
    this->consoleLogging = other.consoleLogging;
    this->lsData = other.lsData;
    this->ssData = other.ssData;
    this->tsData = other.tsData;
    this->hsData = other.hsData;
}

Server::~Server()= default;

void Server::fileWrite(const char *s) const{
    std::ofstream ofstream;
    ofstream.open(s, std::ios_base::out);
    if(ofstream.fail()){
        std::cerr << "[ERROR] cannot open the file : " << s << std::endl;
    }
    ofstream << *this;
    ofstream.close();
}

void Server::fileWrite(const std::string &s) const {
    this->fileWrite(s.c_str());
}

std::ostream& operator<<(std::ostream &os, const Server &s){
    os.setf(std::ios::fixed);
    os.precision(Server::FLOAT_PRECISION);
    os << "The temperature is : " << s.tsData << "°C\n"
       << (s.lsData ? "There is enough light\n" : "There is not enough light\n")
       << "The sound level is : " << s.ssData << " dB\n"
       << "The humidity is at : " << s.hsData << "%" << std::endl;
    return os;

}

void Server::consoleWrite() const{
    std::cout << *this;
}

void Server::setConsoleLog(bool state) {
    this->consoleLogging = state;
}


void Server::setFileLog(bool state) {
    this->fileLogging = state;
}

Server::Server(unsigned int nbrOfSensors, bool consoleLogging, bool fileLogging) {
    this->nbrOfSensors = nbrOfSensors;
    this->consoleLogging = consoleLogging;
    this->fileLogging = fileLogging;
    this->hsData = 0.f;
    this->ssData = 0;
    this->lsData = false;
    this->tsData = 0.f;
}

void Server::recieveData(unsigned int data, Sensor::Type id) {
    if(id == Sensor::SND){
        this->ssData = data;
    }
    if(this->fileLogging){
        this->fileWrite("../text.txt");
    }
    if(this->consoleLogging){
        std::cout << *this;
    }

}

void Server::recieveData(float data, Sensor::Type id) {
    switch(id){
        case Sensor::TMP:
            this->tsData = data;
            break;
        case Sensor::HDT:
            this->hsData = data;
            break;
        default:
            break;
    }
    if(this->fileLogging){
        this->fileWrite("../text.txt");
    }
    if(this->consoleLogging){
        std::cout << *this;
    }
}

void Server::recieveData(bool data, Sensor::Type id) {
    if(id == Sensor::LGT){
        this->lsData = data;
    }
    if(this->fileLogging){
        this->fileWrite("../text.txt");
    }
    if(this->consoleLogging){
        std::cout << *this;
    }
}

Server &Server::operator=(const Server &other) = default;

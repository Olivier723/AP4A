#include "../include/Server.h"
#include <iostream>
#include <fstream>

Server::Server(){
    this->fileLogging = true;
    this->consoleLogging = false;
    this->lsData = false;
    this->ssData = 0;
    this->tsData = 0.f;
    this->hsData = 0.f;
}

Server::Server(bool consoleLogging, bool fileLogging) {
    this->consoleLogging = consoleLogging;
    this->fileLogging = fileLogging;
    this->hsData = 0.f;
    this->ssData = 0;
    this->lsData = false;
    this->tsData = 0.f;
}

Server::Server(const Server &other) {
    this->fileLogging = other.fileLogging;
    this->consoleLogging = other.consoleLogging;
    this->lsData = other.lsData;
    this->ssData = other.ssData;
    this->tsData = other.tsData;
    this->hsData = other.hsData;
}

Server::~Server() = default;

std::ostream& operator<<(std::ostream &os, const Server &s){
    os.setf(std::ios::fixed);
    os.precision(Server::FLOAT_PRECISION);
    os << "The temperature is : " << s.tsData << "°C\n"
       << (s.lsData ? "There is enough light\n" : "There is not enough light\n")
       << "The sound level is : " << s.ssData << " dB\n"
       << "The humidity is at : " << s.hsData * 100<< "%" << std::endl;
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

Server &Server::operator=(const Server &other) = default;

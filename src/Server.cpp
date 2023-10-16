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

Server::Server(unsigned int nbrOfSensors, bool consoleLogging, bool fileLogging) {
    this->nbrOfSensors = nbrOfSensors;
    this->consoleLogging = consoleLogging;
    this->fileLogging = fileLogging;
    this->hsData = 0.f;
    this->ssData = 0;
    this->lsData = false;
    this->tsData = 0.f;
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


void Server::recieveData(unsigned int data, SensorType id) {
    if(this->fileLogging){
        Server::fileWrite(data, id);
    }
    if(this->consoleLogging){
        std::cout << *this;
    }

}

void Server::recieveData(float data, SensorType id) {
    if(this->fileLogging){
        Server::fileWrite(data, id);
    }
    if(this->consoleLogging){
        std::cout << *this;
    }
}

void Server::recieveData(bool data, SensorType id) {
    if(this->fileLogging){
        Server::fileWrite(data, id);
    }
    if(this->consoleLogging){
        std::cout << *this;
    }
}

void Server::fileWrite(unsigned int data, SensorType t){
    std::ofstream ofs("../logs/soundsensor.log", std::ios::app);
    if(ofs.fail()){
        std::cerr << "[ERROR] Cannot open ../logs/soundsensor.log" << std::endl;
        return;
    }
    ofs << "Sound : " << data << " dB" << std::endl;
    ofs.close();
}

void Server::fileWrite(float data, SensorType t){
    std::string name;
    switch(t){
        case HMDT:
            name = "../logs/humiditysensor.log";
            break;
        case TEMP:
            name = "../logs/tempsensor.log";
            break;
        default:
            return;
    }
    std::ofstream ofs(name, std::ios::app);
    if(ofs.fail()){
        std::cerr << "[ERROR] Cannot open " << name << std::endl;
        return;
    }
    ofs.setf(std::ios::fixed);
    ofs.precision(Server::FLOAT_PRECISION);
    switch(t){
        case HMDT:
            ofs << "Humidity : " << data << " %\n";
            break;
        case TEMP:
            ofs << "Temperature : " << data << " °C\n";
            break;
        default:
            return;
    }

    ofs.close();
}

void Server::fileWrite(bool data, SensorType t){
    std::ofstream ofs("../logs/lightsensor.log", std::ios::app);
    if(ofs.fail()){
        std::cerr << "[ERROR] Cannot open ../logs/lightsensor.log" << std::endl;
        return;
    }
    ofs << (data ? "There is enough light" : "There is not enough light") << std::endl;
    ofs.close();
}

Server &Server::operator=(const Server &other) = default;

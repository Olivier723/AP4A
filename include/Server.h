//
// Created by olivier on 9/15/23.
//
#ifndef TP1_SERVER_H
#define TP1_SERVER_H

#include <ostream>
#include "Sensor.h"

class Server {
private:
    unsigned int nbrOfSensors;
    bool consoleLogging, fileLogging;
    bool lsData;
    unsigned int ssData;
    float tsData, hsData;
    static const int FLOAT_PRECISION = 2;
    void fileWrite(unsigned int data, Sensor::Type t) const;
    void fileWrite(float data, Sensor::Type t) const;
    void fileWrite(bool data, Sensor::Type t) const;
public:
    Server();
    Server(const Server &other);
    Server(unsigned int nbrOfSensors, bool consoleLogging, bool fileLogging);
    virtual ~Server();
    void consoleWrite() const;
    void recieveData(unsigned int data, Sensor::Type id);
    void recieveData(float data, Sensor::Type id);
    void recieveData(bool data, Sensor::Type id);
    void setConsoleLog(bool state);
    void setFileLog(bool state);
    Server& operator=(const Server &other);
    friend std::ostream& operator<<(std::ostream &os, const Server &s);

};

#endif //TP1_SERVER_H

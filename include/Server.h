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
    static void fileWrite(unsigned int data, SensorType t);
    static void fileWrite(float data, SensorType t);
    static void fileWrite(bool data, SensorType t);
    void consoleWrite() const;
public:
    Server();
    Server(const Server &other);
    Server(unsigned int nbrOfSensors, bool consoleLogging, bool fileLogging);
    virtual ~Server();
    void recieveData(unsigned int data, SensorType id);
    void recieveData(float data, SensorType id);
    void recieveData(bool data, SensorType id);
    void setConsoleLog(bool state);
    void setFileLog(bool state);
    Server& operator=(const Server &other);
    friend std::ostream& operator<<(std::ostream &os, const Server &s);

};

#endif //TP1_SERVER_H

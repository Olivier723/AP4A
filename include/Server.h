//
// Created by olivier on 9/15/23.
//
#ifndef TP1_SERVER_H
#define TP1_SERVER_H

#include <ostream>
#include <fstream>
#include "Sensor.h"

class Server {
private:
    bool consoleLogging, fileLogging;
    bool lsData;
    unsigned int ssData;
    float tsData, hsData;
    static const int FLOAT_PRECISION = 2;

    void consoleWrite() const;

    template<class T>
    static void fileWrite(T data, SensorType t, unsigned int sensor_num){
        std::string name;
        std::string sensor_num_str = std::to_string(sensor_num);
        switch(t) {
            case HMDT:
                name = "../logs/humiditysensor" + sensor_num_str + ".log";
                break;
            case TEMP:
                name = "../logs/tempsensor" + sensor_num_str + ".log";
                break;
            case SND:
                name = "../logs/soundsensor" + sensor_num_str + ".log";
                break;
            case LGHT:
                name = "../logs/lightsensor" + sensor_num_str + ".log";
                break;
            default:
                return;
        }
        std::ofstream ofs(name, std::ios::app);
        if(ofs.fail()){
            std::cerr << "[ERROR] Cannot open : " << name  << std::endl;
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
            case SND:
                ofs << "Sound : " << data << " dB" << std::endl;
                break;
            case LGHT:
                ofs << (data ? "There is enough light" : "There is not enough light") << std::endl;
                break;
            default:
                return;
        }
        ofs.close();
    }
public:
    Server();
    Server(const Server &other);
    Server(bool consoleLogging, bool fileLogging);
    virtual ~Server();

    template<class T>
    void recieveData(T data, SensorType id, unsigned int sensor_num) const{
        if(this->fileLogging){
            Server::fileWrite(data, id, sensor_num);
        }
        if(this->consoleLogging){
            std::cout << *this;
        }
    }

    void setConsoleLog(bool state);
    void setFileLog(bool state);
    Server& operator=(const Server &other);
    friend std::ostream& operator<<(std::ostream &os, const Server &s);

};

#endif //TP1_SERVER_H

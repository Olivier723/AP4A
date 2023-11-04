//
// Created by olivier on 9/15/23.
//
#ifndef TP1_SERVER_H
#define TP1_SERVER_H

#include <ostream>
#include <fstream>
#include "Sensor.hpp"

class Server {
private:
    bool console_logging, file_logging;

    // Write floats to the console with 2 digits after the dot
    static const int FLOAT_PRECISION = 2;

    template<class T>
    void console_write(T data, SensorType type, unsigned int sensor_num) const{
        std::cout << "Received data from ";
        switch (type) {
            case SensorType::HMDT:
                std::cout << "humidity sensor ";
                break;
            case SensorType::SND:
                std::cout << "sound sensor ";
                break;
            case SensorType::TEMP:
                std::cout << "temperature sensor ";
                break;
            case SensorType::LGHT:
                std::cout << "light sensor ";
                break;
            default:
                std::cout << "unknown sensor ";
        }
        std::cout << "n°" << sensor_num << " :\n";
        Server::write(data, type, std::cout);
    }

    /**
     * Creates (if it doesn't already exist) a file named "sensortype_sensornum.log" containing all the data received by that specific sensor
     * @param data
     * @param type the type of the sensor sending the data
     * @param sensor_num the number of the sensor sending the data
     */
    template<class T>
    void file_write(T data, SensorType type, unsigned int sensor_num){
        std::string name;
        std::string sensor_num_str = std::to_string(sensor_num);
        switch(type) {
            case SensorType::HMDT:
                name = "./logs/humiditysensor" + sensor_num_str + ".log";
                break;
            case SensorType::TEMP:
                name = "./logs/tempsensor" + sensor_num_str + ".log";
                break;
            case SensorType::SND:
                name = "./logs/soundsensor" + sensor_num_str + ".log";
                break;
            case SensorType::LGHT:
                name = "./logs/lightsensor" + sensor_num_str + ".log";
                break;
            default:
                return;
        }
        std::ofstream ofs(name, std::ios::app);
        if(ofs.fail()){
            std::cerr << "[ERROR] Cannot open : " << name  << std::endl;
            return;
        }
        Server::write(data, type, ofs);
        ofs.close();
    }

    template<class T>
    static void write(T data, SensorType type, std::ostream &os){
        os.setf(std::ios::fixed);
        os.precision(Server::FLOAT_PRECISION);
        switch(type){
            case SensorType::HMDT:
                os << "Humidity : " << data << " %\n";
                break;
            case SensorType::TEMP:
                os << "Temperature : " << data << " °C\n";
                break;
            case SensorType::SND:
                os << "Sound : " << data << " dB\n";
                break;
            case SensorType::LGHT:
                os << (data ? "There is enough light\n" : "There is not enough light\n");
                break;
            default:
                return;
        }
    }
public:
    Server();
    Server(const Server &other);
    Server& operator=(const Server &other);
    Server(bool consoleLogging, bool fileLogging);


    virtual ~Server();

    /**
     * @tparam T the type of the data sent (must be an unsigned int, a float or a bool otherwise it can cause undefined behavior)
     * @param data
     * @param type
     * @param sensor_num
     */
    template<class T>
    void receive_data(T data, SensorType type, unsigned int sensor_num){
        if(this->file_logging){
            this->file_write(data, type, sensor_num);
        }
        if(this->console_logging) {
            this->console_write(data, type, sensor_num);
        }
    }
    void set_console_log(bool state);
    void set_file_log(bool state);
};

#endif //TP1_SERVER_H

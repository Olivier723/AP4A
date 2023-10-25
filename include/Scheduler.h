//
// Created by olivier on 9/15/23.
//

#ifndef TP1_SCHEDULER_H
#define TP1_SCHEDULER_H

#include <vector>

#include "Sensor.h"
#include "Server.h"
#include "LightSensor.h"
#include "TemperatureSensor.h"
#include "SoundSensor.h"
#include "HumiditySensor.h"

class Scheduler{
private:
    Server server;
    std::vector<LightSensor> light_sensors;
    std::vector<TemperatureSensor> temp_sensors;
    std::vector<SoundSensor> sound_sensors;
    std::vector<HumiditySensor> humid_sensors;

    template<class T>
    void poll_sensors(const std::vector<T>& sensors) const;
public:
    Scheduler();
    virtual ~Scheduler();
    void update();


    void add_sensor(const LightSensor& sensor);
    void add_sensor(const SoundSensor& sensor);
    void add_sensor(const TemperatureSensor& sensor);
    void add_sensor(const HumiditySensor& sensor);
};

#endif //TP1_SCHEDULER_H

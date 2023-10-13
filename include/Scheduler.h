//
// Created by olivier on 9/15/23.
//

#ifndef TP1_SCHEDULER_H
#define TP1_SCHEDULER_H

#include "Sensor.h"
#include "Server.h"

class Scheduler{
private:
    Server server;
    Sensor::LightSensor ls;
    Sensor::TemperatureSensor ts;
    Sensor::SoundSensor ss;
    Sensor::HumiditySensor hs;
public:
    Scheduler();
    virtual ~Scheduler();
    Server& getServer();
    void pollSensor(Sensor::Type type);
    void update();
};

#endif //TP1_SCHEDULER_H

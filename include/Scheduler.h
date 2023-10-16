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
    LightSensor ls;
    TemperatureSensor ts;
    SoundSensor ss;
    HumiditySensor hs;
public:
    Scheduler();
    virtual ~Scheduler();
    Server& getServer();

    void pollSensor(LightSensor ls);
    void pollSensor(SoundSensor ss);
    void pollSensor(TemperatureSensor ts);
    void pollSensor(HumiditySensor hs);
    void update();
};

#endif //TP1_SCHEDULER_H

//
// Created by olivier on 9/15/23.
//
#include "../include/Scheduler.h"

Scheduler::Scheduler() {
    this->server = Server(4, true, true);
    this->ts = Sensor::TemperatureSensor();
    this->ss = Sensor::SoundSensor();
    this->hs = Sensor::HumiditySensor();
    this->ls = Sensor::LightSensor();
}

void Scheduler::pollSensor(Sensor::Type type) {
    if(type == Sensor::LGT){
        this->server.recieveData(ls.sendData(), type);
    }else if(type == Sensor::TMP){
        this->server.recieveData(ts.sendData(), type);
    }else if(type == Sensor::HDT){
        this->server.recieveData(hs.sendData(), type);
    }else if(type == Sensor::SND){
        this->server.recieveData(ss.sendData(), type);
    }
}

void Scheduler::update() {
    this->ls.update();
    this->hs.update();
    this->ss.update();
    this->ts.update();
    this->pollSensor(Sensor::TMP);
    this->pollSensor(Sensor::LGT);
    this->pollSensor(Sensor::HDT);
    this->pollSensor(Sensor::SND);
}

Scheduler::~Scheduler() = default;


//
// Created by olivier on 9/15/23.
//
#include "../include/Scheduler.h"

Scheduler::Scheduler() {
    this->server = Server(4, true, true);
    this->ts = TemperatureSensor();
    this->ss = SoundSensor();
    this->hs = HumiditySensor();
    this->ls = LightSensor();
}

void Scheduler::pollSensor(HumiditySensor hs){
    this->server.recieveData(hs.sendData(), hs.getType());
}
void Scheduler::pollSensor(LightSensor ls) {
    this->server.recieveData(ls.sendData(), ls.getType());
}
void Scheduler::pollSensor(SoundSensor ss) {
    this->server.recieveData(ss.sendData(), ss.getType());
}
void Scheduler::pollSensor(TemperatureSensor ts) {
    this->server.recieveData(ts.sendData(), ts.getType());
}

void Scheduler::update() {
    this->ls.update();
    this->hs.update();
    this->ss.update();
    this->ts.update();
    this->pollSensor(ls);
    this->pollSensor(hs);
    this->pollSensor(ss);
    this->pollSensor(ts);
}

Server &Scheduler::getServer() {
    return this->server;
}

Scheduler::~Scheduler() = default;


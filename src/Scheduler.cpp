//
// Created by olivier on 9/15/23.
//
#include "../include/Scheduler.h"

Scheduler::Scheduler() {
    this->server = Server(false, true);
    this->temp_sensors = std::vector<TemperatureSensor>();
    this->sound_sensors = std::vector<SoundSensor>();
    this->humid_sensors = std::vector<HumiditySensor>();
    this->light_sensors = std::vector<LightSensor>();
}

template<class T>
void Scheduler::poll_sensors(const std::vector<T> &sensors) const{
    for(std::size_t i = 0; i < sensors.size(); i++)
        this->server.recieveData(sensors[i].send_data(), sensors[i].getType(), i+1);
}

void Scheduler::update() {
    for(auto &ls : this->light_sensors)
        ls.update();
    for(auto &hs : this->humid_sensors)
        hs.update();
    for(auto &ss : this->sound_sensors)
        ss.update();
    for(auto &ts : this->temp_sensors)
        ts.update();
    this->poll_sensors(light_sensors);
    this->poll_sensors(humid_sensors);
    this->poll_sensors(sound_sensors);
    this->poll_sensors(temp_sensors);
}

void Scheduler::add_sensor(const LightSensor &sensor) {
    this->light_sensors.push_back(sensor);
}

void Scheduler::add_sensor(const SoundSensor &sensor) {
    this->sound_sensors.push_back(sensor);
}

void Scheduler::add_sensor(const TemperatureSensor &sensor) {
    this->temp_sensors.push_back(sensor);
}

void Scheduler::add_sensor(const HumiditySensor &sensor) {
    this->humid_sensors.push_back(sensor);
}

Scheduler::~Scheduler() = default;


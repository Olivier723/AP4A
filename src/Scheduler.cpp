//
// Created by olivier on 9/15/23.
//
#include "../include/Scheduler.h"
#include <ctime>

Scheduler::Scheduler(const Server &server) {
    std::srand(std::time(nullptr));
    this->server = server;
    this->temp_sensors = std::vector<TemperatureSensor>();
    this->sound_sensors = std::vector<SoundSensor>();
    this->humid_sensors = std::vector<HumiditySensor>();
    this->light_sensors = std::vector<LightSensor>();
}

void Scheduler::update() {
    for(LightSensor &ls : this->light_sensors)
        ls.update();
    for(HumiditySensor &hs : this->humid_sensors)
        hs.update();
    for(SoundSensor &ss : this->sound_sensors)
        ss.update();
    for(TemperatureSensor &ts : this->temp_sensors)
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


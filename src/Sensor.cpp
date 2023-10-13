//
// Created by olivier on 9/15/23.
//
#include "../include/Sensor.h"

namespace Sensor {
    template<class T>
    float Sensor<T>::aleaFloatGen() {
        return (float) std::rand() / (float) RAND_MAX;
    }

    template<class T>
    bool Sensor<T>::aleaBoolGen() {
        return std::rand() % 2;
    }

    template<class T>
    int Sensor<T>::aleaIntGen() {
        return std::rand(); //Arbitrary limit on maxium sound intensity
    }

    LightSensor &LightSensor::operator=(const LightSensor &other) {
        this->data = other.data;
        return *this;
    }

    LightSensor::LightSensor() {
        this->data = false;
    }

    bool LightSensor::sendData() {
        return this->data;
    }

    void LightSensor::update() {
        this->data = Sensor::aleaBoolGen();
    }

    SoundSensor::SoundSensor() {
        this->data = 0;
    }

    SoundSensor &SoundSensor::operator=(const SoundSensor &other) {
        this->data = other.data;
        return *this;
    }

    void SoundSensor::update() {
        this->data = (unsigned int) Sensor::aleaIntGen() % MAX_DECIBEL;
    }

    unsigned int SoundSensor::sendData() {
        return this->data;
    }

    void TemperatureSensor::update() {
        this->data = Sensor::aleaFloatGen() * MAX_TEMP;
    }

    TemperatureSensor &TemperatureSensor::operator=(const TemperatureSensor &other) {
        this->data = other.data;
        return *this;
    }

    TemperatureSensor::TemperatureSensor() {
        this->data = 0.f;
    }

    float TemperatureSensor::sendData() {
        return this->data;
    }

    HumiditySensor::HumiditySensor() {
        this->data = 0.f;
    }

    HumiditySensor &HumiditySensor::operator=(const HumiditySensor &other) {
        this->data = other.data;
        return *this;
    }

    float HumiditySensor::sendData() {
        return this->data;
    }

    void HumiditySensor::update() {
        this->data = Sensor::aleaFloatGen();
    }
}

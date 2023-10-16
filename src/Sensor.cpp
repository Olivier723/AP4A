//
// Created by olivier on 9/15/23.
//
#include <fstream>
#include <iostream>
#include "../include/Sensor.h"


template<class T>
/**
 * @return A float between 0 and 1
 */
float Sensor<T>::aleaFloatGen() {
    return (float) std::rand() / (float) RAND_MAX;
}

/**
 * @return A random boolean
 */
template<class T>
bool Sensor<T>::aleaBoolGen() {
    return std::rand() % 2;
}

/**
 * @return An int between 0 and RAND_MAX
 */
template<class T>
int Sensor<T>::aleaIntGen() {
    return std::rand();
}

/**
 * @return The data contained in the sensor
 */
template<class T>
T Sensor<T>::sendData() {
    return this->data;
}

/**
 * Updates the data in the sensor using the aleaValGen method to simulate a real life use
 * @tparam T
 */
template<class T>
void Sensor<T>::update() {
    this->data = this->aleaValGen();
}

LightSensor &LightSensor::operator=(const LightSensor &other) {
    this->data = other.data;
    return *this;
}

bool LightSensor::aleaValGen() {
    return LightSensor::aleaBoolGen();
}


SoundSensor &SoundSensor::operator=(const SoundSensor &other) {
    this->data = other.data;
    return *this;
}

unsigned int SoundSensor::aleaValGen() {
    return SoundSensor::aleaIntGen() % MAX_DECIBEL;
}


TemperatureSensor &TemperatureSensor::operator=(const TemperatureSensor &other) {
    this->data = other.data;
    return *this;
}


float TemperatureSensor::aleaValGen() {
    return TemperatureSensor::aleaFloatGen() * MAX_TEMP;
}


HumiditySensor &HumiditySensor::operator=(const HumiditySensor &other) {
    this->data = other.data;
    return *this;
}

float HumiditySensor::aleaValGen() {
    return HumiditySensor::aleaFloatGen() * 100;
}

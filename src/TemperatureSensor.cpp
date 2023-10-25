//
// Created by olivier on 10/22/23.
//

#include "../include/TemperatureSensor.h"

TemperatureSensor &TemperatureSensor::operator=(const TemperatureSensor &other) {
    this->data = other.data;
    return *this;
}


float TemperatureSensor::alea_val_gen() {
    return alea_float_gen() * MAX_TEMP;
}
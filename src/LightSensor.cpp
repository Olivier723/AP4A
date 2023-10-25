//
// Created by olivier on 10/22/23.
//

#include "../include/LightSensor.h"

LightSensor &LightSensor::operator=(const LightSensor &other) {
    this->data = other.data;
    return *this;
}

bool LightSensor::alea_val_gen() {
    return alea_bool_gen();
}

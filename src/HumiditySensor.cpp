//
// Created by olivier on 10/22/23.
//

#include "../include/HumiditySensor.h"

HumiditySensor &HumiditySensor::operator=(const HumiditySensor &other) {
    this->data = other.data;
    return *this;
}

float HumiditySensor::alea_val_gen() {
    return alea_float_gen() * 100;
}
//
// Created by olivier on 10/22/23.
//

#include "../include/SoundSensor.h"


SoundSensor &SoundSensor::operator=(const SoundSensor &other) {
    this->data = other.data;
    return *this;
}

unsigned int SoundSensor::alea_val_gen() {
    return alea_int_gen() % MAX_DECIBEL;
}

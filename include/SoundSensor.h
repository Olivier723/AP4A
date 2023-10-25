//
// Created by olivier on 10/22/23.
//

#ifndef TP1_SOUNDSENSOR_H
#define TP1_SOUNDSENSOR_H

#include "Sensor.hpp"

class SoundSensor : public Sensor<unsigned int> {
private:
    /**
     * Put an upper ceilling on the decibel range.
     */
    static const unsigned int MAX_DECIBEL = 200;

    unsigned int alea_val_gen() final;
public:
    SoundSensor() : Sensor<unsigned int>() {
        this->type = SND;
    };

    SoundSensor &operator=(const SoundSensor &other);

    ~SoundSensor() = default;
};

#endif //TP1_SOUNDSENSOR_H

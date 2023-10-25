//
// Created by olivier on 10/22/23.
//

#ifndef TP1_LIGHTSENSOR_H
#define TP1_LIGHTSENSOR_H

#include "Sensor.h"

class LightSensor : public Sensor<bool> {
private:
    bool alea_val_gen() override;
public:
    LightSensor() : Sensor<bool>() {
        this->type = LGHT;
    };

    LightSensor &operator=(const LightSensor &other);

    ~LightSensor() = default;
};

#endif //TP1_LIGHTSENSOR_H

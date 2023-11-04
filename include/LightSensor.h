//
// Created by olivier on 10/22/23.
//

#ifndef TP1_LIGHTSENSOR_H
#define TP1_LIGHTSENSOR_H

#include "Sensor.hpp"

class LightSensor final : public Sensor<bool> {
private:
    bool alea_val_gen() final;
public:
    LightSensor() : Sensor<bool>() {
        this->type = SensorType::LGHT;
    };

    LightSensor(const LightSensor &other) = default;

    LightSensor &operator=(const LightSensor &other);

    ~LightSensor() final = default;
};

#endif //TP1_LIGHTSENSOR_H

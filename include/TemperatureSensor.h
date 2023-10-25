//
// Created by olivier on 10/22/23.
//

#ifndef TP1_TEMPERATURESENSOR_H
#define TP1_TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor<float> {
private:
    /**
     * Limit the maximum temperature to 100°C as it doesn't make much sense to record higher in a house environment
     */
    constexpr static const float MAX_TEMP = 100.f;

    float alea_val_gen() override;
public:
    TemperatureSensor() : Sensor<float>() {
        this->type = TEMP;
    };

    TemperatureSensor &operator=(const TemperatureSensor &other);

    ~TemperatureSensor() = default;
};


#endif //TP1_TEMPERATURESENSOR_H

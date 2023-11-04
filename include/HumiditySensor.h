//
// Created by olivier on 10/22/23.
//

#ifndef TP1_HUMIDITYSENSOR_H
#define TP1_HUMIDITYSENSOR_H

#include "Sensor.hpp"

class HumiditySensor final : public Sensor<float> {
private:
    float alea_val_gen() final;
public:
    HumiditySensor() : Sensor<float>() {
        this->type = SensorType::HMDT;
    };

    HumiditySensor(const HumiditySensor &other) = default;

    HumiditySensor &operator=(const HumiditySensor &other);

    ~HumiditySensor() final = default;
};



#endif //TP1_HUMIDITYSENSOR_H

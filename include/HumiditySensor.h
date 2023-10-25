//
// Created by olivier on 10/22/23.
//

#ifndef TP1_HUMIDITYSENSOR_H
#define TP1_HUMIDITYSENSOR_H

#include "Sensor.h"

class HumiditySensor : public Sensor<float> {
private:
    float alea_val_gen() override;

public:
    HumiditySensor() : Sensor<float>() {
        this->type = HMDT;
    };

    HumiditySensor &operator=(const HumiditySensor &other);

    ~HumiditySensor() = default;
};



#endif //TP1_HUMIDITYSENSOR_H

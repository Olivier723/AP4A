//
// Created by olivier on 9/15/23.
//

#ifndef TP1_SENSOR_H
#define TP1_SENSOR_H
#define PURE 0

#include <iostream>

enum SensorType {
    NONE,
    TEMP,
    HMDT,
    SND ,
    LGHT,
};

template<class T>
class Sensor {
protected:
    T data;

    SensorType type;

    static float alea_float_gen() {
        return (float) std::rand() / (float) RAND_MAX;
    }

    static bool alea_bool_gen() {
        return std::rand() % 2;
    }

    static int alea_int_gen() {
        return std::rand();
    }

    Sensor() {
        this->data = {0};
        this->type = NONE;
    }
public:

    T send_data() const{
        return this->data;
    }

    /**
     * Updates the data of the sensor using the appropriate random value generator
     */
    void update(){
        this->data = this->alea_val_gen();
    }

    virtual T alea_val_gen() = PURE;

    SensorType getType() const {
        return this->type;
    };

    virtual ~Sensor() = default;
};



#undef PURE

#endif //TP1_SENSOR_H

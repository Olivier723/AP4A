#ifndef TP1_SENSOR_HPP
#define TP1_SENSOR_HPP

#include <iostream>

enum class SensorType {
    NONE,
    TEMP,  // Temperature
    HMDT,  // Humidity
    SND ,  // Sound
    LGHT,  // Light
};

template<class T>
class Sensor {
protected:
    T data;

    // The type of the sensor, to help with distinguishing them in the server
    SensorType type;

    /**
     * @return A float between 0 and 1
     */
    static float alea_float_gen() {
        return (float) std::rand() / (float) RAND_MAX;
    }

    /**
     * @return A pseudo random boolean
     */
    static bool alea_bool_gen() {
        return std::rand() % 2;
    }

    /**
     * @return A pseudo random unsigned integer between 0 and RAND_MAX
     */
    static unsigned int alea_int_gen() {
        return std::rand();
    }

    Sensor() {
        data = {0};
        type = SensorType::NONE;
    }

    Sensor(const Sensor<T> &other){
        this->type = other.type;
        this->data = other.data;
    }

    virtual ~Sensor() = default;
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

    virtual T alea_val_gen() = 0;

    SensorType get_type() const {
        return this->type;
    }
};

#endif //TP1_SENSOR_HPP

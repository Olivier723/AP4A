//
// Created by olivier on 9/15/23.
//

#ifndef TP1_SENSOR_H
#define TP1_SENSOR_H
#define PURE 0
#include <ostream>

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

    static float aleaFloatGen();

    static bool aleaBoolGen();

    static int aleaIntGen();

    Sensor() {
        this->data = 0;
        this->type = NONE;
    };
public:

    virtual T sendData();

    /**
     * Updates the data of the sensor using the appropriate random value generator
     */
    virtual void update();

    virtual T aleaValGen() = PURE;

    SensorType getType() {
        return this->type;
    };
};

class LightSensor : public Sensor<bool> {
private:
    bool aleaValGen() override;
public:
    LightSensor() : Sensor<bool>() {
        this->type = LGHT;
    };

    LightSensor &operator=(const LightSensor &other);

    ~LightSensor() = default;
};

class SoundSensor : public Sensor<unsigned int> {
private:
    /**
     * Put an upper ceilling on the decibel range.
     */
    static const unsigned int MAX_DECIBEL = 200;

    unsigned int aleaValGen() override;
public:
    SoundSensor() : Sensor<unsigned int>() {
        this->type = SND;
    };

    SoundSensor &operator=(const SoundSensor &other);

    ~SoundSensor() = default;
};

class TemperatureSensor : public Sensor<float> {
private:
    /**
     * Limit the maximum temperature to 100°C as it doesn't make much sense to record higher in a house environment
     */
    constexpr static const float MAX_TEMP = 100.f;

    float aleaValGen() override;
public:
    TemperatureSensor() : Sensor<float>() {
        this->type = TEMP;
    };

    TemperatureSensor &operator=(const TemperatureSensor &other);

    ~TemperatureSensor() = default;
};

class HumiditySensor : public Sensor<float> {
private:
    float aleaValGen() override;

public:
    HumiditySensor() : Sensor<float>() {
        this->type = HMDT;
    };

    HumiditySensor &operator=(const HumiditySensor &other);

    ~HumiditySensor() = default;
};


#undef PURE

#endif //TP1_SENSOR_H

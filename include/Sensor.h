//
// Created by olivier on 9/15/23.
//

#ifndef TP1_SENSOR_H
#define TP1_SENSOR_H
#define PURE 0
#include <ostream>

namespace Sensor {
    enum Type {
        TMP,
        HDT,
        SND,
        LGT
    };

    template<class T>
    class Sensor {
    protected:
        T data;

        static float aleaFloatGen();

        static bool aleaBoolGen();

        static int aleaIntGen();

        Sensor();
    public:

        virtual T sendData();

        /**
         * Updates the data of the sensor using the appropriate random value generator
         */
        virtual void update();

        virtual T aleaValGen() = PURE;
    };

    // If I put this in the .cpp file, the linker complains;
    // If I leave it here, it works
    // Why ???
    template<class T>
    Sensor<T>::Sensor() {
        this->data = 0;
    }

    class LightSensor : public Sensor<bool> {
    private:
        bool aleaValGen() override;
    public:
        LightSensor() : Sensor<bool>() {};

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
        SoundSensor() : Sensor<unsigned int>() {};

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
        TemperatureSensor() : Sensor<float>() {};

        TemperatureSensor &operator=(const TemperatureSensor &other);

        ~TemperatureSensor() = default;
    };

    class HumiditySensor : public Sensor<float> {
    private:
        float aleaValGen() override;
    public:
        HumiditySensor() : Sensor<float>() {};

        HumiditySensor &operator=(const HumiditySensor &other);

        ~HumiditySensor() = default;
    };
}

#undef PURE

#endif //TP1_SENSOR_H

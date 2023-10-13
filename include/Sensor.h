//
// Created by olivier on 9/15/23.
//

#ifndef TP1_SENSOR_H
#define TP1_SENSOR_H

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
        T data = 0;
    public:
        static float aleaFloatGen();

        static bool aleaBoolGen();

        static int aleaIntGen();

        virtual T sendData() = 0;

        virtual void update() = 0;

    };

    class LightSensor : Sensor<bool> {
    public:
        LightSensor();

        LightSensor &operator=(const LightSensor &other);

        ~LightSensor() = default;

        bool sendData() override;

        void update() override;
    };

    class SoundSensor : Sensor<unsigned int> {
    private:
        static const unsigned int MAX_DECIBEL = 200;
    public:
        SoundSensor();

        SoundSensor &operator=(const SoundSensor &other);

        ~SoundSensor() = default;

        unsigned int sendData() override;

        void update() override;

    };

    class TemperatureSensor : Sensor<float> {
    private:
        constexpr static const float MAX_TEMP = 100.f;
    public:
        TemperatureSensor();

        TemperatureSensor &operator=(const TemperatureSensor &other);

        ~TemperatureSensor() = default;

        float sendData() override;

        void update() override;
    };

    class HumiditySensor : Sensor<float> {
    public:
        HumiditySensor();

        HumiditySensor &operator=(const HumiditySensor &other);

        ~HumiditySensor() = default;

        float sendData() override;

        void update() override;
    };
}

#endif //TP1_SENSOR_H

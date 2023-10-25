cmake_minimum_required(VERSION 3.26)
project(TP1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)

add_executable(TP1 main.cpp
        src/Server.cpp
        include/Server.h
        include/Sensor.hpp
        src/Scheduler.cpp
        include/Scheduler.h
        src/LightSensor.cpp
        include/LightSensor.h
        src/SoundSensor.cpp
        include/SoundSensor.h
        src/TemperatureSensor.cpp
        include/TemperatureSensor.h
        src/HumiditySensor.cpp
        include/HumiditySensor.h
)

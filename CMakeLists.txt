cmake_minimum_required(VERSION 3.26)
project(TP1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)

add_executable(TP1 main.cpp
        src/Server.cpp
        include/Server.h
        src/Sensor.cpp
        include/Sensor.h
        src/Scheduler.cpp
        include/Scheduler.h)

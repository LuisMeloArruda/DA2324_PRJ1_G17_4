cmake_minimum_required(VERSION 3.23)
project(DA2324_PRJ1_G17_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA2324_PRJ1_G17_4
        src/Menu.cpp
        src/Menu.h
        src/main.cpp
        src/Graph.h
        src/Station.h
        src/Station.cpp
        src/Reservoir.h
        src/Reservoir.cpp
        src/City.cpp
        src/City.h)
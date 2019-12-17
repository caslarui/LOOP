cmake_minimum_required(VERSION 3.15)
project(LOOP)

set(CMAKE_CXX_STANDARD 14)

set(TARGET_SRC
        Game/Game.cpp
        Game/Map/Map.cpp)

add_executable(LOOP main.cpp ${TARGET_SRC})

cmake_minimum_required(VERSION 3.15)
project(LOOP)

set(CMAKE_CXX_STANDARD 14)

set(TARGET_SRC
        Game/Game.cpp
        Game/Map/Map.cpp
        Game/Characters/Attributes/Coords.cpp
        Game/Characters/Attributes/Effects.cpp
        Game/Characters/Heroes/Ability.cpp
        Game/Characters/Attributes/Strategy.cpp
        Game/Characters/Attributes/Stats.cpp)
set(TARGET_INC
        Game/Game.hpp
        Game/Map/Map.hpp
        Game/Characters/Attributes/Coords.hpp
        Game/Characters/Attributes/Effects.hpp
        Game/Characters/Heroes/Ability.hpp
        Game/Characters/Attributes/Strategy.hpp
        Game/Characters/Attributes/Stats.hpp)

add_executable(LOOP main.cpp ${TARGET_SRC} ${TARGET_INC})

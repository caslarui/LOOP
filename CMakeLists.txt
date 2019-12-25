cmake_minimum_required(VERSION 3.15)
project(LOOP)

set(CMAKE_CXX_STANDARD 14)

set(TARGET_SRC
        Game/Game.cpp
        Game/Map/Map.cpp
        Game/Characters/Heroes/Hero.cpp
        Game/Characters/Attributes/Coords.cpp
        Game/Characters/Attributes/Effects.cpp
        Game/Characters/Attributes/Strategy.cpp
        Game/Characters/Attributes/Stats.cpp
        Game/Characters/Heroes/Ability.cpp
        Game/Characters/Heroes/Knight/Execute.cpp
        Game/Characters/Heroes/Knight/Knight.cpp
        Game/Characters/Heroes/Knight/Slam.cpp
        Game/Characters/Heroes/Pyromancer/Fireblast.cpp
        Game/Characters/Heroes/Pyromancer/Ignite.cpp
        Game/Characters/Heroes/Pyromancer/Pyromancer.cpp
        Game/Characters/Heroes/Rogue/Backstab.cpp
        Game/Characters/Heroes/Rogue/Paralysis.cpp
        Game/Characters/Heroes/Rogue/Rogue.cpp
        Game/Characters/Heroes/Wizard/Drain.cpp
        Game/Characters/Heroes/Wizard/Wizard.cpp
        Game/Characters/Heroes/HeroFactory.cpp Game/Characters/Heroes/Wizard/Deflect.cpp Game/Characters/Heroes/Wizard/Deflect.hpp)
set(TARGET_INC
        Game/Game.hpp
        Game/Map/Map.hpp
        Game/Characters/Heroes/Hero.hpp
        Game/Characters/Attributes/Coords.hpp
        Game/Characters/Attributes/Effects.hpp
        Game/Characters/Attributes/Strategy.hpp
        Game/Characters/Attributes/Stats.hpp
        Game/Characters/Heroes/Ability.hpp
        Game/Characters/Heroes/Knight/Execute.hpp
        Game/Characters/Heroes/Knight/Slam.hpp
        Game/Characters/Heroes/Knight/Knight.hpp
        Game/Characters/Heroes/Pyromancer/Fireblast.hpp
        Game/Characters/Heroes/Pyromancer/Ignite.hpp
        Game/Characters/Heroes/Pyromancer/Pyromancer.hpp
        Game/Characters/Heroes/Rogue/Backstab.hpp
        Game/Characters/Heroes/Rogue/Paralysis.hpp
        Game/Characters/Heroes/Rogue/Rogue.hpp
        Game/Characters/Heroes/Wizard/Drain.hpp
        Game/Characters/Heroes/Wizard/Wizard.hpp
        Game/Characters/Heroes/HeroFactory.hpp)

add_executable(LOOP main.cpp ${TARGET_SRC})

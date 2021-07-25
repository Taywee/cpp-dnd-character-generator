cmake_minimum_required(VERSION 3.14)

project(sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    character-generator
    src/character.cxx
    src/attributes.cxx
    src/generateFunctions.cxx
    src/main.cxx
    src/races/human.cxx
    src/races/dragonborn.cxx
    src/races/dwarf.cxx
    src/races/hilldwarf.cxx
    src/races/elf.cxx
    src/races/highelf.cxx
    src/races/gnome.cxx
    src/races/rockgnome.cxx
    src/races/halfling.cxx
    src/races/lightfoothalfling.cxx
    src/races/halfelf.cxx
    src/races/halforc.cxx
    src/races/tiefling.cxx
    src/races/race.cxx
    )


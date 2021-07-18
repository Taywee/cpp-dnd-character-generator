cmake_minimum_required(VERSION 3.14)

project(sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    character-generator
    src/character.cxx
    src/dwarf.cxx
    src/hilldwarf.cxx
    src/human.cxx
    src/main.cxx
    src/race.cxx
    src/attributes.cxx
    src/generateAppearance.cxx
    )


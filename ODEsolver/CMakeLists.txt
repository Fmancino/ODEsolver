cmake_minimum_required(VERSION 3.2.2)

project(ODEsover)

#the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_library(ODEsolver ${SOURCES})

# Specify that this library itself needs access to the folder "common/include" and that any other
# target which depends on this also gets similar access - i.e. use 'PUBLIC'

target_include_directories(ODEsolver PUBLIC include)

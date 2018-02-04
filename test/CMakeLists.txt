cmake_minimum_required(VERSION 3.2.2)

project(testing)

# assuming you call cmake from test/build, places the makefiles of the ODEsolver library in
# ./ODEsolver/build

add_subdirectory(../ODEsolver ../../ODEsolver/build)



add_executable(Extinction Test_logistic_extinction.cpp)

# Specify that this exe depends upon ODEsolver.

target_link_libraries(Extinction ODEsolver)

add_executable(SinCos Test_SinCos.cpp)

target_link_libraries(SinCos ODEsolver)

add_executable(GenFunction Test_GenericFunction.cpp)

target_link_libraries(GenFunction ODEsolver)

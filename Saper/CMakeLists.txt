cmake_minimum_required(VERSION 3.6)
project(saper)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp calculate.h calculate.cpp generayt.cpp KreatWnd.h KreatWnd.cpp Butten.cpp Butten.h const.h generayt.h const_main.h memory_work.h memory_work.cpp)
add_executable(saper ${SOURCE_FILES})
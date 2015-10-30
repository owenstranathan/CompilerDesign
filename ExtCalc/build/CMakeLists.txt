#Owen's Cmake file for ext-calc-lang

#require make version 2.8 minimum
cmake_minimum_required(VERSION 2.8)

#compile with c++11 (because why would you not?)
#Turn on warnings and make then errs
set( CMAKE_CXX_FLAGS "-Wall -Werror -std=c++11")

#executable
file(GLOB extCalcLib
    "../extCalc/*.cpp"
)

add_executable(ext_calc_eval ${extCalcLib})

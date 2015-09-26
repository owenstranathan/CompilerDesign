#Owen's Cmake file for calc-lang

#require make version 2.8 minimum
cmake_minimum_required(VERSION 2.8)

#compile with c++11 (because why would you not?)
#Turn on warnings and make then errs
set( CMAKE_CXX_FLAGS "-Wall -Werror -std=c++11")

#executable
add_executable(calc_eval ../src/eval.cpp
                    ../src/calc-parse.cpp
                    ../src/calc-eval.cpp
)

add_executable(s_expr ../src/s_expr.cpp
                    ../src/calc-parse.cpp
                    ../src/calc-print/cpp
)

add_executable(post_fix ../src/post_fix.cpp
                    ../src/calc-parse.cpp
                    ../src/calc-print/cpp
)

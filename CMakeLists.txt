cmake_minimum_required(VERSION 3.0)
project(Kondra)

find_path(GMP_INCLUDE_DIR gmp.h)
find_library(GMP_LIBRARY gmp)

include_directories(${GMP_INCLUDE_DIR})

add_library(dynamic_integer types/libs/DynamicInteger.cpp)
add_library(variable types/libs/Variable.cpp)
add_executable(kondra main.cpp)

target_link_libraries(kondra variable dynamic_integer ${GMP_LIBRARY})

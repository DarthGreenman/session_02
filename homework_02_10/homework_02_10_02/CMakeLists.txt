
cmake_minimum_required(VERSION 3.22.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

project(homework_02_10_02)
set(SOURCE_EXE homework_02_10_02.cpp )

set(SOURCE_LIB_GEO lib/geo/Shape.cpp lib/geo/IShape.cpp)
add_library(lib_geo STATIC ${SOURCE_LIB_GEO})
add_executable(homework_02_10_02 ${SOURCE_EXE})
target_link_libraries(homework_02_10_02 lib_geo )
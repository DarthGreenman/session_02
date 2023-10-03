# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required(VERSION 3.22.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

project ("homework_02_11_03")

# Включите подпроекты.
add_subdirectory ("homework_02_11_03")
add_subdirectory("lib\geo")

set(SOURCE_EXE homework_02_10_03.cpp )

set(SOURCE_LIB_GEO lib/geo/Shape.cpp lib/geo/IShape.cpp)

add_library(lib_geo STATIC ${SOURCE_LIB_GEO})
add_executable(homework_02_10_03 ${SOURCE_EXE})

target_link_libraries(homework_02_10_02 lib_geo )
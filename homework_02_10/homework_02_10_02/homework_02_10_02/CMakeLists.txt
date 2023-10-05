# CMakeList.txt: проект CMake для homework_02_10_02; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

set(HEADER_INC "../includes/Localisation.h" "../includes/Types.h" "../includes/Triangle.h"  "../includes/Quadrangle.h")
set(SOURCE_INC "../includes/Shape.cpp")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (homework_02_10_02 "homework_02_10_02.cpp" ${HEADER_INC} ${SOURCE_INC})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET homework_02_10_02 PROPERTY CXX_STANDARD 20)
endif()
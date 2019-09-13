cmake_minimum_required(VERSION 3.14)
project(journey)

set(CMAKE_CXX_STANDARD 17)

add_executable(journey src/main.cpp)

include_directories(include/eigen-3.3.7)
include_directories(include/matplotlib-cpp)

add_subdirectory(src)

find_package(PythonLibs 2.7)
target_include_directories(journey PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(journey ${PYTHON_LIBRARIES})
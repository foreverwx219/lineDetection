cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(PROJECT_NAME lineDetection)

find_package(OpenCV REQUIRED)
include_directories(${OpneCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} lineDetection.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

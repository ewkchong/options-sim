cmake_minimum_required(VERSION 3.26.3)

project(options-sim)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB options-sim-files CONFIGURE_DEPENDS "./include/*.h" "./src/*.cpp")

add_executable(${PROJECT_NAME} ${options-sim-files})

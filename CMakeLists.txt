cmake_minimum_required(VERSION 3.26.3)

project(options-sim)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB options-sim-files CONFIGURE_DEPENDS "./include/*.h" "./src/*.cpp")
list(FILTER options-sim-files EXCLUDE REGEX "/Trader\\.cpp$")

file(GLOB client-files CONFIGURE_DEPENDS "./include/*.h" "./src/client/*.cpp")
list(FILTER client-files EXCLUDE REGEX "/main\\.cpp$")

add_executable(${PROJECT_NAME} ${options-sim-files})
add_executable(client ${client-files})

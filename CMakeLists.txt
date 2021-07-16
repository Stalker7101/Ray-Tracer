cmake_minimum_required(VERSION 3.0)
project(ray_tracing VERSION 0.1 LANGUAGES CXX)

file(GLOB CPPS_simp "src/*.cpp")
file(GLOB CPPS ${CPPS_simp})

include_directories(hdr)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} ${CPPS})

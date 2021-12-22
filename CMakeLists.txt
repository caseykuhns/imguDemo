cmake_minimum_required(VERSION 3.0.0)
project(imgui VERSION 0.1.0)

file(GLOB SRCS imgui/*.cpp imgui/*.h)
add_executable(DemoApp main.cpp ${SRCS})
target_include_directories(DemoApp PRIVATE imgui)

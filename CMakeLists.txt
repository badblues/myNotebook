cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(progress_bar main.cpp shared.cpp base.h shared.h)

cmake_minimum_required(VERSION 3.10)
project(Echipa)

set(CMAKE_CXX_STANDARD 14)

# Include directory
include_directories(inc)

# Adaugă sursele proiectului
add_executable(Echipa src/main.cpp src/Echipa.cpp)

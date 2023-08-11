cmake_minimum_required(VERSION 3.26)
project(GroupProjectCOP3530)
## not sure if I needed to add this here but am doing
set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GroupProjectCOP3530
        Conditions.cpp
        Conditions.h
        Main.cpp
        Maxheap.cpp
        Maxheap.h
        Patients.cpp
        Patients.h)

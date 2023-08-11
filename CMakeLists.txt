cmake_minimum_required(VERSION 3.26)
project(GroupProjectCOP3530)
## not sure if I needed to add this here but am doing so
set(CMAKE_CXX_STANDARD 14
        input1.txt
        input2.txt
        input3.txt
        input4.txt
        input5.txt)

include_directories(.
        input1.txt
        input2.txt
        input3.txt
        input4.txt
        input5.txt)

add_executable(GroupProjectCOP3530
        Conditions.cpp
        Conditions.h
        Main.cpp
        Maxheap.cpp
        Maxheap.h
        Patients.cpp
        Patients.h)

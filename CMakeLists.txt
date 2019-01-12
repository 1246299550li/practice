cmake_minimum_required(VERSION 3.13)
project(new)

set(CMAKE_CXX_STANDARD 17)

add_executable(new main.cpp Employee.cpp Employee.h RegularEmployee.cpp RegularEmployee.h TemporaryEmployee.cpp TemporaryEmployee.h Table.cpp Table.h)
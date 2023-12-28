cmake_minimum_required(VERSION 3.26)
project(bamush)

set(CMAKE_CXX_STANDARD 23)

add_executable(bamush src/shell/shell.cpp
src/shell/shell.h
src/command_handler/command_handler.cpp
        src/config/config_loader.cpp
src/config/config_loader.h
src/config/config_parser.cpp
src/config/config_parser.h)

cmake_minimum_required(VERSION 3.10.0)
project(lab_1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/main.cpp
    src/my_string.cpp
    src/utils.cpp
    src/program.cpp
    src/menus.cpp
)

set(HEADERS
    include/my_string.h
    include/utils.h   
    include/program.h 
    include/menus.h
)

add_executable(lab1 ${SOURCES} ${HEADERS})
cmake_minimum_required(VERSION 3.10.0)
project(lab_2 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/main.cpp
    src/string.cpp
    src/utils.cpp
    src/program.cpp
    src/menus.cpp
)

set(HEADERS
    include/string.h
    include/utils.h   
    include/program.h 
    include/menus.h
)

add_executable(lab_2 ${SOURCES} ${HEADERS})
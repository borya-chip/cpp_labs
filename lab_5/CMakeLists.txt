cmake_minimum_required(VERSION 3.10.0)
project(lab_5 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/main.cpp
    src/utils.cpp
)

set(HEADERS
    include/utils.h   
    include/program.h 
    include/myarray.h 
)

add_executable(lab_5 ${SOURCES} ${HEADERS})
cmake_minimum_required(VERSION 3.10.0)
project(lab_8 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/menu.cpp
    src/myexception.cpp
    src/main.cpp
)

set(HEADERS
    myalgorithm.h
    mycontainer.h
    myexception.h
    menu.h 
    myiterator.h
)

add_executable(lab_8 ${SOURCES})
set_property(TARGET lab_8 PROPERTY CXX_STANDARD 20)
set_property(TARGET lab_8 PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lab_8 PROPERTY CXX_EXTENSIONS OFF)
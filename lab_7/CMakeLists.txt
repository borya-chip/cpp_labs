cmake_minimum_required(VERSION 3.10.0)
project(lab_7 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/employee.cpp
    src/employeefinder.cpp
    src/main.cpp
    src/menu.cpp
    src/utils.cpp
    src/program.cpp
)

set(HEADERS
    include/employee.h   
    include/utils.h
    include/program.h
    include/menu.h 
    include/employeefinder.h
)

add_executable(lab_7 ${SOURCES} ${HEADERS})
set_property(TARGET lab_7 PROPERTY CXX_STANDARD 20)
set_property(TARGET lab_7 PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lab_7 PROPERTY CXX_EXTENSIONS OFF)
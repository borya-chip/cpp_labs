cmake_minimum_required(VERSION 3.10.0)
project(lab_6 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/date.cpp
    src/main.cpp
    src/menu.cpp
    src/myexception.cpp
    src/program.cpp
    src/utils.cpp
)

set(HEADERS
    include/date.h   
    include/date_digit_exception.h
    include/date_format_exception.h
    include/date_range_exception.h
    include/menu.h 
    include/utils.h
    include/program.h
    include/myexception.h 
)

add_executable(lab_6 ${SOURCES} ${HEADERS})
set_property(TARGET lab_6 PROPERTY CXX_STANDARD 20)
set_property(TARGET lab_6 PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lab_6 PROPERTY CXX_EXTENSIONS OFF)
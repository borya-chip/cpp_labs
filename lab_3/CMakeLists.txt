cmake_minimum_required(VERSION 3.10.0)
project(lab_3 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/main.cpp
    src/school_student.cpp
    src/university_student.cpp
    src/utils.cpp
    src/student.cpp
    src/program.cpp
    src/menus.cpp
)

set(HEADERS
    include/school_student.h
    include/utils.h   
    include/program.h 
    include/menus.h
    include/university_student.h
    include/student.h
)

add_executable(lab_3 ${SOURCES} ${HEADERS})


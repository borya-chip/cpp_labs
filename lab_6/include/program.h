#pragma once

#include "date.h"

class Program {
    Date date;
    void testConstructors();
    void testInputDate();
    void showCurrentDate();
    public:
    Program() = default;
    ~Program() = default;
    void run();
};

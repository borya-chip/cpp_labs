#pragma once

#include "date.h"

class Program {
    Date date;
    void testConstructors() const;
    void testInputDate();
    void showCurrentDate() const;
    public:
    Program() = default;
    ~Program() = default;
    void run();
};

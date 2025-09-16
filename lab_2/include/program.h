#pragma once
#include "string.h"

class Program {
    String str;

    void inputString();
    void showString() const;
    void encode();
    void decode();

  public:
    void run();
};
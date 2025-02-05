#pragma once

#include <iostream>

class prnt {

public:
    static void print(int x);
    static void print(double x);
    static void print(unsigned long long x);
    static void print(const std::string& x);
};




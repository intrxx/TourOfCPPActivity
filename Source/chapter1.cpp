#include <iostream>
#include <cstdint>
#include <complex>
#include <vector>

/*
void print(int x, double y){
    // This code will cause compiler error
}

void print(double x, int y){
    // This code will cause compiler error
}
*/

void print(int x){
    std::cout << x << "\n";
}

void print(double x){
    std::cout << x << "\n";
}

void print(unsigned long long x){
    std::cout << x << "\n";
}

void print(const std::string& x){
    std::cout << x << "\n";
}

double square(double x){
    return x*x;
}

void print_square(double x){
    std::cout << "Square of " << x << " is " << square(x) << "\n";
}

void chapter1(){
    std::cout << "\n";
    std::cout << "Chapter 1: \n";
    std::cout << "\n";
    std::cout << "Hello, Tour of C++\n";
    print_square(1.234);
    print(42);
    print(9.65);
    print("Barcelona");

    // print(0, 0); this call is ambiguous
    print(sizeof(char));
    print(sizeof(int));
    std::int32_t int32 = 31312;
    print(sizeof(int32));

    int binary = 0b101011001;
    print(binary);
    int hex = 0x52BA12F;
    print(hex);
    int octal = 03347;
    print(octal);

    double pi = 3.14159'26535'89793'23846'26433'83279'50288;
    print(pi);

    double d = 2.2;
    int i = 7;
    d = d+i;
    print(d);
    i = d+i;
    print(i);

    double d1 = 2.3;
    double d2 = {2.3};
    double d3 {2.3};
    std::complex<double> z1 = 1;
    std::complex<double> z2 = {d1, d2};
    std::complex<double> z3 {d1, d3};
    std::vector<int> v {1,2,3,4,5,6};

    // {} initialization prevents type conversion
    int i1 = 7.8; // will be type converted to 7
    // int i2 {7.8}; will cause type conversion error

    auto b = true;
    auto ch = 'x';
    auto ai = 123;
    auto ad = 1.2;
    auto z = square(i);
    auto bb {true};
    auto add {1.2354};
}

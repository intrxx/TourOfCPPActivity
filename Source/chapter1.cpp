#include <iostream>
#include <cstdint>
#include <complex>
#include <utility>
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

std::vector<int> global_vec;

struct Record {
    Record() = default;
    explicit Record(std::string in_name)
            : name(std::move(in_name))
    {}
    std::string name = "None";
};

void some_global_func(int with_local_arg){
    std::string local_string = "I'm local!";
    auto p = new Record("Hume");
    print(p->name);
    delete p;
}

double sum(const std::vector<double>& vec){
    double result = 0;
    for(double i : vec){
        result += i;
    }
    return result;
}

constexpr double constexpr_square(double x){
    return x*x;
}

consteval double consteval_square(double x){
    return x*x;
}

constexpr double nth(double x, int n){
    if(n < 0){
        return x;
    }

    double res = 1;
    int i = 0;
    while(i<n){
        res *= x;
        ++i;
    }
    return res;
}

int count_x(const char* p, char x){
    if(p == nullptr){
        return 0;
    }

    int count = 0;
    for(; *p != 0; ++p){ // will run until 0, ergo until null termination of p
        if(*p == x){
            ++count;
        }
    }

    // could use
    /*
    while(*p){ // will run until 0, ergo until null termination of p
        if(*p == x){
            ++count;
        }
        ++p;
    }
    */
    return count;
}

bool accept(){
    std::cout << "Do you want to continue (y or n)?\n";
    char answer = 0;

    std::cin >> answer;
    if(answer == 'y'){
        return true;
    }
    return false;
}

bool accept1(){
    std::cout << "Do you want to continue (y or n)?\n";
    char answer = 0;

    std::cin >> answer;
    switch (answer) {
        case 't':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "Will treat it like no. \n";
            return false;
    }
}

void chapter1(){

    // 1.2
    std::cout << "\n";
    std::cout << "Chapter 1: \n";
    std::cout << "\n";
    std::cout << "Hello, Tour of C++\n";

    // 1.3
    print_square(1.234);
    print(42);
    print(9.65);
    print("Barcelona");

    // print(0, 0); this call is ambiguous

    // 1.4
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

    // 1.4.1
    double d = 2.2;
    int i = 7;
    d = d+i;
    print(d);
    i = d+i;
    print(i);

    // 1.4.2
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

    // 1.5
    some_global_func(1);

    // 1.6
    constexpr int dmv = 17;
    int var = 17;
    const double sqv = sqrt(var);

    std::vector<double> v2 {1.2, 3.4, 4.5};
    const double s1 = sum(v2);
    // constexpr double s2 = sum(v2); // this is cause compiler error because sum isn't constant expression
    constexpr double max1 = 1.4 * constexpr_square(17);
    // constexpr double max2 = 1.4 * constexpr_square(var); // this expression isn't constant, var isn't a constant expression
    const double max3 = 1.4 * constexpr_square(var); // this is okay because we can call constexpr functions without constant values
    constexpr double max4 = 1.4 * consteval_square(17);
    // const double max5 = 1.4 * consteval_square(var); // this is not okay, consteval forces us to use constant values and var isn't constant
    constexpr double res = nth(15, 5);
    print(res);

    // 1.7
    char arr[6] = {1, 2, 3, 4, 5, 6};
    char* p = &arr[3];
    char value_p = *p;
    print(value_p);

    int arr1[] = {0, 1, 2, 3, 4, 5};
    for(auto& x : arr1){
        ++x;
    }

    for(auto x : arr1){
        std::cout << x << "\n";
    }

    for(auto x : {5, 4, 3, 2, 1}){
        std::cout << x << "\n";
    }

    double* pd = nullptr;
    // int x = nullptr; nullptr is a pointer type

    const char* pp = "Hello tour of cpp";
    int res1 = count_x(pp, 'p');
    print(res1);

    accept();

    int xx = 7;
    int& rr {xx};
    print(rr);
    rr = 8;
    print(xx);

    // int& r2; references require initialization
}

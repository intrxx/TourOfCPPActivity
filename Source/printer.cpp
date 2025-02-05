#include <string>

#include "printer.h"

void prnt::print(int x) {
    std::cout << x << "\n";
}

void prnt::print(double x) {
    std::cout << x << "\n";
}

void prnt::print(unsigned long long int x) {
    std::cout << x << "\n";
}

void prnt::print(const std::string& x) {
    std::cout << x << "\n";
}

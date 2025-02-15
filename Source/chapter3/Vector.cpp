//
// Created by iwni on 09-Feb-25.
//

#include "Vector.h"

Vector::Vector(int s)
        : elem{new double [s]}
        , sz{s} {
}

Vector::~Vector() {
    delete[] elem;
}

double& Vector::operator[](int i) {
    return elem[i];
}

int Vector::size() const {
    return sz;
}

#pragma once

class Vector {
public:
    explicit Vector(int s);
    ~Vector();

    double& operator[](int i);

    [[nodiscard]] int size() const;
private:
    double* elem;
    int sz;
};




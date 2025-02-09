#include <iostream>
#include <variant>

#include "../printer.h"
#include "../chapter3/Vector.h"

enum class Type
{
    ptr,
    num
};

struct Node {
    int g;
};

// Non-union struct, p and i is never used so memory is wasted
struct Entry {
    std::string name;
    Type t;
    Node* p;
    int i;
};

void ff(Entry* e){
    if(e->t == Type::num){
        prnt::print(e->i);
    }
}

// Union type, node and i are allocated at the same memory address
union Value {
    Node* n;
    int i;
};

struct UpgradedEntry {
    std::string name;
    Type t;
    Value v;
};

void fff(UpgradedEntry* ue){
    if(ue->t == Type::num){
        prnt::print(ue->v.i);
    }
}

struct EntryLastForm {
    std::string name;
    std::variant<Node*, int> v;
};

void ffff(EntryLastForm* elf){
    if(std::holds_alternative<int>(elf->v)){
        prnt::print(std::get<int>(elf->v));
    }
}

enum Color {
    red,
    green,
    blue
};

enum class RGB_color {
    red,
    green,
    blue
};

enum class Traffic_light {
    green,
    yellow,
    red
};

Traffic_light& operator++(Traffic_light& t){
    using enum Traffic_light;

    switch(t){
        case red:
            return t = green;
        case green:
            return t = yellow;
        case yellow:
            return t = red;
        default:
            throw std::logic_error("Invalid Traffic_light value");
    }
}

/*
class Vector {
public:
    explicit Vector(int s)
    : elem{new double [s]}
    , sz{s}
    {}

    ~Vector(){
        delete[] elem;
    }

    double& operator[](int i){
        return elem[i];
    }

    [[nodiscard]] int size() const {
        return sz;
    }
private:
    double* elem;
    int sz;
};
 */

/*
void vector_init(Vector& v, int s){
    v.elem = new double[s];
    v.sz = s;
}
 */

double read_and_sum(int s){
    if(s <= 0){
        return 0;
    }
    Vector v(s - 1);

    prnt::print("Provide numbers: ");
    for(int i = 0; i <= v.size(); ++i){
        std::cin >> v[i];
    }

    double sum = 0;
    for(int i = 0; i <= v.size(); ++i){
        sum += v[i];
    }
    return sum;
}

void f(Vector v, Vector& rv, Vector* pv){
    int i1 = v.size();
    int i2 = rv.size();
    int i3 = pv->size();
}

void chapter2(){
    // 2.2
    //Vector v{};
    prnt::print(read_and_sum(2));

    // 2.3 Changed Vector form struct to class
    Vector(6);

    // 2.4
    RGB_color col = RGB_color::red;
    Traffic_light light = Traffic_light::red;

    //RGB_color x1 = red; // wdym red?
    //RGB_color y2 = Traffic_light::red; // error cannot initialize RGB_Color with Traffic_light::red
    RGB_color x2 = RGB_color::red;
    auto x4 = RGB_color::red;
    //int i = RGB_color::red;
    //RGB_color i2 = 2; // not ok
    RGB_color i3 = RGB_color{2};
    RGB_color i4 {6};
    int x = int(RGB_color::red);

    Traffic_light trafficLight = Traffic_light::green;
    prnt::print(static_cast<double>(trafficLight));
    ++trafficLight;
    prnt::print(static_cast<double>(trafficLight));

    int bluevar = blue;
    prnt::print(bluevar);

    // 2.5
    EntryLastForm elf {"as", 69};
    ffff(&elf);
};

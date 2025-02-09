#include "printer.h"

void chapter1();
void chapter2();
void chapter3();

void displayChapter(){
    prnt::print("Choose which chapter to display: ");

    int option = 0;
    std::cin >> option;

    switch (option) {
        case 1:
            chapter1();
            break;
        case 2:
            chapter2();
            break;
        case 3:
            chapter3();
            break;
        default:
            prnt::print("Provided wrong number, exiting.");
            break;
    }
}

int main(){
   displayChapter();
}




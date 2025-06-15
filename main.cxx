//useless imports in final program
#include "colors.h"
#include "wall.h"

//useful imports in final program
#include <iostream>

using namespace std;

int main() {
    cout<<"Helou cube!\n";
    Wall w1(color::white, color::red, color::blue,
            color::green, color::yellow, color::orange,
            color::green, color::yellow, color::red);
    w1.print_wall();
    w1.rotate_left2();
    cout<<endl;
    w1.print_wall();
    return 0;
}
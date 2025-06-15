// in /build
// cmake .. -G "Unix Makefiles"
// make

//useless imports in final program
#include "colors.h"
#include "wall.h"

//useful imports in final program
#include <iostream>

using namespace std;

int main() {
    cout<<"Helou cube!\n";
    Wall w1(Color::white, Color::red,    Color::blue,
            Color::green, Color::yellow, Color::orange,
            Color::green, Color::yellow, Color::red);
    w1.print_wall();
    w1.rotate_left2();
    cout<<endl;
    w1.print_wall();
    return 0;
}
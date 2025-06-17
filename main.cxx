// in /build
// WINDOWS cmake .. -G "Unix Makefiles" 
// OTHER cmake ..
// make

//useless imports in final program
#include "colors.h"
#include "wall.h"
#include "cube.h"

//useful imports in final program
#include <iostream>

using namespace std;


int main() {
    cout<<"Helou cube!\n";
    Wall w1(Color::white, Color::red,    Color::blue,
            Color::green, Color::yellow, Color::orange,
            Color::green, Color::yellow, Color::red);

    Cube mi;
    mi.user_input_wall("front");
    mi.user_input_wall("up");
    mi.user_input_wall("right");
    mi.user_input_wall("left");
    mi.user_input_wall("down");
    mi.user_input_wall("back");
    mi.print_cube();
    mi.white_layer_down();

    return 0;
}
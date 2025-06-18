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

    mi.white_layer_down();
    mi.white_cross();
    
    mi.print_cube();

    return 0;
}


// R y LP UP x RP F L xp U R U2 Fp Up

// wrgbrboyr
// yrroyrbby
// ogwoggwgr
// rgoobyybg
// wobwwwbrg
// gwbyowyyo
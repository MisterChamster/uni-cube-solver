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

    Cube solvd_qb;

    Cube mi;
    mi.user_input_all_walls();

    mi.white_layer_down();
    mi.solve_white_cross();
    cout<<endl;
    mi.solve_white_layer();

    mi.print_cube();

    // if(solvd_qb.is_white_cross()) cout<<"FUUUUUUCK YOUUUUUUUUU"<<endl;
    // if(solvd_qb.is_white_layer()) cout<<"FUUUUUUCK YOUUUUUUUUU"<<endl;
    // if(solvd_qb.is_f2l()) cout<<"FUUUUUUCK YOUUUUUUUUU"<<endl;
    // if(solvd_qb.is_yellow_cross()) cout<<"FUUUUUUCK YOUUUUUUUUU"<<endl;
    // if(solvd_qb.is_solved()) cout<<"FUUUUUUCK YOUUUUUUUUU"<<endl;

    return 0;
}


// R y LP UP x RP F L xp U R U2 Fp Up

// wrgbrboyr
// yrroyrbby
// ogwoggwgr
// rgoobyybg
// wobwwwbrg
// 

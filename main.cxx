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
    // Wall w1(Color::white, Color::red,    Color::blue,
    //         Color::green, Color::yellow, Color::orange,
    //         Color::green, Color::yellow, Color::red);

    Cube solvd_qb;

    Cube mi;
    mi.user_input_all_walls();

    mi.white_layer_down();
    cout<<endl;
    mi.solve_white_cross();
    cout<<endl;
    mi.solve_white_layer();
    cout<<endl;
    mi.solve_f2l();
    cout<<endl;
    mi.solve_yellow_cross();
    cout<<endl;
    mi.solve_yellow_cross_orientation();
    cout<<endl;
    mi.solve_yellow_corners_placing();
    cout<<endl;
    mi.z2();
    cout<<endl;
    mi.yellow_corners_orientation();
    cout<<endl;

    mi.print_cube();

    return 0;
}


// R y Lp Up x Rp F L xp U R U2 Fp Up

// wrgbrboyr
// yrroyrbby
// ogwoggwgr
// rgoobyybg
// wobwwwbrg
// gwbyowyyo


// U Rp x F Lp U F D L R B 

// bgyowbbbo
// oyobbgwog
// rygwrwgrb
// borwowrry
// oyybgggyr
// wrwrygyow

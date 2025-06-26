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

    // Cube solvd_qb;

    Cube mi;
    mi.solve();

    // mi.print_cube();

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


// R yp L F D B L Fp Up

// rbyyogwrg
// oyowyygrr
// bowobwyog
// yryrggwwr
// byoowbggr
// bbbbrgwwo


//sp
// brbwbwgog
// oboyyyobo
// yrybrbwow
// wowgogyry
// rgrwwwrgr
// gogygybrb


// mf
// bgyrobryw
// oygobwowb
// ooywwgror
// gbwyywory
// bogbggwyb
// rgyrrbwrg
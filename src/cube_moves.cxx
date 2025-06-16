#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>

using namespace std;

// ======================================
// =============== Basic ================
// ======================================
void Cube::F(){
    cout<<"F ";
    wall_front.rotate_right();

    Color temp1, temp2, temp3;
    temp1 = wall_up.dl;
    temp2 = wall_up.dm;
    temp3 = wall_up.dr;

    wall_up.dl = wall_left.dr;
    wall_up.dm = wall_left.mr;
    wall_up.dr = wall_left.tr;

    wall_left.dr = wall_down.tr;
    wall_left.mr = wall_down.tm;
    wall_left.tr = wall_down.tl;

    wall_down.tr = wall_right.tl;
    wall_down.tm = wall_right.ml;
    wall_down.tl = wall_right.dl;

    wall_right.tl = temp1;
    wall_right.ml = temp2;
    wall_right.dl = temp3;

};
void Cube::R(){
    cout<<"R ";

};
void Cube::L(){
    cout<<"L ";
    
};
void Cube::U(){
    cout<<"U ";
    
};
void Cube::D(){
    cout<<"D ";
    
};

// void Cube::B(){};



// =====================================
// ============== Reverse ==============
// =====================================
void Cube::Fp(){
    cout<<"Fp ";
};
void Cube::Rp(){
    cout<<"Rp ";
};
void Cube::Lp(){
    cout<<"Lp ";
};
void Cube::Up(){
    cout<<"Up ";
};
void Cube::Dp(){
    cout<<"Dp ";
};

// void Cube::Bp(){};



// ======================================
// ============= Cube moves =============
// ======================================
// void Cube::x(){};

void Cube::y(){
    cout<<"y ";
};
void Cube::z(){
    cout<<"z ";
};



// ======================================
// ========= Reverse cube moves =========
// ======================================
// void Cube::xp(){};

void Cube::yp(){
    cout<<"yp ";
};
void Cube::zp(){
    cout<<"zp ";
};
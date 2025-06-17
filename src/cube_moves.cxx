#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>

using namespace std;


// ======================================
// =============== Basic ================
// ======================================
void Cube::F() {
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
void Cube::R() {
    cout<<"R ";
    wall_right.rotate_right();

    Color temp1, temp2, temp3;
    temp1 = wall_up.dr;
    temp2 = wall_up.mr;
    temp3 = wall_up.tr;
 
    wall_up.dr = wall_front.dr;
    wall_up.mr = wall_front.mr;
    wall_up.tr = wall_front.tr;

    wall_front.dr = wall_down.dr;
    wall_front.mr = wall_down.mr;
    wall_front.tr = wall_down.tr;

    wall_down.dr = wall_back.tr;
    wall_down.mr = wall_back.ml;
    wall_down.tr = wall_back.dl;

    wall_back.tr = temp1;
    wall_back.ml = temp2;
    wall_back.dl = temp3;
    
};
void Cube::L() {
    cout<<"L ";
    wall_left.rotate_right();
 
    Color temp1, temp2, temp3;
    temp1 = wall_up.tl;
    temp2 = wall_up.ml;
    temp3 = wall_up.dl;

    wall_up.tl = wall_back.dr;
    wall_up.ml = wall_back.mr;
    wall_up.dl = wall_back.tr;

    wall_back.dr = wall_down.tl;
    wall_back.mr = wall_down.ml;
    wall_back.tr = wall_down.dl;
    
    wall_down.tl = wall_front.tl;
    wall_down.ml = wall_front.ml;
    wall_down.dl = wall_front.dl;

    wall_front.tl = temp1;
    wall_front.ml = temp2;
    wall_front.dl = temp3;
    
};
void Cube::U() {
    cout<<"U "; // fuck why "up" and not "top" ??????
    // It's because it's a "U" move, not "T" move. 
    // Why in hell would it be named "top"?? Wtf
    // you have no fucking idea what ur talking about :(
    wall_up.rotate_right();
 
    Color temp1, temp2, temp3;
    temp1 = wall_front.tl;
    temp2 = wall_front.tm;
    temp3 = wall_front.tr;

    wall_front.tl = wall_right.tl;
    wall_front.tm = wall_right.tm;
    wall_front.tr = wall_right.tr;
 
    wall_right.tl = wall_back.tl;
    wall_right.tm = wall_back.tm;
    wall_right.tr = wall_back.tr;

    wall_back.tl = wall_left.tl;
    wall_back.tm = wall_left.tm;
    wall_back.tr = wall_left.tr;

    wall_left.tl = temp1;
    wall_left.tm = temp2;
    wall_left.tr = temp3;
    
};
void Cube::D() {
    cout<<"D ";
    wall_up.rotate_right();
 
    Color temp1, temp2, temp3;
    temp1 = wall_front.dl;
    temp2 = wall_front.dm;
    temp3 = wall_front.dr;

    wall_front.dl = wall_left.dl;
    wall_front.dm = wall_left.dm;
    wall_front.dr = wall_left.dr;
 
    wall_left.dl = wall_back.dl;
    wall_left.dm = wall_back.dm;
    wall_left.dr = wall_back.dr;

    wall_back.dl = wall_right.dl;
    wall_back.dm = wall_right.dm;
    wall_back.dr = wall_right.dr;

    wall_right.dl = temp1;
    wall_right.dm = temp2;
    wall_right.dr = temp3;
    
};

// void Cube::B(){};



// =====================================
// ============== Reverse ==============
// =====================================
void Cube::Fp() {
    cout<<"Fp ";
    wall_front.rotate_left();

    Color temp1, temp2, temp3;
    temp1 = wall_up.dl;
    temp2 = wall_up.dm;
    temp3 = wall_up.dr;

    wall_up.dl = wall_right.tl;
    wall_up.dm = wall_right.ml;
    wall_up.dr = wall_right.dl;

    wall_right.tl = wall_down.tr;
    wall_right.ml = wall_down.tm;
    wall_right.dl = wall_down.tl;

    wall_down.tr = wall_left.dr;
    wall_down.tm = wall_left.mr;
    wall_down.tl = wall_left.tr;

    wall_left.dr = temp1;
    wall_left.mr = temp2;
    wall_left.tr = temp3;
};
void Cube::Rp() {
    cout<<"Rp ";//Rzeczpospolita Polska
    wall_right.rotate_left();

    Color temp1, temp2, temp3;
    temp1 = wall_up.dr;
    temp2 = wall_up.mr;
    temp3 = wall_up.tr;
 
    wall_up.dr = wall_back.tr;
    wall_up.mr = wall_back.ml;
    wall_up.tr = wall_back.dl;

    wall_back.tr = wall_down.dr;
    wall_back.ml = wall_down.mr;
    wall_back.dl = wall_down.tr;

    wall_down.dr = wall_front.dr;
    wall_down.mr = wall_front.mr;
    wall_down.tr = wall_front.tr;

    wall_front.dr = temp1;
    wall_front.mr = temp2;
    wall_front.tr = temp3;
};
void Cube::Lp() {
    cout<<"Lp ";
    wall_left.rotate_left();
 
    Color temp1, temp2, temp3;
    temp1 = wall_up.tl;
    temp2 = wall_up.ml;
    temp3 = wall_up.dl;

    wall_up.tl = wall_front.tl;
    wall_up.ml = wall_front.ml;
    wall_up.dl = wall_front.dl;

    wall_front.tl = wall_down.tl;
    wall_front.ml = wall_down.ml;
    wall_front.dl = wall_down.dl;
    
    wall_down.tl = wall_back.dr;
    wall_down.ml = wall_back.mr;
    wall_down.dl = wall_back.tr;

    wall_back.dr = temp1;
    wall_back.mr = temp2;
    wall_back.tr = temp3;
};
void Cube::Up() {
    cout<<"Up ";
    wall_up.rotate_left();
 
    Color temp1, temp2, temp3;
    temp1 = wall_front.tl;
    temp2 = wall_front.tm;
    temp3 = wall_front.tr;

    wall_front.tl = wall_left.tl;
    wall_front.tm = wall_left.tm;
    wall_front.tr = wall_left.tr;

    wall_left.tl = wall_back.tl;
    wall_left.tm = wall_back.tm;
    wall_left.tr = wall_back.tr;

    wall_back.tl = wall_right.tl;
    wall_back.tm = wall_right.tm;
    wall_back.tr = wall_right.tr;

    wall_right.tl = temp1;
    wall_right.tm = temp2;
    wall_right.tr = temp3;
    
};
void Cube::Dp() {
    cout<<"Dp ";
    wall_up.rotate_left();
 
    Color temp1, temp2, temp3;
    temp1 = wall_front.dl;
    temp2 = wall_front.dm;
    temp3 = wall_front.dr;

    wall_front.dl = wall_right.dl;
    wall_front.dm = wall_right.dm;
    wall_front.dr = wall_right.dr;
 
    wall_right.dl = wall_back.dl;
    wall_right.dm = wall_back.dm;
    wall_right.dr = wall_back.dr;

    wall_back.dl = wall_left.dl;
    wall_back.dm = wall_left.dm;
    wall_back.dr = wall_left.dr;

    wall_left.dl = temp1;
    wall_left.dm = temp2;
    wall_left.dr = temp3;
};

// void Cube::Bp(){};



// ======================================
// ============= Cube moves =============
// ======================================
void Cube::x() {};

void Cube::y() {
    cout<<"y ";
};
void Cube::z() {
    cout<<"z ";
};



// ======================================
// ========= Reverse cube moves =========
// ======================================
void Cube::xp() {};

void Cube::yp() {
    cout<<"yp ";
};
void Cube::zp() {
    cout<<"zp ";
};
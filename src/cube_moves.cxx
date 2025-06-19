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
}

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

    wall_down.dr = wall_back.tl;
    wall_down.mr = wall_back.ml;
    wall_down.tr = wall_back.dl;

    wall_back.tl = temp1;
    wall_back.ml = temp2;
    wall_back.dl = temp3;
}

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
}

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
}

void Cube::D() {
    cout<<"D ";
    wall_down.rotate_right();
 
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
}

void Cube::B(){
    cout<<"B ";
    wall_back.rotate_right();

    Color temp1, temp2, temp3;
    temp1 = wall_up.tl;
    temp2 = wall_up.tm;
    temp3 = wall_up.tr;

    wall_up.tl = wall_right.tr;
    wall_up.tm = wall_right.mr;
    wall_up.tr = wall_right.dr;

    wall_right.tr = wall_down.dr;
    wall_right.mr = wall_down.dm;
    wall_right.dr = wall_down.dl;

    wall_down.dr = wall_left.dl;
    wall_down.dm = wall_left.ml;
    wall_down.dl = wall_left.tl;

    wall_left.dl = temp1;
    wall_left.ml = temp2;
    wall_left.tl = temp3;
}



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
}

void Cube::Rp() {
    cout<<"Rp ";//Rzeczpospolita Polska
    wall_right.rotate_left();

    Color temp1, temp2, temp3;
    temp1 = wall_up.dr;
    temp2 = wall_up.mr;
    temp3 = wall_up.tr;
 
    wall_up.dr = wall_back.tl;
    wall_up.mr = wall_back.ml;
    wall_up.tr = wall_back.dl;

    wall_back.tl = wall_down.dr;
    wall_back.ml = wall_down.mr;
    wall_back.dl = wall_down.tr;

    wall_down.dr = wall_front.dr;
    wall_down.mr = wall_front.mr;
    wall_down.tr = wall_front.tr;

    wall_front.dr = temp1;
    wall_front.mr = temp2;
    wall_front.tr = temp3;
}

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
}

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
}

void Cube::Dp() {
    cout<<"Dp ";
    wall_down.rotate_left();
 
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
}

void Cube::Bp(){
    cout<<"Bp ";
    wall_back.rotate_left();

    Color temp1, temp2, temp3;
    temp1 = wall_up.tl;
    temp2 = wall_up.tm;
    temp3 = wall_up.tr;

    wall_up.tl = wall_left.dl;
    wall_up.tm = wall_left.ml;
    wall_up.tr = wall_left.tl;

    wall_left.dl = wall_down.dr;
    wall_left.ml = wall_down.dm;
    wall_left.tl = wall_down.dl;

    wall_down.dr = wall_right.tr;
    wall_down.dm = wall_right.mr;
    wall_down.dl = wall_right.dr;

    wall_right.tr = temp1;
    wall_right.mr = temp2;
    wall_right.dr = temp3;
}



// ======================================
// ============= Cube moves =============
// ======================================
void Cube::x() {
    cout<<"x ";
    wall_right.rotate_right();
    wall_left.rotate_left();

    Wall temp = wall_up;
    wall_up = wall_front;
    wall_front = wall_down;

    wall_back.rotate_2();
    wall_down = wall_back;

    temp.rotate_2();
    wall_back = temp;
}

void Cube::y() {
    cout<<"y ";
    wall_up.rotate_right();
    wall_down.rotate_left();

    Wall temp = wall_front;
    wall_front = wall_right;
    wall_right = wall_back;
    wall_back = wall_left;
    wall_left = temp;
}

void Cube::z() {
    cout<<"z ";
    wall_front.rotate_right();
    wall_back.rotate_left();

    Wall temp = wall_up;
    wall_up = wall_left;
    wall_up.rotate_right();

    wall_left = wall_down;
    wall_left.rotate_right();

    wall_down = wall_right;
    wall_down.rotate_right();

    wall_right = temp;
    wall_right.rotate_right();
}



// ======================================
// ========= Reverse cube moves =========
// ======================================
void Cube::xp() {
    cout<<"xp ";  
    wall_right.rotate_left();
    wall_left.rotate_right();

    Wall temp = wall_up;

    wall_back.rotate_2();
    wall_up = wall_back;

    wall_down.rotate_2();
    wall_back = wall_down;

    wall_down = wall_front;
    wall_front = temp;

    //temp.rotate_2();
}

void Cube::yp() {
    cout<<"yp ";
    wall_up.rotate_left();
    wall_down.rotate_right();

    Wall temu = wall_front; //mu
    wall_front = wall_left;
    wall_left = wall_back;
    wall_back = wall_right;
    wall_right = temu;
}

void Cube::zp() {
    cout<<"zp ";
    wall_front.rotate_left();
    wall_back.rotate_right();

    Wall temp = wall_up;
    wall_up = wall_right;
    wall_up.rotate_left();

    wall_right = wall_down;
    wall_right.rotate_left();

    wall_down = wall_left;
    wall_down.rotate_left();

    wall_left = temp;
    wall_left.rotate_left();
}



// =====================================
// ============== 2-moves ==============
// =====================================
void Cube::F2() {
    cout<<"F2 ";
    for(int i=0; i<2; i++) {
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
    }
}

void Cube::R2() {
    cout<<"R2 ";
    for(int i=0; i<2; i++) {
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

        wall_down.dr = wall_back.tl;
        wall_down.mr = wall_back.ml;
        wall_down.tr = wall_back.dl;

        wall_back.tl = temp1;
        wall_back.ml = temp2;
        wall_back.dl = temp3;
    }
}

void Cube::L2() {
    cout<<"L2 ";
    for(int i=0; i<2; i++) {
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
    }
}

void Cube::U2() {
    cout<<"U2 ";
    for(int i=0; i<2; i++) {
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
    }
}

void Cube::D2() {
    cout<<"D2 ";
    for(int i=0; i<2; i++) {
        wall_down.rotate_right();
    
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
    }
}

void Cube::B2() {
    cout<<"B2 ";
    for(int i=0; i<2; i++) {
        wall_back.rotate_right();

        Color temp1, temp2, temp3;
        temp1 = wall_up.tl;
        temp2 = wall_up.tm;
        temp3 = wall_up.tr;

        wall_up.tl = wall_right.tr;
        wall_up.tm = wall_right.mr;
        wall_up.tr = wall_right.dr;

        wall_right.tr = wall_down.dr;
        wall_right.mr = wall_down.dm;
        wall_right.dr = wall_down.dl;

        wall_down.dr = wall_left.dl;
        wall_down.dm = wall_left.ml;
        wall_down.dl = wall_left.tl;

        wall_left.dl = temp1;
        wall_left.ml = temp2;
        wall_left.tl = temp3;
    }
}


void Cube::x2() {
    cout<<"x2 ";
    for(int i=0; i<2; i++) {
        wall_right.rotate_right();
        wall_left.rotate_left();

        Wall temp = wall_up;
        wall_up = wall_front;
        wall_front = wall_down;

        wall_back.rotate_2();
        wall_down = wall_back;

        temp.rotate_2();
        wall_back = temp;
    }
}

void Cube::y2() {
    cout<<"y2 ";
    for(int i=0; i<2; i++) {
        wall_up.rotate_right();
        wall_down.rotate_left();

        Wall temp = wall_front;
        wall_front = wall_right;
        wall_right = wall_back;
        wall_back = wall_left;
        wall_left = temp;
    }
}

void Cube::z2() {
    cout<<"z2 ";
    for(int i=0; i<2; i++) {
        wall_front.rotate_right();
        wall_back.rotate_left();

        Wall temp = wall_up;
        wall_up = wall_left;
        wall_up.rotate_right();

        wall_left = wall_down;
        wall_left.rotate_right();

        wall_down = wall_right;
        wall_down.rotate_right();

        wall_right = temp;
        wall_right.rotate_right();
    }
}



// ======================================
// =========== Move sequences ===========
// ======================================

void Cube::corner_down_white_front_tr() {
    Fp();
    Up();
    F();
}

void Cube::corner_down_white_right_tl() {
    R();
    U();
    Rp();
}

void Cube::corner_down_white_up_dr() {
    R();
    U2();
    Rp();
    Up();
    corner_down_white_right_tl();
}

void Cube::f2l_right() {
    U();
    R();
    Up();
    Rp();
    Up();
    Fp();
    U();
    F();
}

void Cube::f2l_left() {
    Fp();
    Lp();
    F();
    U();
    F();
    Up();
    Fp();
    L();
}

void Cube::f2l_right_from_left_layer() {
    R();
    Up();
    Rp();
    Up();
    Fp();
    U();
    F();
}

void Cube::f2l_left_from_right_layer() {
    Rp();
    Fp();
    R();
    U();
    R();
    Up();
    Rp();
    F();
}

void Cube::f2l_reverse() {
    Rp();
    F();
    R();
    Fp();

    R();
    Up();
    Rp();
    U();
    R();
    Up();
    Rp();
    U2();
    R();
    Up();
    Rp();
}

void Cube::RURU() {
    R();
    U();
    Rp();
    Up();
}

void Cube::RURU2() {
    RURU();
    RURU();
}

void Cube::yellow_cross_1s() {
    F();
    RURU();
    Fp();
}

void Cube::yellow_cross_2s() {
    F();
    RURU2();
    Fp();
}

void Cube::yellow_cross_orient_sequence() {
    Up();
    R();
    U2();
    Rp();
    Up();
    R();
    Up();
    Rp();
}

void Cube::yellow_cross_orient_sequence_no_Up() {
    R();
    U2();
    Rp();
    Up();
    R();
    Up();
    Rp();
}

void Cube::yellow_cross_orient_sequence_U2() {
    U2();
    R();
    U2();
    Rp();
    Up();
    R();
    Up();
    Rp();
}

void Cube::yellow_cross_orient_sequence_U() {
    U();
    R();
    U2();
    Rp();
    Up();
    R();
    Up();
    Rp();
}

void Cube::yellow_corners_orient_sequence() {
    U();
    R();
    Up();
    Lp();
    U();
    Rp();
    Up();
    L();
}

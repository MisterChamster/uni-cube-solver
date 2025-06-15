#include "wall.h"
#include "colors.h"
#include <iostream>



Wall::Wall(Color tl, Color tm, Color tr,
           Color ml, Color mm, Color mr,
           Color dl, Color dm, Color dr) {
    this->tl = tl;
    this->tm = tm;
    this->tr = tr;
    this->ml = ml;
    this->mm = mm;
    this->mr = mr;
    this->dl = dl;
    this->dm = dm;
    this->dr = dr;
}

Wall::Wall(Color c) {
    this->tl = c;
    this->tm = c;
    this->tr = c;
    this->ml = c;
    this->mm = c;
    this->mr = c;
    this->dl = c;
    this->dm = c;
    this->dr = c;
}


void Wall::print_wall() {
    std::cout<<" "<<tl<<" "<<tm<<" "<<tr<<std::endl;
    std::cout<<" "<<ml<<" "<<mm<<" "<<mr<<std::endl;
    std::cout<<" "<<dl<<" "<<dm<<" "<<dr<<std::endl;
}

// Rotates colors clockerwise.
// Equivalent to color rotation done with F move on front wall.
void Wall::rotate_right() {
    Color temp;
    temp = tl;
    tl = dl;
    dl = dr;
    dr = tr;
    tr = temp;

    temp = tm;
    tm = ml;
    ml = dm;
    dm = mr;
    mr = temp;
}

// Rotates colors counter-clockerwise.
// Equivalent to color rotation done with F' move on front wall.
void Wall::rotate_left() {
    Color temp;
    temp = tl;
    tl = tr;
    tr = dr;
    dr = dl;
    dl = temp;

    temp = tm;
    tm = mr;
    mr = dm;
    dm = ml;
    ml = temp;
}

// Rotates colors by 180 deg.
// Equivalent to color rotation done with 2F move on front wall.
void Wall::rotate_2() {
    rotate_right();
    rotate_right();
}

// Checks if the cube is one-color.
// NEEDS IMPLEMENTING
bool is_one_color(){
    return false;
}

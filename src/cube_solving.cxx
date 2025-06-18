#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>



void Cube::white_layer_down() {
    if     (wall_up.mm    == Color::white) {z(); z();}
    else if(wall_front.mm == Color::white)  xp();
    else if(wall_right.mm == Color::white)  z();
    else if(wall_left.mm  == Color::white)  zp();
    else if(wall_back.mm  == Color::white)  x();
}

//assuming white mm is on wall_down
void Cube::white_cross_edge() {
    //if white wall is on bottom
    if(wall_down.mm == Color::white) {
        Color front_color = wall_front.mm;
        //if edge not in the right place
        if(wall_down.tm != Color::white || wall_front.dm != front_color) {
            //bad orientation
            if (wall_down.tm == front_color || wall_front.dm == Color::white) {
                Fp();
                R();
                U();
                Rp();
                //F2();
            }
        }
    }
    return;
}

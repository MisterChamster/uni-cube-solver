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

void Cube::white_cross_edge(Color second_color) {
    return;
}

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
        if(wall_front.dm != front_color || wall_down.tm != Color::white) {

            // =========================================================
            // ================== White on front wall ==================
            // =========================================================
            if(wall_front.dm == Color::white && wall_down.tm == front_color) {
                Fp();
                R();
                U();
                Rp();
                F2();
            }
            else if(wall_front.mr == Color::white && wall_right.ml == front_color) {
                R();
                U();
                Rp();
                F2();
            }
            else if(wall_front.ml == Color::white && wall_left.mr == front_color) {
                Lp();
                Up();
                L();
                F2();
            }
            else if(wall_front.tm == Color::white && wall_up.dm == front_color) {
                Up();
                Rp();
                F();
                R();
            }

            // =========================================================
            // ================= Front col on front wall ===============
            // =========================================================
            else if(wall_front.mr == front_color && wall_right.ml == Color::white) {
                F();
            }
            else if(wall_front.ml == front_color && wall_left.mr == Color::white) {
                Fp();
            }
            else if(wall_front.tm == front_color && wall_up.dm == Color::white) {
                F2();
            }

            // ========================================================
            // =================== White on down wall =================
            // ========================================================
            else if(wall_down.mr == Color::white && wall_right.dm == front_color) {
                R();
                D();
                Rp();
                Dp();
            }
            else if(wall_down.ml == Color::white && wall_left.dm == front_color) {
                L();
                Dp();
                Lp();
                D();
            }
            else if(wall_down.dm == Color::white && wall_back.dm == front_color) {
                D2();
                F();
                D2();
                Fp();
            }

        }
    }
    return;
}

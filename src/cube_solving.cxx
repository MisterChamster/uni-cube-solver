#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>



void Cube::white_cross_edge() {
    // If white mm is not on bottom - return
    if(wall_down.mm != Color::white) return;

    Color front_color = wall_front.mm;
    // If edge in the right place - return
    if(wall_front.dm == front_color && wall_down.tm == Color::white) return;


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


    // ==========================================================
    // ================== Front col on down wall ================
    // ==========================================================
    else if(wall_down.mr == front_color && wall_right.dm == Color::white) {
        R();
        F();
    }
    else if(wall_down.ml == front_color && wall_left.dm == Color::white) {
        Lp();
        Fp();
    }
    else if(wall_down.dm == front_color && wall_back.dm == Color::white) {
        Dp();
        R();
        D();
        F();
    }


    // ========================================================
    // =================== White on up wall ===================
    // ========================================================
    else if(wall_up.mr == Color::white && wall_right.tm == front_color) {
        U();
        F2();
    }
    else if(wall_up.ml == Color::white && wall_left.tm == front_color) {
        Up();
        F2();
    }
    else if(wall_up.tm == Color::white && wall_back.tm == front_color) {
        U2();
        F2();
    }


    // ========================================================
    // ================= Front col on up wall =================
    // ========================================================
    else if(wall_up.mr == front_color && wall_right.tm == Color::white) {
        Rp();
        F();
        R();
    }
    else if(wall_up.ml == front_color && wall_left.tm == Color::white) {
        L();
        Fp();
        Lp();
    }
    else if(wall_up.tm == front_color && wall_back.tm == Color::white) {
        U();
        Rp();
        F();
        R();
    }

    
    // ========================================================
    // ===================== Rest on back =====================
    // ========================================================
    else if(wall_back.mr == Color::white && wall_left.ml == front_color) {
        L();
        Up();
        Lp();
        F2();
    }
    else if(wall_back.ml == Color::white && wall_right.mr == front_color) {
        Rp();
        U();
        R();
        F2();
    }

    else if(wall_back.mr == front_color && wall_left.ml == Color::white) {
        L2();
        Fp();
        L2();
    }
    else if(wall_back.ml == front_color && wall_right.mr == Color::white) {
        R2();
        F();
        R2();
    }
}

void Cube::white_cross() {
    if(is_white_cross()) return;
    white_cross_edge();
    if(is_white_cross()) return;
    y();
    white_cross_edge();
    if(is_white_cross()) return;
    y();
    white_cross_edge();
    if(is_white_cross()) return;
    y();
    white_cross_edge();
    cout<<endl;
}

void Cube::white_layer_corner() {
    if(!is_white_cross()) return;

    Color front_color = wall_front.mm;
    // If corner in the right place - return
    if(wall_front.dr == front_color && wall_down.tr == Color::white) return;

    // =========================================================
    // ================== White on front wall ==================
    // =========================================================
    if(wall_front.dr == Color::white && wall_right.dl == front_color) {
        Fp();
        Up();
        F();
        U();
        corner_down_white_front_tr();
    }
    else if(wall_front.tr == Color::white && wall_up.dr == front_color) {
        corner_down_white_front_tr();
    }
    else if(wall_front.tl == Color::white && wall_left.tr == front_color) {
        Up();
        corner_down_white_right_tl();
    }
    else if(wall_front.dl == Color::white && wall_down.tl == front_color) {
        F();
        Up();
        Fp();
        U2();
        corner_down_white_right_tl();
    }


    // ========================================================
    // =================== White on up wall ===================
    // ========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }


    // =========================================================
    // ================== White on right wall ==================
    // =========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }


    // ========================================================
    // ================== White on left wall ==================
    // ========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }


    // ========================================================
    // ================== White on down wall ==================
    // ========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }


    // ========================================================
    // ================== White on back wall ==================
    // ========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }
    // else if() {
        
    // }


}

void Cube::white_corners() {

}
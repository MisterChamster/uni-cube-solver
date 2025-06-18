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

void Cube::solve_white_cross() {
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
    // cout<<"Front color is: "<<front_color;
    // If corner in the right place - return
    if(wall_front.dr == front_color && wall_down.tr == Color::white) return;
    // cout<<"Up dl: "<<wall_up.dl<<". Front tl: "<<wall_front.tl<<endl;
    // cout<<"Beginning my search.\n";

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
    else if(wall_up.dr == Color::white && wall_right.tl == front_color) {
        corner_down_white_up_dr();
    }
    else if(wall_up.tr == Color::white && wall_back.tl == front_color) {
        U();
        corner_down_white_up_dr();
    }
    else if(wall_up.tl == Color::white && wall_left.tl == front_color) {
        U2();
        corner_down_white_up_dr();
    }
    else if(wall_up.dl == Color::white && wall_front.tl == front_color) {
        Up();
        corner_down_white_up_dr();
    }


    // =========================================================
    // ================== White on right wall ==================
    // =========================================================
    else if(wall_right.dr == Color::white && wall_back.dl == front_color) {
        Rp();
        U2();
        R();
        Up();
        corner_down_white_front_tr();
    }
    else if(wall_right.tr == Color::white && wall_up.tr == front_color) {
        U();
        corner_down_white_front_tr();
    }
    else if(wall_right.tl == Color::white && wall_front.tr == front_color) {
        corner_down_white_right_tl();
    }
    else if(wall_right.dl == Color::white && wall_down.tr == front_color) {
        R();
        U();
        Rp();
        Up();
        corner_down_white_right_tl();
    }


    // ========================================================
    // ================== White on left wall ==================
    // ========================================================
    else if(wall_left.dr == Color::white && wall_front.dl == front_color) {
        Lp();
        Up();
        L();
        corner_down_white_front_tr();
    }
    else if(wall_left.tr == Color::white && wall_up.dl == front_color) {
        Up();
        corner_down_white_front_tr();
    }
    else if(wall_left.tl == Color::white && wall_back.tr == front_color) {
        U2();
        corner_down_white_right_tl();
    }
    else if(wall_left.dl == Color::white && wall_down.dl == front_color) {
        L();
        U2();
        Lp();
        corner_down_white_right_tl();
    }


    // ========================================================
    // ================== White on down wall ==================
    // ========================================================
    else if(wall_down.dr == Color::white && wall_right.dr == front_color) {
        B();
        U2();
        Bp();
        Up();
        corner_down_white_front_tr();
    }
    else if(wall_down.tl == Color::white && wall_left.dr == front_color) {
        Lp();
        Up();
        L();
        corner_down_white_right_tl();
    }
    else if(wall_down.dl == Color::white && wall_back.dl == front_color) {
        L();
        U2();
        Lp();
        corner_down_white_front_tr();
    }


    // ========================================================
    // ================== White on back wall ==================
    // ========================================================
    else if(wall_back.dr == Color::white && wall_left.dl == front_color) {
        Bp();
        U2();
        B();
        corner_down_white_front_tr();
    }
    else if(wall_back.tr == Color::white && wall_up.tl == front_color) {
        U2();
        corner_down_white_front_tr();
    }
    else if(wall_back.tl == Color::white && wall_right.tr == front_color) {
        U();
        corner_down_white_right_tl();
    }
    else if(wall_back.dl == Color::white && wall_down.dr == front_color) {
        B();
        U();
        Bp();
        corner_down_white_right_tl();
    }
    cout<<"Search ended. Happy?\n";
}

void Cube::solve_white_layer() {
    if(is_white_layer()) return;
    white_layer_corner();
    if(is_white_layer()) return;
    y();
    white_layer_corner();
    if(is_white_layer()) return;
    y();
    white_layer_corner();
    if(is_white_layer()) return;
    y();
    white_layer_corner();
    cout<<endl;
}

void Cube::f2l_right_piece() {
    if(!is_white_layer()) return;

    Color front_color = wall_front.mm;
    Color right_color = wall_right.mm;
    //solved piece
    if(wall_front.mr == front_color && wall_right.ml == right_color) return;
    //evil mf
    if(wall_front.mr == right_color && wall_right.ml == front_color) f2l_reverse();


    // =========================================================
    // =============== Front color on front wall ===============
    // =========================================================
    else if(wall_front.tm == front_color && wall_up.dm == right_color) {
        f2l_right();
    }
    else if(wall_front.ml == front_color && wall_left.mr == right_color) {
        f2l_left();
        U();
        f2l_right();
    }

    // =========================================================
    // =============== Right color on front wall ===============
    // =========================================================
    else if(wall_front.tm == right_color && wall_up.dm == front_color) {
        Up();
        f2l_left_from_right_layer();
    }
    else if(wall_front.ml == right_color && wall_left.mr == front_color) {
        f2l_left();
        f2l_left_from_right_layer();
    }

    // ========================================================
    // ================ Front color on up wall ================
    // ========================================================
    else if(wall_up.mr == front_color && wall_right.tm == right_color) {
        f2l_left_from_right_layer();
    }
    else if(wall_up.tm == front_color && wall_back.tm == right_color) {
        U();
        f2l_left_from_right_layer();
    }
    else if(wall_up.ml == front_color && wall_left.tm == right_color) {
        U2();
        f2l_left_from_right_layer();
    }

    // ========================================================
    // ================ Right color on up wall ================
    // ========================================================
    else if(wall_up.mr == right_color && wall_right.tm == front_color) {
        U();
        f2l_right();
    }
    else if(wall_up.tm == right_color && wall_back.tm == front_color) {
        U2();
        f2l_right();
    }
    else if(wall_up.ml == right_color && wall_left.tm == front_color) {
        Up();
        f2l_right();
    }

    // ========================================================
    // =============== Front color on back wall ===============
    // ========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }
    
    // ========================================================
    // =============== Right color on back wall ===============
    // ========================================================
    // else if() {
        
    // }
    // else if() {
        
    // }

}

void Cube::solve_f2l() {
    if(is_f2l()) return;
    f2l_right_piece();
    if(is_f2l()) return;
    y();
    f2l_right_piece();
    if(is_f2l()) return;
    y();
    f2l_right_piece();
    if(is_f2l()) return;
    y();
    f2l_right_piece();
    cout<<endl;
}
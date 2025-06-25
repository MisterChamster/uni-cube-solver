#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>


// White Layer Down
void Cube::white_layer_down() {
    if     (wall_up.mm    == Color::white) z2();
    else if(wall_front.mm == Color::white) xp();
    else if(wall_right.mm == Color::white) z();
    else if(wall_left.mm  == Color::white) zp();
    else if(wall_back.mm  == Color::white) x();
}


// White Cross Edges
void Cube::white_cross_edge() {
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
        cout<<endl;
    }
    else if(wall_front.mr == Color::white && wall_right.ml == front_color) {
        R();
        U();
        Rp();
        F2();
        cout<<endl;
    }
    else if(wall_front.ml == Color::white && wall_left.mr == front_color) {
        Lp();
        Up();
        L();
        F2();
        cout<<endl;
    }
    else if(wall_front.tm == Color::white && wall_up.dm == front_color) {
        Up();
        Rp();
        F();
        R();
        cout<<endl;
    }


    // =========================================================
    // ================= Front col on front wall ===============
    // =========================================================
    else if(wall_front.mr == front_color && wall_right.ml == Color::white) {
        F();
        cout<<endl;
    }
    else if(wall_front.ml == front_color && wall_left.mr == Color::white) {
        Fp();
        cout<<endl;
    }
    else if(wall_front.tm == front_color && wall_up.dm == Color::white) {
        F2();
        cout<<endl;
    }


    // ========================================================
    // =================== White on down wall =================
    // ========================================================
    else if(wall_down.mr == Color::white && wall_right.dm == front_color) {
        R();
        D();
        Rp();
        Dp();
        cout<<endl;
    }
    else if(wall_down.ml == Color::white && wall_left.dm == front_color) {
        L();
        Dp();
        Lp();
        D();
        cout<<endl;
    }
    else if(wall_down.dm == Color::white && wall_back.dm == front_color) {
        D2();
        F();
        D2();
        Fp();
        cout<<endl;
    }


    // ==========================================================
    // ================== Front col on down wall ================
    // ==========================================================
    else if(wall_down.mr == front_color && wall_right.dm == Color::white) {
        R();
        F();
        cout<<endl;
    }
    else if(wall_down.ml == front_color && wall_left.dm == Color::white) {
        Lp();
        Fp();
        cout<<endl;
    }
    else if(wall_down.dm == front_color && wall_back.dm == Color::white) {
        Dp();
        R();
        D();
        F();
        cout<<endl;
    }


    // ========================================================
    // =================== White on up wall ===================
    // ========================================================
    else if(wall_up.mr == Color::white && wall_right.tm == front_color) {
        U();
        F2();
        cout<<endl;
    }
    else if(wall_up.ml == Color::white && wall_left.tm == front_color) {
        Up();
        F2();
        cout<<endl;
    }
    else if(wall_up.tm == Color::white && wall_back.tm == front_color) {
        U2();
        F2();
        cout<<endl;
    }


    // ========================================================
    // ================= Front col on up wall =================
    // ========================================================
    else if(wall_up.mr == front_color && wall_right.tm == Color::white) {
        Rp();
        F();
        R();
        cout<<endl;
    }
    else if(wall_up.ml == front_color && wall_left.tm == Color::white) {
        L();
        Fp();
        Lp();
        cout<<endl;
    }
    else if(wall_up.tm == front_color && wall_back.tm == Color::white) {
        U();
        Rp();
        F();
        R();
        cout<<endl;
    }


    // ========================================================
    // ===================== Rest on back =====================
    // ========================================================
    else if(wall_back.mr == Color::white && wall_left.ml == front_color) {
        L();
        Up();
        Lp();
        F2();
        cout<<endl;
    }
    else if(wall_back.ml == Color::white && wall_right.mr == front_color) {
        Rp();
        U();
        R();
        F2();
        cout<<endl;
    }

    else if(wall_back.mr == front_color && wall_left.ml == Color::white) {
        L2();
        Fp();
        L2();
        cout<<endl;
    }
    else if(wall_back.ml == front_color && wall_right.mr == Color::white) {
        R2();
        F();
        R2();
        cout<<endl;
    }
}

void Cube::solve_white_cross() {
    // If white mm is not on bottom - return
    if(wall_down.mm != Color::white) return;

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
}


// White Layer Corners
void Cube::white_layer_corner() {
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
        cout<<endl;
    }
    else if(wall_front.tr == Color::white && wall_up.dr == front_color) {
        corner_down_white_front_tr();
        cout<<endl;
    }
    else if(wall_front.tl == Color::white && wall_left.tr == front_color) {
        Up();
        corner_down_white_right_tl();
        cout<<endl;
    }
    else if(wall_front.dl == Color::white && wall_down.tl == front_color) {
        F();
        Up();
        Fp();
        U2();
        corner_down_white_right_tl();
        cout<<endl;
    }


    // ========================================================
    // =================== White on up wall ===================
    // ========================================================
    else if(wall_up.dr == Color::white && wall_right.tl == front_color) {
        corner_down_white_up_dr();
        cout<<endl;
    }
    else if(wall_up.tr == Color::white && wall_back.tl == front_color) {
        U();
        corner_down_white_up_dr();
        cout<<endl;
    }
    else if(wall_up.tl == Color::white && wall_left.tl == front_color) {
        U2();
        corner_down_white_up_dr();
        cout<<endl;
    }
    else if(wall_up.dl == Color::white && wall_front.tl == front_color) {
        Up();
        corner_down_white_up_dr();
        cout<<endl;
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
        cout<<endl;
    }
    else if(wall_right.tr == Color::white && wall_up.tr == front_color) {
        U();
        corner_down_white_front_tr();
        cout<<endl;
    }
    else if(wall_right.tl == Color::white && wall_front.tr == front_color) {
        corner_down_white_right_tl();
        cout<<endl;
    }
    else if(wall_right.dl == Color::white && wall_down.tr == front_color) {
        R();
        U();
        Rp();
        Up();
        corner_down_white_right_tl();
        cout<<endl;
    }


    // ========================================================
    // ================== White on left wall ==================
    // ========================================================
    else if(wall_left.dr == Color::white && wall_front.dl == front_color) {
        Lp();
        Up();
        L();
        corner_down_white_front_tr();
        cout<<endl;
    }
    else if(wall_left.tr == Color::white && wall_up.dl == front_color) {
        Up();
        corner_down_white_front_tr();
        cout<<endl;
    }
    else if(wall_left.tl == Color::white && wall_back.tr == front_color) {
        U2();
        corner_down_white_right_tl();
        cout<<endl;
    }
    else if(wall_left.dl == Color::white && wall_down.dl == front_color) {
        L();
        U2();
        Lp();
        corner_down_white_right_tl();
        cout<<endl;
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
        cout<<endl;
    }
    else if(wall_down.tl == Color::white && wall_left.dr == front_color) {
        Lp();
        Up();
        L();
        corner_down_white_right_tl();
        cout<<endl;
    }
    else if(wall_down.dl == Color::white && wall_back.dr == front_color) {
        L();
        U2();
        Lp();
        corner_down_white_front_tr();
        cout<<endl;
    }


    // ========================================================
    // ================== White on back wall ==================
    // ========================================================
    else if(wall_back.dr == Color::white && wall_left.dl == front_color) {
        Bp();
        U2();
        B();
        corner_down_white_front_tr();
        cout<<endl;
    }
    else if(wall_back.tr == Color::white && wall_up.tl == front_color) {
        U2();
        corner_down_white_front_tr();
        cout<<endl;
    }
    else if(wall_back.tl == Color::white && wall_right.tr == front_color) {
        U();
        corner_down_white_right_tl();
        cout<<endl;
    }
    else if(wall_back.dl == Color::white && wall_down.dr == front_color) {
        B();
        U();
        Bp();
        corner_down_white_right_tl();
        cout<<endl;
    }
    // cout<<"Search ended. Happy?\n";
}

void Cube::solve_white_layer() {
    if(!is_white_cross()) return;

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
}


// F2L
void Cube::f2l_right_piece() {
    Color front_color = wall_front.mm;
    Color right_color = wall_right.mm;
    //solved piece
    if(wall_front.mr == front_color && wall_right.ml == right_color) return;
    //evil mf
    if(wall_front.mr == right_color && wall_right.ml == front_color) {
        f2l_reverse();
        cout<<endl;
    }


    // =========================================================
    // =============== Front color on front wall ===============
    // =========================================================
    else if(wall_front.tm == front_color && wall_up.dm == right_color) {
        f2l_right();
        cout<<endl;
    }
    else if(wall_front.ml == front_color && wall_left.mr == right_color) {
        f2l_left();
        // U();
        // f2l_right();
        U2();
        f2l_right_from_left_layer();
        cout<<endl;
    }


    // =========================================================
    // =============== Right color on front wall ===============
    // =========================================================
    else if(wall_front.tm == right_color && wall_up.dm == front_color) {
        Up();
        f2l_left_from_right_layer();
        cout<<endl;
    }
    else if(wall_front.ml == right_color && wall_left.mr == front_color) {
        f2l_left();
        f2l_left_from_right_layer();
        cout<<endl;
    }


    // ========================================================
    // ================ Front color on up wall ================
    // ========================================================
    else if(wall_up.mr == front_color && wall_right.tm == right_color) {
        f2l_left_from_right_layer();
        cout<<endl;
    }
    else if(wall_up.tm == front_color && wall_back.tm == right_color) {
        U();
        f2l_left_from_right_layer();
        cout<<endl;
    }
    else if(wall_up.ml == front_color && wall_left.tm == right_color) {
        U2();
        f2l_left_from_right_layer();
        cout<<endl;
    }


    // ========================================================
    // ================ Right color on up wall ================
    // ========================================================
    else if(wall_up.mr == right_color && wall_right.tm == front_color) {
        U2();
        f2l_right_from_left_layer();
        cout<<endl;
    }
    else if(wall_up.tm == right_color && wall_back.tm == front_color) {
        Up();
        f2l_right_from_left_layer();
        cout<<endl;
    }
    else if(wall_up.ml == right_color && wall_left.tm == front_color) {
        f2l_right_from_left_layer();
        cout<<endl;
    }


    // ========================================================
    // =============== Front color on back wall ===============
    // ========================================================
    else if(wall_back.mr == front_color && wall_left.ml == right_color) {
        y2();
        f2l_right();
        y2();
        Up();
        f2l_left_from_right_layer();
        cout<<endl;
    }
    else if(wall_back.ml == front_color && wall_right.mr == right_color) {
        y();
        f2l_right();
        yp();
        f2l_right_from_left_layer();
        cout<<endl;
    }


    // ========================================================
    // =============== Right color on back wall ===============
    // ========================================================
    else if(wall_back.mr == right_color && wall_left.ml == front_color) {
        y2();
        f2l_right();
        y2();
        f2l_right();
        cout<<endl;
    }
    else if(wall_back.ml == right_color && wall_right.mr == front_color) {
        y();
        f2l_right();
        yp();
        U2();
        f2l_left_from_right_layer();
        cout<<endl;
    }
}

void Cube::solve_f2l() {
    if(!is_white_layer()) return;

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
}


// Yellow Cross
void Cube::solve_yellow_cross() {
    if(!is_f2l()) return;
    if(is_yellow_cross()) return;


    // ========================================================
    // ================== Good orients + dot ==================
    // ========================================================
    if(wall_up.tm == Color::yellow && wall_up.ml == Color::yellow) {
        yellow_cross_2s();
    }
    else if(wall_up.mr == Color::yellow && wall_up.ml == Color::yellow) {
        yellow_cross_1s();
    }
    else if(wall_up.mr != Color::yellow &&
            wall_up.tm != Color::yellow &&
            wall_up.ml != Color::yellow &&
            wall_up.dm != Color::yellow) {

        yellow_cross_2s();
        yp();

        yellow_cross_1s();
    }

    // =========================================================
    // ======================= L orients =======================
    // =========================================================
    else if(wall_up.ml == Color::yellow && wall_up.dm == Color::yellow) {
        U();
        yellow_cross_2s();
    }
    else if(wall_up.dm == Color::yellow && wall_up.mr == Color::yellow) {
        U2();
        yellow_cross_2s();
    }
    else if(wall_up.mr == Color::yellow && wall_up.tm == Color::yellow) {
        Up();
        yellow_cross_2s();
    }

    // ========================================================
    // ===================== Line orients =====================
    // ========================================================
    else if(wall_up.tm == Color::yellow && wall_up.dm == Color::yellow) {
        U();
        yellow_cross_1s();
    }
    cout<<endl;
}


// Yellow Cross Orientation
void Cube::solve_yellow_cross_orientation() {
    if(!is_yellow_cross()) return;
    if(is_yellow_cross_oriented()) return;

    Color front_color = wall_front.mm;
    Color right_color = wall_right.mm;
    Color left_color  = wall_left.mm;
    Color back_color  = wall_back.mm;

    // already prepared
    if(wall_right.tm == right_color && wall_back.tm == back_color) return;


    // ========================================================
    // ==================== Back and right ====================
    // ========================================================
    if(wall_back.tm == right_color && wall_left.tm == back_color) {
        U();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_left.tm == right_color && wall_front.tm == back_color) {
        // cout<<"WINDOWWWWWWWWWWWWWWWWW\n";
        U2();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_front.tm == right_color && wall_right.tm == back_color) {
        Up();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }


    // =========================================================
    // ===================== Left and back =====================
    // =========================================================
    else if(wall_back.tm == back_color && wall_left.tm == left_color) {
        y();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_left.tm == back_color && wall_front.tm == left_color) {
        y();
        U();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_front.tm == back_color && wall_right.tm == left_color) {
        y();
        U2();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_right.tm == back_color && wall_back.tm == left_color) {
        y();
        Up();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }


    // ========================================================
    // ==================== Front and left ====================
    // ========================================================
    else if(wall_left.tm == left_color && wall_front.tm == front_color) {
        y2();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_front.tm == left_color && wall_right.tm == front_color) {
        y2();
        U();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_right.tm == left_color && wall_back.tm == front_color) {
        y2();
        U2();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_back.tm == left_color && wall_left.tm == front_color) {
        y2();
        Up();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }


    // =========================================================
    // ==================== Right and front ====================
    // =========================================================
    else if(wall_front.tm == front_color && wall_right.tm == right_color) {
        yp();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_right.tm == front_color && wall_back.tm == right_color) {
        yp();
        U();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_back.tm == front_color && wall_left.tm == right_color) {
        yp();
        U2();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_left.tm == front_color && wall_front.tm == right_color) {
        yp();
        Up();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }


    // ========================================================
    // ================= All horizontal lines =================
    // ========================================================
    else if(wall_right.tm == right_color && wall_left.tm == left_color) {
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
        y();
        U();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_right.tm == left_color && wall_left.tm == right_color) {
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
        yp();
        Up();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_right.tm == front_color && wall_left.tm == back_color) {
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
        U2();
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
    }
    else if(wall_right.tm == back_color && wall_left.tm == front_color) {
        if(is_yellow_cross_oriented()) return;
        yellow_cross_orient_sequence();
        y2();
    }

    cout<<endl;
    if(!is_yellow_cross_oriented()) cout<<"cube_solving.cxx.solve_yellow_cross_orientation() error: Cross has not been oriented properly. Dummy.";
}


// Yellow Corners Placement
void Cube::yellow_corners_placement_prepare_cube() {
    // this if is dumb and has no use you cunt
    // if(is_yellow_corner_placed("dr")) {}
    
    if(is_yellow_corner_placed("tr")) {
        y();
    }
    else if(is_yellow_corner_placed("tl")) {
        y2();
    }
    else if(is_yellow_corner_placed("dl")) {
        yp();
    }
}

void Cube::solve_yellow_corners_placing() {
    if(!is_yellow_cross_oriented()) return;
    if(is_yellow_corners_placed()) return;

    yellow_corners_placement_prepare_cube();
    yellow_corners_orient_sequence();
    if(is_yellow_corners_placed()) return;
    yellow_corners_orient_sequence();
    if(is_yellow_corners_placed()) return;
    else cout<<"\ncube_solving.cxx.solve_yellow_corners_placing() error: Orient sequence didn't orient properly after 2 tries. Idiot.\n";
}


// Yellow Corners Orientation
void Cube::yellow_corners_orientation_prepare_cube(bool &flag) {
    Color down_color = wall_down.mm;
    if(wall_down.tr != down_color) {
        // cout<<"wall_down.tr: "<<wall_down.dl<<". down_color: "<<down_color<<"\n";
        // cout<<"Returning\n";
        return;
    }
    if(wall_down.dr != down_color) {
        // cout<<"wall_down.dr: "<<wall_down.dl<<". down_color: "<<down_color<<"\n";
        // cout<<"Doing DP\n";
        Dp();
    }
    else if(wall_down.dl != down_color) {
        // cout<<"wall_down.dl: "<<wall_down.dl<<". down_color: "<<down_color<<"\n";
        // cout<<"Doing D2\n";
        D2();
    }
    else {
        // cout<<"We're free to go, chief\n";
        flag = true;
    }
}

void Cube::yellow_corners_algorithm() {
    Color down_color = wall_down.mm;
    if(wall_front.dr == down_color) {RURU2(); RURU2();}
    else if(wall_right.dl == down_color) RURU2();
    else cout<<"\ncube_solving.cxx.yellow_corners_algorithm() error: wall_front.dr corner should not be solved. Dumbass.\n";
}

void Cube::yellow_corners_orientation() {
    //should be safer but idgaf
    bool flagger = false;
    for(int i=0; i<4; i++) {
        yellow_corners_orientation_prepare_cube(flagger);
        if(flagger == true) break;
        yellow_corners_algorithm();
    }
    cout<<endl;
}

// Yellow Layer Orientation
void Cube::orient_down_layer() {
    Color front_color = wall_front.mm;
    if(wall_right.dm == front_color) Dp();
    else if(wall_back.dm == front_color) D2();
    else if(wall_left.dm == front_color) Dp();
}

// Solving
void Cube::solve() {
    user_input_all_walls();

    white_layer_down();
    cout<<endl;
    solve_white_cross();
    cout<<endl;
    solve_white_layer();
    cout<<endl;
    solve_f2l();
    cout<<endl;
    solve_yellow_cross();
    cout<<endl;
    solve_yellow_cross_orientation();
    // cout<<endl;
    // print_cube();
    cout<<endl;
    solve_yellow_corners_placing();
    cout<<endl;
    z2();
    cout<<endl;
    yellow_corners_orientation();
    cout<<endl;
    orient_down_layer();
    cout<<endl;
    // print_cube();
    if(!is_solved()) cout<<"cube_solving.cxx.solve() error: Cube is not solved.\n";
}

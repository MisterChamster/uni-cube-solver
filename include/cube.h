#ifndef CUBE
#define CUBE

#include "wall.h"
#include "colors.h"
#include <iostream>

using namespace std;


class Cube{
public:
    // ========================================================================
    // ================================ Fields ================================
    // ========================================================================
    Wall wall_front = Wall(Color::blue);
    Wall wall_right = Wall(Color::red);
    Wall wall_left  = Wall(Color::orange);
    Wall wall_up    = Wall(Color::yellow);
    Wall wall_down  = Wall(Color::white);
    Wall wall_back  = Wall(Color::green);



    // ========================================================================
    // ============================= Constructors =============================
    // ========================================================================
    //solved cube constructor
    Cube();

    Cube(Color wall_front_color,
         Color wall_right_color,
         Color wall_left_color,
         Color wall_up_color,
         Color wall_down_color,
         Color wall_back_color);

    Cube(Wall wall_front, 
         Wall wall_right,
         Wall wall_left,
         Wall wall_up,
         Wall wall_down,
         Wall wall_back);


    // =========================================================================
    // ============================ Methods - moves ============================
    // =========================================================================

    // =============== Basic ================
    void F();
    void R();
    void L();
    void U();
    void D();
    void B();

    // ============== Reverse ==============
    void Fp();
    void Rp();
    void Lp();
    void Up();
    void Dp();
    void Bp();

    // ============= Cube moves =============
    void x();
    void y();
    void z();

    // ========= Reverse cube moves =========
    void xp();
    void yp();
    void zp();

    // ============== 2-moves ==============
    void F2();
    void R2();
    void L2();
    void U2();
    void D2();
    void B2();

    void x2();
    void y2();
    void z2();

    // =========== Move sequences ===========

private:
    void corner_down_white_front_tr();
    void corner_down_white_up_dr();
    void corner_down_white_right_tl();

    void f2l_right();
    void f2l_left();
    void f2l_right_from_left_layer();
    void f2l_left_from_right_layer();
    void f2l_reverse();

    void RURU();
    void RURU2();
    void yellow_cross_1s();
    void yellow_cross_2s();

    void yellow_cross_orient_sequence();
    void yellow_cross_orient_sequence_no_Up();
    void yellow_cross_orient_sequence_U2();
    void yellow_cross_orient_sequence_U();

    void yellow_corners_orient_sequence();



    // =========================================================================
    // ============================ Methods - other ============================
    // =========================================================================
private:
    void user_input_wall(string wall_name);

public:
    void print_cube();
    void user_input_all_walls();
    bool is_white_cross();
    bool is_white_layer();
    bool is_f2l();
    bool is_yellow_cross();
    bool is_yellow_cross_oriented();
    bool is_yellow_corner_placed(string up_corner);
    bool is_yellow_corners_placed();
    bool is_solved();



    // =========================================================================
    // =========================== Methods - solving ===========================
    // =========================================================================
private:
    void white_cross_edge();
    void white_layer_corner();
    void f2l_right_piece();
    void yellow_corners_placement_prepare_cube();
    void yellow_corners_orientation_prepare_cube(bool &flag);
    void yellow_corners_algorithm();
    void orient_down_layer();

public:
    void white_layer_down();
    void solve_white_cross();
    void solve_white_layer();
    void solve_f2l();
    void solve_yellow_cross();
    void solve_yellow_cross_orientation();
    void solve_yellow_corners_placing();
    void yellow_corners_orientation();



};

#endif //CUBE

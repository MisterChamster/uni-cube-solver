#ifndef CUBE
#define CUBE

#include <wall.h>
#include <colors.h>

class Cube{
    Wall wall_front = Wall(Color::blue);
    Wall wall_right = Wall(Color::red);
    Wall wall_left  = Wall(Color::orange);
    Wall wall_up    = Wall(Color::yellow);
    Wall wall_down  = Wall(Color::white);
    Wall wall_back  = Wall(Color::green);


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


    void print_cube();
    void F();
    void R();
    void L();
    void U();
    void D();
    // void B();
};

#endif //CUBE
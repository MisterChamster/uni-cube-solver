#ifndef WALL
#define WALL

#include <colors.h>

class Wall {
public:
    color tl, tm, tr;
    color ml, mm, mr;
    color dl, dm, dr;

    Wall(color tl, color tm, color tr,
         color ml, color mm, color mr,
         color dl, color dm, color dr);

    Wall(color c);


    void print_wall();
    void rotate_right();
    void rotate_left();
    void rotate_right2();
    void rotate_left2();
};

#endif //WALL
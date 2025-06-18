#ifndef WALL
#define WALL

#include "colors.h"


class Wall {
public:
    Color tl, tm, tr;
    Color ml, mm, mr;
    Color dl, dm, dr;

    Wall(Color tl, Color tm, Color tr,
         Color ml, Color mm, Color mr,
         Color dl, Color dm, Color dr);

    Wall(Color c);


    void print_wall();
    void rotate_right();
    void rotate_left();
    void rotate_2();
    bool is_one_color();
};

#endif //WALL

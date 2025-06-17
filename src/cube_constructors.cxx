#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>


//solved cube constructor
Cube::Cube(){
    wall_front = Wall(Color::blue);
    wall_right = Wall(Color::red);
    wall_left  = Wall(Color::orange);
    wall_up    = Wall(Color::yellow);
    wall_down  = Wall(Color::white);
    wall_back  = Wall(Color::green);

}

Cube::Cube(Color wall_front_color,
           Color wall_right_color,
           Color wall_left_color,
           Color wall_up_color,
           Color wall_down_color,
           Color wall_back_color) {

    wall_front = Wall(wall_front_color);
    wall_right = Wall(wall_right_color);
    wall_left  = Wall(wall_left_color);
    wall_up    = Wall(wall_up_color);
    wall_down  = Wall(wall_down_color);
    wall_back  = Wall(wall_back_color);
}

Cube::Cube(Wall wall_front, 
           Wall wall_right,
           Wall wall_left,
           Wall wall_up,
           Wall wall_down,
           Wall wall_back) {

    this->wall_front = wall_front;
    this->wall_right = wall_right;
    this->wall_left  = wall_left;
    this->wall_up    = wall_up;
    this->wall_down  = wall_down;
    this->wall_back  = wall_back;
}

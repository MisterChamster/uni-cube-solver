#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>

using namespace std;


void Cube::print_cube(){
    cout<<"Front wall: "<<endl;
    wall_front.print_wall();
    cout<<"Right wall: "<<endl;
    wall_right.print_wall();
    cout<<"Left wall: "<<endl;
    wall_left.print_wall();
    cout<<"Up wall: "<<endl;
    wall_up.print_wall();
    cout<<"Down wall: "<<endl;
    wall_down.print_wall();
    cout<<"Back wall: "<<endl;
    wall_back.print_wall();
}

void Cube::input_wall(string wall_name) {

}

bool Cube::is_solved(){
    return false;
}

bool Cube::is_white_cross() {
    return false;
}

bool Cube::is_white_layer() {
    return false;
}

bool Cube::is_second_layer() {
    return false;
}

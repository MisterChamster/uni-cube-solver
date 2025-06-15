#include "wall.h"
#include "colors.h"
#include "cube.h"
#include <iostream>
using namespace std;


void Cube::print_cube(){
    cout<<"front wall: "<<endl;
    wall_front.print_wall();
    cout<<"right wall: "<<endl;
    wall_right.print_wall();
    cout<<"left wall: "<<endl;
    wall_left.print_wall();  
    cout<<"up wall: "<<endl;
    wall_up.print_wall();  
    cout<<"down wall: "<<endl;  
    wall_down.print_wall(); 
    cout<<"back wall: "<<endl; 
    wall_back.print_wall();  
}

bool Cube::is_solved(){
    return false;
}

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

void Cube::user_input_wall(string wall_name) {
    string user_input;
    Wall* ptr_wall;
    if      (wall_name == "front") ptr_wall = &wall_front;
    else if (wall_name == "up")    ptr_wall = &wall_up;
    else if (wall_name == "right") ptr_wall = &wall_right;
    else if (wall_name == "left")  ptr_wall = &wall_left;
    else if (wall_name == "down")  ptr_wall = &wall_down;
    else if (wall_name == "back")  ptr_wall = &wall_back;
    
    while(true) {
        cout<<"Input "<<"\e[1m"<<wall_name<<"\e[0m"<<" wall. Colors available: w b g r o y.\n>> ";
        // cin>>user_input;
        getline(cin, user_input);
        // cout<<"\nUser input is: "<<user_input.length()<<endl;
        if(user_input.length() != 9+8 && user_input.length() != 9) {
            cout<<"Incorrect input.\n"<<endl;
            continue;
        }
        cout<<"\n";

        Color* square_ptrs[9];
        square_ptrs[0] = &(ptr_wall->tl);
        square_ptrs[1] = &(ptr_wall->tm);
        square_ptrs[2] = &(ptr_wall->tr);
        square_ptrs[3] = &(ptr_wall->ml);
        square_ptrs[4] = &(ptr_wall->mm);
        square_ptrs[5] = &(ptr_wall->mr);
        square_ptrs[6] = &(ptr_wall->dl);
        square_ptrs[7] = &(ptr_wall->dm);
        square_ptrs[8] = &(ptr_wall->dr);

        for(int i=0; i<9; i++){
            int string_index;
            if(user_input.length() == 9 + 8) string_index = i*2;
            else string_index = i;

            if     (user_input.at(string_index) == 'w') *square_ptrs[i] = white;
            else if(user_input.at(string_index) == 'b') *square_ptrs[i] = blue;
            else if(user_input.at(string_index) == 'g') *square_ptrs[i] = green;
            else if(user_input.at(string_index) == 'r') *square_ptrs[i] = red;
            else if(user_input.at(string_index) == 'o') *square_ptrs[i] = orange;
            else if(user_input.at(string_index) == 'y') *square_ptrs[i] = yellow;
        }
        break;
    }
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

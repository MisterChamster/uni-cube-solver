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

void Cube::user_input_all_walls() {
    user_input_wall("front");
    user_input_wall("up");
    user_input_wall("right");
    user_input_wall("left");
    user_input_wall("down");
    user_input_wall("back");
}

bool Cube::is_white_cross() {
    // If white is not on down layer
    if(wall_down.mm != Color::white) return false;

    // If down layer edges are white...
    if(wall_down.tm == Color::white &&
       wall_down.mr == Color::white &&
       wall_down.ml == Color::white &&
       wall_down.dm == Color::white) {
        // If edge pieces match wall colors...
        if(wall_front.dm == wall_front.mm &&
           wall_right.dm == wall_right.mm &&
           // Can just omit one compeletly for free
           // wall_left.dm  == wall_left.mm  &&
           wall_back.dm  == wall_back.mm) 
            return true;
    }

    return false;
}

bool Cube::is_white_layer() {
    if(!is_white_cross()) return false;

    // If down corners are white...
    if(wall_down.tl == Color::white &&
       wall_down.tr == Color::white &&
       wall_down.dl == Color::white &&
       wall_down.dr == Color::white) {
        // If corner pieces match wall colors...
        // Fuck. Gotta check just white and one other color, not all 3
        //    wall_left.dl  == wall_left.mm  &&
        //    wall_back.dl  == wall_back.mm  &&
        //    wall_front.dl == wall_front.mm &&
        //    wall_right.dl == wall_right.mm &&
        if(wall_front.dr == wall_front.mm &&
           wall_right.dr == wall_right.mm &&
        //  vvvvvvvvvv Free one to omit vvvvvvvvvv
        //    wall_left.dr  == wall_left.mm  &&
           wall_back.dr  == wall_back.mm) return true;
       }

    return false;
}

bool Cube::is_f2l() {
    if(!is_white_layer()) return false;

    if(wall_front.mr == wall_front.mm && wall_front.ml == wall_front.mm &&
       wall_right.mr == wall_right.mm && wall_right.ml == wall_right.mm &&
       wall_left.mr  == wall_left.mm  && wall_left.ml  == wall_left.mm  &&
       wall_back.mr  == wall_back.mm  && wall_back.ml  == wall_back.mm) 
        return true;

    return false;
}

bool Cube::is_yellow_cross() {
    if(!is_f2l()) return false;

    // If up layer edges are yellow...
    if(wall_up.tm == Color::yellow &&
       wall_up.mr == Color::yellow &&
       wall_up.ml == Color::yellow &&
       wall_up.dm == Color::yellow) return true;

    return false;
}

bool Cube::is_yellow_cross_oriented() {
    if(!is_yellow_cross()) return false;

    // If edge pieces match wall colors...
    if(wall_front.tm == wall_front.mm &&
        wall_right.tm == wall_right.mm &&
        // vvvvvvvv Free one to omit vvvvvvvv
        // wall_left.tm  == wall_left.mm  &&
        wall_back.tm  == wall_back.mm) return true;

    return false;
}

bool Cube::is_corner_oriented(string up_corner) {
    if(!is_yellow_cross_oriented()) return false;

    Color front_color = wall_front.mm;
    Color right_color = wall_right.mm;
    Color left_color  = wall_left.mm;
    Color back_color  = wall_back.mm;
    Color up_color    = wall_up.mm;

    if(up_corner == "dr") {
        if(wall_front.tr == front_color && wall_up.dr == up_color)    return true;
        if(wall_front.tr == up_color    && wall_up.dr == right_color) return true;
        if(wall_front.tr == right_color && wall_up.dr == front_color) return true;
    }
    else if(up_corner == "tr") {
        if(wall_right.tr == right_color && wall_up.tr == up_color)    return true;
        if(wall_right.tr == up_color    && wall_up.tr == back_color)  return true;
        if(wall_right.tr == back_color  && wall_up.tr == right_color) return true;
    }
    else if(up_corner == "tl") {
        if(wall_back.tr == back_color && wall_up.tl == up_color)   return true;
        if(wall_back.tr == up_color   && wall_up.tl == left_color) return true;
        if(wall_back.tr == left_color && wall_up.tl == back_color) return true;
    }
    else if(up_corner == "dl") {
        if(wall_left.tr == left_color  && wall_up.dl == up_color)    return true;
        if(wall_left.tr == up_color    && wall_up.dl == front_color) return true;
        if(wall_left.tr == front_color && wall_up.dl == left_color)  return true;
    }

    return false;
}

bool Cube::is_solved(){
    if(!is_yellow_cross()) return false;

    // If up corners are yellow...
    if(wall_up.tl == Color::yellow &&
       wall_up.tr == Color::yellow &&
       wall_up.dl == Color::yellow &&
       wall_up.dr == Color::yellow){
        // If corner pieces match wall colors...
        // One color for each + 1 omit
        if(wall_front.tr == wall_front.mm &&
           wall_right.tr == wall_right.mm &&
        //  vvvvvvvvvv Free one to omit vvvvvvvvvv
        //    wall_left.tr  == wall_left.mm  &&
           wall_back.tr  == wall_back.mm) return true;
    }

    return false;
}

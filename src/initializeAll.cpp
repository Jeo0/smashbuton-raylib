#include "raylib.h"
#include "raymath.h"
#include <iostream>


#include "initializeAll.hpp"

void InitializeAll(){

    InitWindow(screenWidth, screenHeight, pogi);
     /* initialize players */
    Player leftPlayer = Player(KEY_W, KEY_A, KEY_S, KEY_D);
    Player rightPlayer = Player(KEY_I, KEY_J, KEY_K, KEY_L);


    pogisijessie = GetRandomValue(21, 179);
    // generate addends
    leftPlayer.addends1 = pogisijessie - GetRandomValue(21, 179);
    

    SetTargetFPS(10);

    /* game state variables*/
    space = false;


}

// definition
Player::Player(uint one, uint two, uint three, uint four){
    // randomize
    addends1 = one; 
    addends2 = two; 
    useless1 = three; 
    useless2 = four;
}

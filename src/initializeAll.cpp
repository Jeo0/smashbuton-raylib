#include "raylib.h"
#include "initializeAll.hpp"

inline void InitializeAll(){

    InitWindow(screenWidth, screenHeight, pogi);


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

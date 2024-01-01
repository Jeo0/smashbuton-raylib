#include "globalVariables.h"
#include "InitializeFirstGameState.h"


void Modes::InitializeFirstGameState(){
    InitWindow(screenWidth, screenHeight, pogi);
    
    // Game required variables
    state = READY ;       // Current game screen state
    

    leftPlayer.health = MAXHEALTH;
    rightPlayer.health = MAXHEALTH;

    SetExitKey(0);


    
        
    SetTargetFPS(144);               // Set desired framerate (frames per second)
}
#include "globalVariables.h"
#include "InitializeFirstGameState.h"


void Modes::InitializeFirstGameState(){
    // LESSON 01: Window initialization and screens management
    InitWindow(screenWidth, screenHeight, pogi);
    
    // NOTE: Load resources (textures, fonts, audio) after Window initialization

    // Game required variables
    state = READY ;       // Current game screen state
    
    // int framesCounter = 0;          // General pourpose frames counter
    // int gameResult = -1;            // Game result: 0 - Loose, 1 - Win, -1 - Not defined
    // bool gamePaused = false;        // Game paused state toggle
    
    // TODO: Define and Initialize game variables
    leftPlayer.health = MAXHEALTH;
    rightPlayer.health = MAXHEALTH;

    
        
    SetTargetFPS(60);               // Set desired framerate (frames per second)
}
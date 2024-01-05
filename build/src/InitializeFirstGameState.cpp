#include "globalVariables.h"
#include "InitializeFirstGameState.h"


void Modes::InitializeFirstGameState(){
    InitWindow(screenWidth, screenHeight, pogi);
    
    // Game required variables
    state = READY ;       // Current game screen state
    

    leftPlayer.health = MAXHEALTH;
    rightPlayer.health = MAXHEALTH;

    SetExitKey(0);
    SetTargetFPS(90);              
    

    // set the environment
    const char* prev_dir = GetWorkingDirectory();
    const char* application_dir = GetApplicationDirectory();

    ChangeDirectory(application_dir);

    /*----------------loading assets ----------------------------------*/

    image = LoadImage("../resources/textures/instructions.png");     // Loaded in CPU memory (RAM)
    texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)

    /*****************************************/
    InitAudioDevice();
    music = LoadMusicStream("../resources/sfx/bg.mp3");
    sfx_bruh= LoadSound("../resources/sfx/wav/bruh.wav");
    sfx_legit = LoadSound("../resources/sfx/wav/legit.wav");
    sfx_meow = LoadSound("../resources/sfx/wav/meow.wav");
    sfx_oof = LoadSound("../resources/sfx/wav/oof.wav");
    sfx_meow_sad = LoadSound("../resources/sfx/wav/meow_sad.wav");
    sfx_meow_angry = LoadSound("../resources/sfx/wav/meow_angry.wav");


    /*****************************************************************/
    ChangeDirectory(prev_dir);                  // revert back to the directory

    PlayMusicStream(music);
}



void Modes::DeInitialize(){
    UnloadImage(image);
    UnloadTexture(texture);

    UnloadSound(sfx_meow);
    UnloadSound(sfx_bruh);
    UnloadSound(sfx_legit);
    UnloadSound(sfx_oof);


    StopMusicStream(music);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();              // Close window and OpenGL context
}

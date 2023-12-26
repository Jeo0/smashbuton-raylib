//#include <iostream>
#include "raylib.h"
#include "initializeAll.hpp" 

int main()
{
    InitializeAll();
    // initialize

    /* initialize players */
    Player leftPlayer = Player(KEY_W, KEY_A, KEY_S, KEY_D);
    Player rightPlayer = Player(KEY_I, KEY_J, KEY_K, KEY_L);


    pogisijessie = GetRandomValue(21, 179);
    // generate addends
    leftPlayer.addends1 = pogisijessie - GetRandomValue(21, 179);
    

    while(!WindowShouldClose()){
        // update game state

        if(IsKeyPressed(KEY_SPACE)){
            space = !space;
        }

        // draw game
        BeginDrawing();
            ClearBackground(WHITE);         /* start from a white background */



            
            if(space)
                DrawText("i am spaced", GetScreenWidth()/2, GetScreenHeight()/2, (screenHeight/2) * 0.4, BLACK   );

            DrawFPS(10,10);
        EndDrawing();
    }
    //std::cout << std::endl <<  std::endl << typeid(KEY_B).name();

}
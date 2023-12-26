//#include <iostream>
#include "raylib.h"
#include "initializeAll.hpp" 

int main()
{
    InitializeAll();
    // initialize

   

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
#include <iostream>
#include "raylib.h"
#include "initializeAll.hpp" 

int main()
{
    // initialize
    InitializeAll();
    bool matchFlag = false;
    bool lkey1 = false, lkey2 = false, lkey3 = false, lkey4 = false;
    bool rkey1 = false, rkey2 = false, rkey3 =  false, rkey4 = false;

    while(!WindowShouldClose()){
        
        if(IsKeyPressed(KEY_SPACE)){
            pause = !pause;
        }
        if(!pause){
            // update game state
            lkey1 = false; lkey2 = false; lkey3 =  false; lkey4 = false;
            if (IsKeyDown(leftPlayer.key1)) lkey1 = true;
            if (IsKeyDown(leftPlayer.key2)) lkey2 = true;
            if (IsKeyDown(leftPlayer.key3)) lkey3 = true;
            if (IsKeyDown(leftPlayer.key4)) lkey4 = true;
            
            rkey1 = false; rkey2 = false; rkey3 =  false; rkey4 = false;
            if (IsKeyDown(rightPlayer.key1)) rkey1 = true;
            if (IsKeyDown(rightPlayer.key2)) rkey2 = true;
            if (IsKeyDown(rightPlayer.key3)) rkey3 = true;
            if (IsKeyDown(rightPlayer.key4)) rkey4 = true;
        }



        // draw game
        BeginDrawing();
            ClearBackground(WHITE);         /* start from a white background */

            // show options
            if(lkey1) DrawText("w", 50, 50, 50, BLUE);
            if(lkey2) DrawText("a", 35, 75, 50, BLUE);
            if(lkey3) DrawText("s", 50, 75, 50, BLUE);
            if(lkey4) DrawText("d", 75, 75, 50, BLUE);

            if(rkey1) DrawText("i", 50+50, 50+50, 50, BLUE);
            if(rkey2) DrawText("j", 35+50, 75+50, 50, BLUE);
            if(rkey3) DrawText("k", 50+50, 75+50, 50, BLUE);
            if(rkey4) DrawText("l", 75+50, 75+50, 50, BLUE);
            // match point
            if(lkey2 && lkey1){
                matchFlag = true;
                leftPlayer.point++;
            }
            else if(rkey2 && rkey1){
                matchFlag = true;
                rightPlayer.point++;
            }
            else pause = false;
            
            if(pause)
                DrawText("pause", GetScreenWidth()/2, GetScreenHeight()/2, (screenHeight/2) * 0.4, BLACK   );
            if(matchFlag){
                DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth()/2, GetScreenHeight() * 0.25, 50, ORANGE);

            DrawFPS(10,10);
        EndDrawing();
        continue;
            }
            
            
            
            //DrawText(TextFormat("%i", leftPlayer.point), 100, 100, 50, ORANGE);
            DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth()/2, GetScreenHeight() * 0.25, 50, ORANGE);
            DrawFPS(10,10);
        EndDrawing();
    }
    //std::cout << std::endl <<  std::endl << typeid(KEY_B).name();

}
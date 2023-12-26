#include <iostream>
#include "raylib.h"
#include "initializeAll.hpp" 

int main()
{
    // initialize
    InitializeAll();
    bool matchFlag = false;
    bool lkey1 = false, lkey2 = false, lkey3 = false, lkey4 = false;
    bool larray[2] = {};
    uint index = 0;

    while(!WindowShouldClose()){
        
        if(IsKeyPressed(KEY_SPACE)){
            pause = !pause;
            matchFlag = false;
        }
        if(!pause){
            // update game state
            lkey1 = false; lkey2 = false; lkey3 =  false; lkey4 = false;
            if (IsKeyPressed(leftPlayer.key1)) lkey1 = true; 
            if (IsKeyPressed(leftPlayer.key2)) lkey2 = true;
            if (IsKeyPressed(leftPlayer.key3)) lkey3 = true;
            if (IsKeyPressed(leftPlayer.key4)) lkey4 = true;


            /* flush*/
            if(index>=2){
                index = 0;
                larray[0] = false;
                larray[1] = false;
                
            }


            // record if key is pressed 
            // AND if the values in the record will equate to the pogisijessie
            if(lkey1 && (pogisijessie - leftPlayer.addends1 == leftPlayer.addends2)) larray[index] = lkey1;
            if(lkey2 && (pogisijessie - leftPlayer.addends2 == leftPlayer.addends1)) larray[index] = lkey2;
            if(lkey3 && (pogisijessie - leftPlayer.useless1 == leftPlayer.useless2)) larray[index] = lkey3;
            if(lkey4 && (pogisijessie - leftPlayer.useless2 == leftPlayer.useless1)) larray[index] = lkey4;
            if(lkey1 || lkey2 || lkey3 || lkey4) index++;


            // evaluate
            if(larray[0] && larray[1]){
                matchFlag = true;
                leftPlayer.point++;
            }
            DrawText(TextFormat("index 0: %i", larray[0]), GetScreenWidth()/2, GetScreenHeight() * 0.9, 36, ORANGE);
            DrawText(TextFormat("index 1: %i", larray[1]), GetScreenWidth()/2, GetScreenHeight() * 0.95, 36, ORANGE);

        }



        // draw game
        BeginDrawing();
            ClearBackground(WHITE);         /* start from a white background */

            // show key inputs when pressed
            if(lkey1) DrawText("w", 50, 50, 50, BLUE);
            if(lkey2) DrawText("a", 35, 75, 50, BLUE);
            if(lkey3) DrawText("s", 50, 75, 50, BLUE);
            if(lkey4) DrawText("d", 75, 75, 50, BLUE);

            leftPlayer.DrawOptions();
            // match point
            /* if match is end; do pause
            */
            //if(matchFlag){
                //pause = true;
            //}
            
            if(pause)
                DrawText("pause", GetScreenWidth()/2, GetScreenHeight()/2, (screenHeight/2) * 0.4, BLACK   );

            /* if match is done, pause */
            if(matchFlag){
                pause = true;
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
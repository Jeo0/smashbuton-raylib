#include <iostream>
#include "raylib.h"
#include "initializeAll.hpp" 

int main()
{
    // initialize
    InitWindow(screenWidth, screenHeight, pogi);
    InitializeAll();
    bool matchFlag = false;
    bool coolDownMode = true;
    bool showDownMode = false;
    uint lkey1=0, lkey2=0, lkey3=0, lkey4=0;
    uint larray[2] = {};
    uint index = 0;
    startTime = GetTime();
    double timeElapsed = 0;

    while(!WindowShouldClose()){
        
        if(IsKeyPressed(KEY_SPACE)){
            pause = !pause;
            matchFlag = false;
        }
        /*  ----------------------------- while it is not paused, do these code block ------------------------- */
        if(!pause){
            // update game state
            // bind the keyboard input into a value
            /* ------------------------- TODO: make these bindings random -------------------------*/
           lkey1=0;lkey2=0;lkey3=0;lkey4=0;
           if(IsKeyPressed(leftPlayer.key1)) lkey1 = leftPlayer.addends1;
           if(IsKeyPressed(leftPlayer.key2)) lkey2 = leftPlayer.addends2;
           if(IsKeyPressed(leftPlayer.key3)) lkey3 = leftPlayer.useless1;
           if(IsKeyPressed(leftPlayer.key4)) lkey4 = leftPlayer.useless2;



            /* flush*/
            if(index>=2){
                index = 0;
                larray[0] = 0;
                larray[1] = 0;
                
            }


            // record if key is pressed 
            // AND if the values in the record will equate to the pogisijessie
            // and if the previous key is not the same key pressed
            if(lkey1 && lkey1 != larray[0]) {
                larray[index] = lkey1; 
                index++;}
            if(lkey2 && lkey2 != larray[0]) {
                larray[index] = lkey2;
                index++;}
            if(lkey3 && lkey3 != larray[0]) {
                larray[index] = lkey3;
                index++;}
            if(lkey4 && lkey4 != larray[0]) {
                larray[index] = lkey4;
                index++;}


            // evaluate
            if(larray[0] + larray[1] == pogisijessie){
                matchFlag = true;
                leftPlayer.point++;
            }
            DrawText(TextFormat("index 0: %i", larray[0]), GetScreenWidth()/2, GetScreenHeight() * 0.9, 36, ORANGE);
            DrawText(TextFormat("index 1: %i", larray[1]), GetScreenWidth()/2, GetScreenHeight() * 0.95, 36, ORANGE);

        }



        // draw game
        BeginDrawing();
            ClearBackground(WHITE);         /* start from a white background */
            /*  ----------- draw the pogisijessie   -------------------*/
            DrawText(TextFormat("%i", pogisijessie), GetScreenWidth()/2, GetScreenHeight() * 0.1, 100, BLUE);
            //DrawText(TextFormat("timeElapsed %i", timeElapsed), GetScreenWidth()*.1, GetScreenHeight() * 0.9, 50, RED);

            // show key inputs when pressed
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.original_one)) DrawText("w", 50, 50, 50, BLUE);
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.original_two)) DrawText("a", 35, 75, 50, BLUE);
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.original_three)) DrawText("s", 50, 75, 50, BLUE);
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.original_four)) DrawText("d", 75, 75, 50, BLUE);

            // match point
            /* if match is end; do pause */
            
            if(pause)
                DrawText("pause", GetScreenWidth()/2, GetScreenHeight()/2, (screenHeight/2) * 0.4, BLACK   );

            /* if match is done, pause */
            if(matchFlag){
                // pause
                DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth()/2, GetScreenHeight() * 0.25, 50, ORANGE);

                //MatchInitialize();
                GenerateNew_pogisijessie();

                GenerateNew_numbers();      // generate addends
                leftPlayer.RandomizeBindings(KEY_W, KEY_A, KEY_S, KEY_D);
                DrawFPS(10,10);
                EndDrawing();
                timeElapsed = GetTime() - startTime;
                continue;
            }

            leftPlayer.DrawOptions();
            DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);
            DrawFPS(10, 10);
        EndDrawing();
        timeElapsed = GetTime() - startTime;

    }

}
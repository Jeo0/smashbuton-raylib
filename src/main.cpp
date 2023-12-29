#include <iostream>
#include <chrono>
#include "raylib.h"
#include "initializeAll.hpp" 

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

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
    //startTime = GetTime();
    // initialize starting time 
    auto t1 = high_resolution_clock::now();
    auto t2 = high_resolution_clock::now();
    auto timeElapsed = duration_cast<milliseconds>(t2-t1);

    //auto timeElapsed = 0;

    while(!WindowShouldClose()){
        t2 = high_resolution_clock::now();
        timeElapsed = duration_cast<milliseconds>(t2-t1);
        
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
            if(lkey1 && leftPlayer.key1 != IsKeyPressed(leftPlayer.key1)) {
                larray[index] = lkey1; 
                index++;}
            if(lkey2 && leftPlayer.key2 != IsKeyPressed(leftPlayer.key2)) {
                larray[index] = lkey2;
                index++;}
            if(lkey3 && leftPlayer.key3 != IsKeyPressed(leftPlayer.key3)) {
                larray[index] = lkey3;
                index++;}
            if(lkey4 && leftPlayer.key4 != IsKeyPressed(leftPlayer.key4)) {
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
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.key1)) DrawText(TextFormat("%c", leftPlayer.key1), 50, 50, 50, BLUE);
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.key2)) DrawText(TextFormat("%c", leftPlayer.key2), 35, 75, 50, BLUE);
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.key3)) DrawText(TextFormat("%c", leftPlayer.key3), 50, 75, 50, BLUE);
            if((lkey1 || lkey2 || lkey3 || lkey4) && IsKeyPressed(leftPlayer.key4)) DrawText(TextFormat("%c", leftPlayer.key4), 75, 75, 50, BLUE);

            // match point
            /* if match is end; do pause */
            
            if(pause)
                DrawText("pause", GetScreenWidth()/2, GetScreenHeight()/2, (screenHeight/2) * 0.4, BLACK   );

            /* if match is done, pause */
            if(matchFlag){
                // pause
                DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth()/2, GetScreenHeight() * 0.25, 50, ORANGE);

                //MatchInitialize();
                pogisijessie = GenerateNew_pogisijessie();

                GenerateNew_numbers();      // generate addends

                DrawFPS(10,10);
                EndDrawing();

                continue;
            }

            if (timeElapsed.count() >= 1000){
                t1 = high_resolution_clock::now();                          // new timer
                //timeElapsed = std::chrono::milliseconds::zero();          // reset the timer to zero
            }


            leftPlayer.DrawOptions();
            DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);
            DrawFPS(10, 10);
            //DrawText(TextFormat("timeElapsed %u", timeElapsed), GetScreenWidth()*.1, GetScreenHeight() * 0.9, 30, RED);
            //DrawText(TextFormat("t2 %u", t2), GetScreenWidth()*.1, GetScreenHeight() * 0.8, 30, RED);
        EndDrawing();
        //timeElapsed = GetTime() - startTime;

    }

}
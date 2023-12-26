#include "raylib.h"
#include "raymath.h"
#include <iostream>


#include "initializeAll.hpp"


void InitializeAll(){

    InitWindow(screenWidth, screenHeight, pogi);
     /* initialize players */


    pogisijessie = GetRandomValue(MINPOGISIJESSIE, MAXPOGISIJESSIE);
    // generate addends
    leftPlayer.addends1 = pogisijessie - GetRandomValue(MINPOGISIJESSIE+1, pogisijessie);
    leftPlayer.addends2 = pogisijessie - leftPlayer.addends1;
    leftPlayer.useless1 = GetRandomValue(leftPlayer.addends1, leftPlayer.addends2);
    leftPlayer.useless2 = GetRandomValue(leftPlayer.addends1, leftPlayer.addends2);
            DrawText(TextFormat("index 0: %i", larray[0]), GetScreenWidth()/2, GetScreenHeight() * 0.9, 36, ORANGE);
            DrawText(TextFormat("index 1: %i", larray[1]), GetScreenWidth()/2, GetScreenHeight() * 0.95, 36, ORANGE);
    std::cout << "\n\n\npogisijessie " << pogisijessie;
    std::cout << "\n\n\naddends1 " << leftPlayer.addends1;
    std::cout << "\n\n\naddends2 " << leftPlayer.addends2;
    std::cout << "\n\n\nuseless1 " << leftPlayer.useless1;
    std::cout << "\n\n\nuseless2 " << leftPlayer.useless2;


    SetTargetFPS(30);

    /* game state variables*/
    pause = false;
    leftPlayer.point = 0;
    rightPlayer.point = 0;


}

// definition
Player::Player(uint one, uint two, uint three, uint four){
    // randomize
    key1 = one; 
    key2 = two; 
    key3 = three; 
    key4 = four;
}

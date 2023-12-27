#include "raylib.h"
#include "raymath.h"
#include <iostream>


#include "initializeAll.hpp"


void InitializeAll(){

     /* initialize players */

    GenerateNew_pogisijessie();
    // generate addends
    leftPlayer.addends1 = pogisijessie - GetRandomValue(MINPOGISIJESSIE+1, pogisijessie);
    leftPlayer.addends2 = pogisijessie - leftPlayer.addends1;
    leftPlayer.useless1 = GetRandomValue(leftPlayer.addends1, leftPlayer.addends2);
    leftPlayer.useless2 = GetRandomValue(leftPlayer.addends1, leftPlayer.addends2);
    //std::cout << "\n\n\npogisijessie " << pogisijessie;
    /*
    std::cout << "\n\n\naddends1 " << leftPlayer.addends1;
    std::cout << "\n\n\naddends2 " << leftPlayer.addends2;
    std::cout << "\n\n\nuseless1 " << leftPlayer.useless1;
    std::cout << "\n\n\nuseless2 " << leftPlayer.useless2;
    */


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

void Player::DrawOptions(){
    DrawText(TextFormat("%i", pogisijessie), GetScreenWidth()/2, GetScreenHeight() * 0.1, 100, BLUE);
    DrawText(TextFormat("w: %i", leftPlayer.addends1), 100, GetScreenHeight() * 0.2, 50, ORANGE);
    DrawText(TextFormat("a: %i", leftPlayer.addends2), 100, GetScreenHeight() * 0.4, 50, ORANGE);
    DrawText(TextFormat("s: %i", leftPlayer.useless1), 100, GetScreenHeight() * 0.6, 50, ORANGE);
    DrawText(TextFormat("d: %i", leftPlayer.useless2), 100, GetScreenHeight() * 0.8, 50, ORANGE);
}

uint GenerateNew_pogisijessie(){
    pogisijessie = GetRandomValue(MINPOGISIJESSIE, MAXPOGISIJESSIE);
    return pogisijessie;
}
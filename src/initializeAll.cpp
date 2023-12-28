#include "raylib.h"
#include "raymath.h"
#include <iostream>


#include "initializeAll.hpp"


void InitializeAll(){

    GenerateNew_pogisijessie();
    GenerateNew_numbers();      // generate addends
    SetTargetFPS(50);

    /* game state variables*/
    pause = false;
    leftPlayer.point = 0;
    rightPlayer.point = 0;

}

// definition
Player::Player(uint one, uint two, uint three, uint four){
    // randomize
    RandomizeBindings(one, two, three, four);
    original_one = one;
    original_two = two; 
    original_three = three;
    original_four = four;
}


void Player::RandomizeBindings(uint one, uint two, uint three, uint four){
    uint arrayOfInputs[4] = {one, two, three, four};

    //srand( GetRandomValue(0, 120) );
    for (int i = 3; i > 0; i--)
    {

        int j = GetRandomValue(0, 120) % i;
        arrayOfInputs[i] = arrayOfInputs[i] + arrayOfInputs[j];
        arrayOfInputs[j] = arrayOfInputs[i] - arrayOfInputs[j];
        arrayOfInputs[i] = arrayOfInputs[i] - arrayOfInputs[j];
    }
    
    key1 = arrayOfInputs[0]; 
    key2 = arrayOfInputs[1]; 
    key3 = arrayOfInputs[2]; 
    key4 = arrayOfInputs[3];
}

void Player::DrawOptions(){
    DrawText(TextFormat("%c: %i", leftPlayer.key1, leftPlayer.addends1), 100, GetScreenHeight() * 0.2, 50, ORANGE);
    DrawText(TextFormat("%c: %i", leftPlayer.key2, leftPlayer.addends2), 100, GetScreenHeight() * 0.4, 50, ORANGE);
    DrawText(TextFormat("%c: %i", leftPlayer.key3, leftPlayer.useless1), 100, GetScreenHeight() * 0.6, 50, ORANGE);
    DrawText(TextFormat("%c: %i", leftPlayer.key4, leftPlayer.useless2), 100, GetScreenHeight() * 0.8, 50, ORANGE);
}

uint GenerateNew_pogisijessie(){
    pogisijessie = GetRandomValue(MINPOGISIJESSIE, MAXPOGISIJESSIE);
    return pogisijessie;
}

void GenerateNew_numbers(){
    leftPlayer.addends1 = pogisijessie - GetRandomValue(MINPOGISIJESSIE+1, pogisijessie);
    leftPlayer.addends2 = pogisijessie - leftPlayer.addends1;
    leftPlayer.useless1 = GetRandomValue(leftPlayer.addends1+1, leftPlayer.addends2+1);
    leftPlayer.useless2 = GetRandomValue(leftPlayer.useless1+1, leftPlayer.addends2+2);

}

void MatchInitialize(){
    GenerateNew_pogisijessie();
    GenerateNew_numbers();      // generate addends

    WaitFor_xseconds(startTime, 1);
    // proceed drawing pogisijessie 
    WaitFor_xseconds(startTime, 2.5);
    leftPlayer.DrawOptions();

    /* game state variables*/
    pause = false;
}

void WaitFor_xseconds(float startTime, float xtime){
    startTime += GetFrameTime();
    if (startTime >= xtime){
        startTime = 0;
    }
    else{
        EndDrawing();
        //continue;
    }
    
}
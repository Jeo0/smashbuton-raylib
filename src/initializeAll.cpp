#include "raylib.h"
#include "raymath.h"
#include <iostream>


#include "initializeAll.hpp"


void InitializeAll(){

    pogisijessie = GenerateNew_pogisijessie();
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
    //RandomizeBindings(one, two, three, four);
    //RandomizeNumbers(key1, key2, key3, key4);
    key1 = one;
    key2 = two;
    key3 = three;
    key4 = four;
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

void Player::RandomizeNumbers(uint add1, uint add2, uint sls1, uint sls2){
    uint arrayOfNumbers[4] = {add1, add2, sls1, sls2};
    for (int i = 3; i > 0; i--){

        int j = GetRandomValue(0, 120) % i;
        arrayOfNumbers[i] = arrayOfNumbers[i] + arrayOfNumbers[j];
        arrayOfNumbers[j] = arrayOfNumbers[i] - arrayOfNumbers[j];
        arrayOfNumbers[i] = arrayOfNumbers[i] - arrayOfNumbers[j];
    }
    leftPlayer.addends1 = arrayOfNumbers[0];
    leftPlayer.addends2 = arrayOfNumbers[1];
    leftPlayer.useless1 = arrayOfNumbers[2];
    leftPlayer.useless2 = arrayOfNumbers[3];
}

void Player::DrawOptions(){
    /*
    DrawText(TextFormat("%c: %i", leftPlayer.key1, leftPlayer.addends1), 100, GetScreenHeight() * 0.2, 50, ORANGE);
    DrawText(TextFormat("%c: %i", leftPlayer.key2, leftPlayer.addends2), 100, GetScreenHeight() * 0.4, 50, ORANGE);
    DrawText(TextFormat("%c: %i", leftPlayer.key3, leftPlayer.useless1), 100, GetScreenHeight() * 0.6, 50, ORANGE);
    DrawText(TextFormat("%c: %i", leftPlayer.key4, leftPlayer.useless2), 100, GetScreenHeight() * 0.8, 50, ORANGE);
    */

    DrawText(TextFormat("w: %i", addends1), 100, GetScreenHeight() * 0.2, 50, ORANGE);
    DrawText(TextFormat("a: %i", addends2), 100, GetScreenHeight() * 0.4, 50, ORANGE);
    DrawText(TextFormat("s: %i", useless1), 100, GetScreenHeight() * 0.6, 50, ORANGE);
    DrawText(TextFormat("d: %i", useless2), 100, GetScreenHeight() * 0.8, 50, ORANGE);
}

uint GenerateNew_pogisijessie(){
    uint what = GetRandomValue(MINPOGISIJESSIE, MAXPOGISIJESSIE);
    return what;
}

void GenerateNew_numbers(){
    // generate numbers
    leftPlayer.addends1 = pogisijessie - GetRandomValue(MINPOGISIJESSIE+1, pogisijessie);
    leftPlayer.addends2 = pogisijessie - leftPlayer.addends1;
    leftPlayer.useless1 = GetRandomValue(leftPlayer.addends1+1, leftPlayer.addends2+1);
    leftPlayer.useless2 = GetRandomValue(leftPlayer.useless1+1, leftPlayer.addends2+2);

    // shuffle the numbers
    uint arrayOfNumbers[4] = {leftPlayer.addends1,
                            leftPlayer.addends2,
                            leftPlayer.useless1,
                            leftPlayer.useless2};
    for (int i = 3; i > 0; i--){

        int j = GetRandomValue(0, 120) % i;
        arrayOfNumbers[i] = arrayOfNumbers[i] + arrayOfNumbers[j];
        arrayOfNumbers[j] = arrayOfNumbers[i] - arrayOfNumbers[j];
        arrayOfNumbers[i] = arrayOfNumbers[i] - arrayOfNumbers[j];
    }

    // reassign the numbers to the shuffled nunmbers
    leftPlayer.addends1 = arrayOfNumbers[0];
    leftPlayer.addends2 = arrayOfNumbers[1];
    leftPlayer.useless1 = arrayOfNumbers[2];
    leftPlayer.useless2 = arrayOfNumbers[3];


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
#include "raylib.h"
#include "raymath.h"
#include <iostream>


#include "initializeAll.hpp"


void InitializeAll(){

    gameMatch.GenerateNew_pogisijessie();
    gameMatch.GenerateNew_numbers();      // generate addends
    SetTargetFPS(50);

    /* game state variables*/
    pause = false;
    leftPlayer.point = 0;
    rightPlayer.point = 0;
    leftPlayer.health = 20;
    rightPlayer.health = 20;

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
    DrawText(TextFormat("%c: %i", key1, addends1), 100, GetScreenHeight() * 0.2, 50, ORANGE);
    DrawText(TextFormat("%c: %i", key2, addends2), 100, GetScreenHeight() * 0.4, 50, ORANGE);
    DrawText(TextFormat("%c: %i", key3, useless1), 100, GetScreenHeight() * 0.6, 50, ORANGE);
    DrawText(TextFormat("%c: %i", key4, useless2), 100, GetScreenHeight() * 0.8, 50, ORANGE);
}

void GameMatch::GenerateNew_pogisijessie(){
    pogisijessie = GetRandomValue(MINPOGISIJESSIE, MAXPOGISIJESSIE);
}

void GameMatch::GenerateNew_numbers(){
    // generate numbers
    leftPlayer.addends1 = pogisijessie - GetRandomValue(MINPOGISIJESSIE+1, pogisijessie-2);
    leftPlayer.addends2 = pogisijessie - leftPlayer.addends1;
    leftPlayer.useless1 = GetRandomValue(leftPlayer.addends1+1, leftPlayer.addends2+1);
    leftPlayer.useless2 = GetRandomValue(leftPlayer.useless1+1, leftPlayer.addends2+2);

    /* store the numbers in an array 
     * shuffle the array
     */
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
    //GenerateNew_pogisijessie();
    //GenerateNew_numbers();      // generate addends

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
GameMatch::GameMatch(bool pause, bool readyMode, bool coolDownMode, bool showDownMode, bool rewardingMode){
    pause = pause;
    readyMode = readyMode;
    coolDownMode = coolDownMode;
    showDownMode = showDownMode;
    rewardingMode = rewardingMode;
}

void GameMatch::Pause(){
    gameMatch.pause = !gameMatch.pause;
}
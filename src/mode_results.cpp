#include "globalVariables.h"

void Player::DrawResults(char whatPosition){
    if(whatPosition == 'L'){
        DrawText(TextFormat("%c\n\n\n\n\n\n%c\n\n\n\n\n\n%c\n\n\n\n\n\n%c", key1, key2, key3, key4), GetScreenWidth()/2, GetScreenHeight()/2-100, 50, BLACK);
        DrawText("winds", GetScreenWidth()/2, GetScreenHeight()/2+100, 100, BLACK);
    }
    else{
        DrawText(TextFormat("%c\n\n\n\n\n\n%c\n\n\n\n\n\n%c\n\n\n\n\n\n%c", key1, key2, key3, key4), GetScreenWidth()/2, GetScreenHeight()/2-100, 50, BLACK);
        DrawText("winds", GetScreenWidth()/2, GetScreenHeight()/2+100, 100, BLACK);
    }
}


void Player::ResetPoints(){
    Player::point = 0;
}


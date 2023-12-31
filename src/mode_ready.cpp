#define POGIAKO
#ifndef POGIAKO
#include "globalVariables.h"

bool Player::CheckIfReady(){
    
    if(IsKeyPressed(key1)) lkey1 = 1;
    if(IsKeyPressed(key2)) lkey2 = 1;
    if(IsKeyPressed(key3)) lkey3 = 1;
    if(IsKeyPressed(key4)) lkey4 = 1;

    if (lkey1 && lkey2 && lkey3 && lkey4){
        lkey1 = 0; 
        lkey2 = 0;
        lkey3 = 0;
        lkey4 = 0;
        return true;
    }
    else   
        return false;
}


void Player::Draw_IsReady(char player){
    if(player == 'L'){
        Color left{245, 25, 25};
        float width = GetScreenWidth() * 0.4;
        float height = GetScreenHeight() * 0.8 * 0.25;
        float positionY = GetScreenHeight();
        int iii = 0;
        int posiY = 0.2;

        if(lkey1) {
            iii = 0;
            posiY = 0.2;

            DrawRectangle( 0, (float)positionY *posiY, width, height, 
                ColorAlpha(left, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key1), GetScreenWidth()/2-200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
        if(lkey2) {
            iii = 1;
            posiY = 0.4;
            DrawRectangle( 0, (float)positionY *posiY, width, height, 
                ColorAlpha(left, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key2), GetScreenWidth()/2-200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
        if(lkey3) {
            iii = 2;
            posiY = 0.6;
            DrawRectangle( 0, (float)positionY *posiY, width, height, 
                ColorAlpha(left, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key3), GetScreenWidth()/2-200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
        if(lkey4) {
            iii = 3;
            posiY = 0.8;
            DrawRectangle( 0, (float)positionY *posiY, width, height, 
                ColorAlpha(left, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key4), GetScreenWidth()/2-200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }

    }
    else if (player == 'R'){
        Color right{25, 100, 240};
        int width = GetScreenWidth() * 0.4;
        int height = GetScreenHeight() * 0.8 * 0.25;
        int positionY = GetScreenHeight();
        int positionX = GetScreenWidth() - width;
        int iii = 0;
        int posiY = 0.2;

        if(lkey1) {
            iii = 0;
            posiY = 0.2;

            DrawRectangle( positionX, positionY *posiY, width, height, 
                ColorAlpha(right, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key1), GetScreenWidth()/2+200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
        if(lkey2) {
            iii = 1;
            posiY = 0.4;
            DrawRectangle( positionX, positionY *posiY, width, height, 
                ColorAlpha(right, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key2), GetScreenWidth()/2+200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
        if(lkey3) {
            iii = 2;
            posiY = 0.6;
            DrawRectangle( positionX, positionY *posiY, width, height, 
                ColorAlpha(right, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key3), GetScreenWidth()/2+200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
        if(lkey4) {
            iii = 3;
            posiY = 0.8;
            DrawRectangle( positionX, positionY *posiY, width, height, 
                ColorAlpha(right, alpha[iii]));                              // background
            DrawText(TextFormat("%c", key4), GetScreenWidth()/2+200, GetScreenHeight() * posiY, 50,
                ColorAlpha({0,0,0}, alpha[iii]));                           // character binding
            if(alpha[iii] - 0.05f > 0)
                alpha[iii] -= 0.05f;
            else
                alpha[iii] = 0.0f;
        }
    }
}

void Player::ResetAlpha_and_lkey(){
    for(int index = 0; index<4; index++)
        alpha[index] = 1.0f;
    
}

#endif
#include "globalVariables.h"

bool Player::CheckIfReady(){
    
    if(IsKeyPressed(key1)) lkey1 = 1; 
    if(IsKeyPressed(key2)) lkey2 = 1;
    if(IsKeyPressed(key3)) lkey3 = 1;
    if(IsKeyPressed(key4)) lkey4 = 1;


    if (lkey1 && lkey2 && lkey3 && lkey4){
        return true;
    }
    else   
        return false;
}


void Player::Draw_IsReady(char player){
    Color left{245, 25, 25};
    Color right {45, 14, 230};
    if(player == 'L'){

        if(lkey1) {
            Draw_ready(player, left, 0, 0.2, key1);
            ReduceAlpha(0); }
        else    
            Draw_ready(player, left, 0, 0.2, key1);

        if(lkey2) {
            Draw_ready(player, left, 1, 0.4, key2);
            ReduceAlpha(1); }
        else  
            Draw_ready(player, left, 1, 0.4, key2);

        if(lkey3) {
            Draw_ready(player, left, 2, 0.6, key3);
            ReduceAlpha(2);}
        else
            Draw_ready(player, left, 2, 0.6, key3);

        if(lkey4) {
            Draw_ready(player, left, 3, 0.8, key4);
            ReduceAlpha(3);}
        else
            Draw_ready(player, left, 3, 0.8, key4);

    }
    else if (player == 'R'){

        if(lkey1) {
            Draw_ready(player, right, 0, 0.2, key1);
            ReduceAlpha(0); }
        else    
            Draw_ready(player, right, 0, 0.2, key1);

        if(lkey2) {
            Draw_ready(player, right, 1, 0.4, key2);
            ReduceAlpha(1); }
        else  
            Draw_ready(player, right, 1, 0.4, key2);

        if(lkey3) {
            Draw_ready(player, right, 2, 0.6, key3);
            ReduceAlpha(2);}
        else
            Draw_ready(player, right, 2, 0.6, key3);

        if(lkey4) {
            Draw_ready(player, right, 3, 0.8, key4);
            ReduceAlpha(3);}
        else
            Draw_ready(player, right, 3, 0.8, key4);

    }
}

void Player::ResetAlpha(){
    for(int x = 0; x<4; x++)
        alpha[x] = 1.0f;
}

void Player::Reset_lkey(){
    lkey1 = 0;
    lkey2 = 0;
    lkey3 = 0;
    lkey4 = 0;
}

void Player::Ready_check(){
    if(Player::CheckIfReady()){
        Player::amready = true;
    }
}

void Player::ReduceAlpha(uint iii){

    if(alpha[iii] - 0.05f > 0)
        alpha[iii] -= 0.05f;
    else{
        alpha[iii] = 0.0f;
        alphaflag = false;
    }
}

void Player::Draw_ready(char whatPosition, Color color, uint iindex, float posiY, uint keybind){
    float width = GetScreenWidth() * 0.3;
    float height = GetScreenHeight() * 0.8 * 0.25;


    if(whatPosition == 'L'){
        int positionY = GetScreenHeight();

        DrawRectangle( 0, positionY * posiY, width, height, 
            ColorAlpha(color, alpha[iindex]));                              // background
        DrawText(TextFormat("%c", keybind), GetScreenWidth()/2-200, GetScreenHeight() * posiY, 50,
            ColorAlpha({0,0,0}, alpha[iindex]));                           // character binding

    }
    else if (whatPosition == 'R'){
        int positionY = GetScreenHeight();

        DrawRectangle(GetScreenWidth()-width, positionY * posiY, width, height, 
            ColorAlpha(color, alpha[iindex]));                              // background
        DrawText(TextFormat("%c", keybind), GetScreenWidth()/2+200, GetScreenHeight() * posiY, 50,
            ColorAlpha({0,0,0}, alpha[iindex]));                           // character binding

    }
}
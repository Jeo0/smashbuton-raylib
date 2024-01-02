#include "globalVariables.h"
#include "mode_cooldown.h"

void Modes::GenerateNew_pogisijessie(){
    pogisijessie = GetRandomValue(MINPOGISIJESSIE, MAXPOGISIJESSIE);
}

void Player::DrawRegisters(char whatPosition){
    if(whatPosition == 'R'){
        DrawText(TextFormat("index 0: %i", Player::registers[0]), GetScreenWidth() / 2 + 400, GetScreenHeight() * 0.9, 36, ORANGE);
        DrawText(TextFormat("index 1: %i", Player::registers[1]), GetScreenWidth() / 2 + 400, GetScreenHeight() * 0.95, 36, ORANGE);
    }
    else{
        DrawText(TextFormat("index 0: %i", Player::registers[0]), GetScreenWidth() / 2 - 400, GetScreenHeight() * 0.9, 36, ORANGE);
        DrawText(TextFormat("index 1: %i", Player::registers[1]), GetScreenWidth() / 2 - 400, GetScreenHeight() * 0.95, 36, ORANGE);
    }
}

void Modes::DrawPogisijessie(){
    char text[] = "%i ";
    int size = 100;
    int spacing = 10;
    Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);

    DrawTextEx(GetFontDefault(), 
        TextFormat(text, pogisijessie), 
        {GetScreenWidth()/2 - (text_dim.x/2),
        ((float)(GetScreenHeight()*0.1)  - (text_dim.y/2))},
        size, spacing, BLUE);
    //DrawText(TextFormat("%i", pogisijessie), GetScreenWidth()/2, GetScreenHeight() * 0.1, 100, BLUE);
}

void Modes::GenerateNew_numbers(){
    // generate numbers
    leftPlayer.addends1 = pogisijessie - GetRandomValue(MINPOGISIJESSIE+1, pogisijessie-2);
    leftPlayer.addends2 = pogisijessie - leftPlayer.addends1;
    leftPlayer.useless1 = GetRandomValue(leftPlayer.addends1+1, leftPlayer.addends2+1);
    leftPlayer.useless2 = GetRandomValue(leftPlayer.useless1+1, leftPlayer.addends2+2);

    rightPlayer.addends1 = leftPlayer.addends1;
    rightPlayer.addends2 = leftPlayer.addends2;
    rightPlayer.useless1 = leftPlayer.useless1;
    rightPlayer.useless2 = leftPlayer.useless2;


    leftPlayer.ShuffleArray(leftPlayer.addends1, leftPlayer.addends2, leftPlayer.useless1, leftPlayer.useless2);
    rightPlayer.ShuffleArray(rightPlayer.addends1, rightPlayer.addends2, rightPlayer.useless1, rightPlayer.useless2);
}
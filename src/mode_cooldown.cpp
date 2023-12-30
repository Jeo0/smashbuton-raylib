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
    DrawText(TextFormat("%i", pogisijessie), GetScreenWidth()/2, GetScreenHeight() * 0.1, 100, BLUE);
}

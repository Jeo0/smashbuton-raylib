#include "globalVariables.h"

void Player::DrawResults(){
    char text[] = "%c\n\n\n\n\n%c\n\n\n\n\n%c\n\n\n\n\n%c";
    char wins[] = "winds";
    int size = 50;
    int spacing = 10;
    Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);
    Vector2 wins_dim = MeasureTextEx(GetFontDefault(), wins, size, spacing);

    DrawTextEx(GetFontDefault(), 
        TextFormat(text, key1, key2, key3, key4), 
        {GetScreenWidth()/2 - (text_dim.x/4),
        (GetScreenHeight()/2  - (text_dim.y/4) + GetScreenHeight()/22)},
        size, spacing, BLACK);
    DrawTextEx(GetFontDefault(), 
        wins,
        {GetScreenWidth()/2 - (wins_dim.x/2),
        (GetScreenHeight()/2  - (wins_dim.y/2) + GetScreenHeight()/14 )},
        size, spacing, BLACK);
}


void Player::ResetPoints(){
    Player::point = 0;
}


#include "globalVariables.h"

Player::Player(uint one, uint two, uint three, uint four){
    // randomized already
    key1 = one;
    key2 = two;
    key3 = three;
    key4 = four;
    
}


bool Modes::CheckIfPause(){
    if(IsKeyPressed(KEY_SPACE)){
        pause = !pause;
        return pause;
    }
    return pause;
}


void Modes::DrawInstructions(Gamephase nani){
    if(nani == SHOWDOWN){
        char text[] = "combine and spam two numbers to kil ur oponet";
        char plspause[] = "press SPACE to pause";
        int size = 20;
        int spacing = 3;
        Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);
        Vector2 plspause_dim= MeasureTextEx(GetFontDefault(), plspause, size, spacing);

        DrawTextEx(GetFontDefault(), text, 
            {GetScreenWidth()/2 - (text_dim.x/2),
            (GetScreenHeight()/2 - (text_dim.y/2) + (GetScreenHeight()/3))},
            size, spacing, {150,150,150,255});
        DrawTextEx(GetFontDefault(), plspause, 
            {GetScreenWidth()/2 - (plspause_dim.x/2),
            (GetScreenHeight()/2 - (plspause_dim.y/2) + (GetScreenHeight()/(2.5)))},
            size, spacing, {150,150,150,255});
    }
    if(nani == RESULTS){
        char text[] = "press ESC to restart";
        int size = 20;
        int spacing = 3;
        Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);

        DrawTextEx(GetFontDefault(), text, 
            {GetScreenWidth()/2 - (text_dim.x/2),
            (GetScreenHeight()/2 - (text_dim.y/2) + (GetScreenHeight()/3))},
            size, spacing, {150,150,150,255});
    }
    if(nani == PAUSE){
        char text[] = "press space to continue";
        int size = 20;
        int spacing = 3;
        Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);

        DrawTextEx(GetFontDefault(), text, 
            {GetScreenWidth()/2 - (text_dim.x/2),
            (GetScreenHeight()/2 - (text_dim.y/2) + (GetScreenHeight()/3))},
            size, spacing, {150,150,150,255});
    }
    if(nani == READY){
        char text[] = "^ press dese if u ready ^";
        int size = 20;
        int spacing = 3;
        Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);

        DrawTextEx(GetFontDefault(), text, 
            {GetScreenWidth()/2 - (text_dim.x/2),
            (GetScreenHeight()/2 - (text_dim.y/2) + (GetScreenHeight()/3))},
            size, spacing, {150,150,150,255});
    }
}



/*****************************************/
// audios

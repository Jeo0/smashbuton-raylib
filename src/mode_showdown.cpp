#include "globalvariables.h"
#include "mode_showdown.h"
#include <algorithm>
#include <iostream>

void Modes::DrawPoints(){
    char text[] = "%i : %i";
    int size = 50;
    int spacing = 10;
    Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, size, spacing);

    DrawTextEx(GetFontDefault(), 
        TextFormat(text, leftPlayer.point, rightPlayer.point), 
        {GetScreenWidth()/2 - (text_dim.x/4),
        (GetScreenHeight()/4  - (text_dim.y/2))},
        size, spacing, ORANGE);
    //DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);
}

void Modes::DrawShowdown() {
    mode.DrawPoints();

    mode.DrawPogisijessie();
    leftPlayer.DrawOptions('L');
    //leftPlayer.DrawRegisters('L');
    //leftPlayer.DrawAnimateRegisters('L');
    leftPlayer.DrawHealth('L');

    rightPlayer.DrawOptions('R');
    //rightPlayer.DrawRegisters('R');
    //rightPlayer.DrawAnimateRegisters('R');
    rightPlayer.DrawHealth('R');
}


void Player::DrawOptions(char whatPosition){
    if(whatPosition == 'R'){
        DrawText(TextFormat("%i :%c", addends1, key1), GetScreenWidth()*0.825, GetScreenHeight() * 0.2, 50, {18, 22, 121, 255});
        DrawText(TextFormat("%i :%c", addends2, key2), GetScreenWidth()*0.825, GetScreenHeight() * 0.4, 50, {18, 22, 121, 255} );
        DrawText(TextFormat("%i :%c", useless1, key3), GetScreenWidth()*0.825, GetScreenHeight() * 0.6, 50, {18, 22, 121, 255} );
        DrawText(TextFormat("%i :%c", useless2, key4), GetScreenWidth()*0.825, GetScreenHeight() * 0.8, 50, {18, 22, 121, 255} );
    }
    else {
        DrawText(TextFormat("%c: %i", key1, addends1), GetScreenWidth() * 0.1, GetScreenHeight() * 0.2, 50, {121, 18, 18, 255});
        DrawText(TextFormat("%c: %i", key2, addends2), GetScreenWidth() * 0.1, GetScreenHeight() * 0.4, 50, {121, 18, 18, 255});
        DrawText(TextFormat("%c: %i", key3, useless1), GetScreenWidth() * 0.1, GetScreenHeight() * 0.6, 50, {121, 18, 18, 255});
        DrawText(TextFormat("%c: %i", key4, useless2), GetScreenWidth() * 0.1, GetScreenHeight() * 0.8, 50, {121, 18, 18, 255});
    }
}

void Player::DrawAnimateRegisters(char whatPosition){
    float pos[4] {0.2, 0.4, 0.6, 0.8};

    float boxWidth = GetScreenWidth() * 0.3;
    float boxHeight = GetScreenHeight() * 0.8 * 0.25;

    
    if(index >0){
        previousKeymode = keymode;
    }

    // if(IsKeyPressed(key1))
    //     keymode = 0;
    // if(IsKeyPressed(key2))
    //     keymode = 1;
    // if(IsKeyPressed(key3))
    //     keymode = 2;
    // if(IsKeyPressed(key4))
    //     keymode = 3;

    if(whatPosition == 'L'){
        Color color {255,111,111};        // red
        //blackAlpha[keymode] = 1.0f;
        DrawRectangle(0, GetScreenHeight()*pos[keymode], boxWidth, boxHeight, 
            ColorAlpha(color, alpha[keymode]));

        DrawRectangle(0, GetScreenHeight()*pos[previousKeymode], boxWidth, boxHeight, 
            ColorAlpha(color, alpha[previousKeymode]));
        
    }

    else if(whatPosition == 'R'){
        Color color {111,198,255};        // blue

        DrawRectangle(GetScreenWidth()-boxWidth, GetScreenHeight()*pos[keymode], boxWidth, boxHeight, 
            ColorAlpha(color, alpha[keymode]));

        DrawRectangle(GetScreenWidth()-boxWidth, GetScreenHeight()*pos[previousKeymode], boxWidth, boxHeight, 
            ColorAlpha(color, alpha[previousKeymode]));
    }


}

void Player::ShuffleArray(uint one, uint two, uint three, uint four){
    // shuffle
    uint arrayOfNumbers[4] = {one, two, three, four};
    for (int i = 3; i > 0; i--){
        int j = GetRandomValue(0, 120) % i;
        arrayOfNumbers[i] = arrayOfNumbers[i] + arrayOfNumbers[j];
        arrayOfNumbers[j] = arrayOfNumbers[i] - arrayOfNumbers[j];
        arrayOfNumbers[i] = arrayOfNumbers[i] - arrayOfNumbers[j];
    }

    // reassign the numbers to the shuffled nunmbers
    Player::addends1 = arrayOfNumbers[0];
    Player::addends2 = arrayOfNumbers[1];
    Player::useless1 = arrayOfNumbers[2];
    Player::useless2 = arrayOfNumbers[3];
}

bool Modes::CheckIf_onePlayer_reached_5_matchPoints(){
    return (leftPlayer.point>=MAXPOINTS || rightPlayer.point >=MAXPOINTS);
}

bool Modes::CheckIf_showdownModeDone_andAdd_points(){
    // update player points
    if (leftPlayer.health<= 0){
        rightPlayer.point+=1;
        return true;
    }
    if(rightPlayer.health <=0) {
        leftPlayer.point+=1;
        return true;
    }

    return false;
}

void Modes::EvaluateShowdownMode(){
    // REDUCE right enemy's health if correct combi & + 1, else REDUCE left health 
    if(leftPlayer.registers[0] + leftPlayer.registers[1] == mode.pogisijessie && leftPlayer.index >= 2){
        rightPlayer.health -=2;
        leftPlayer.health +=1;
        leftPlayer.greenFlag = true;        // flag for drawing green

        // int keyIndex1 = std::distance(leftPlayer.registers, std::find(leftPlayer.registers, leftPlayer.registers + 2, leftPlayer.registers[0]));
        // int keyIndex2 = std::distance(leftPlayer.registers, std::find(leftPlayer.registers, leftPlayer.registers + 2, leftPlayer.registers[1]));

        // std::cout << keyIndex1 << std::endl << keyIndex2 << "\n\n"; 

        // leftPlayer.ReduceAlpha(keyIndex1);
        // leftPlayer.ReduceAlpha(keyIndex2);
        }
    else if(leftPlayer.registers[0] + leftPlayer.registers[1] != mode.pogisijessie && leftPlayer.index >= 2){
        leftPlayer.health -=2;
        
        // int keyIndex1 = std::distance(leftPlayer.registers, std::find(leftPlayer.registers, leftPlayer.registers + 2, leftPlayer.registers[0]));
        // int keyIndex2 = std::distance(leftPlayer.registers, std::find(leftPlayer.registers, leftPlayer.registers + 2, leftPlayer.registers[1]));

        // std::cout << keyIndex1 << std::endl << keyIndex2 << "\n\n"; 

        // leftPlayer.ReduceAlpha(keyIndex1);
        // leftPlayer.ReduceAlpha(keyIndex2);
    }

    // REDUCE left enemy's health if correct combi & +1, else REDUCE right health 
    if(rightPlayer.registers[0] + rightPlayer.registers[1] == mode.pogisijessie && rightPlayer.index >=2){
        leftPlayer.health -=2;
        rightPlayer.health +=1;
        rightPlayer.greenFlag = true;       // flag for drawing green


        // int keyIndex1 = std::distance(rightPlayer.registers, std::find(rightPlayer.registers, rightPlayer.registers + 2, rightPlayer.registers[0]));
        // int keyIndex2 = std::distance(rightPlayer.registers, std::find(rightPlayer.registers, rightPlayer.registers + 2, rightPlayer.registers[1]));

        // std::cout << keyIndex1 << std::endl << keyIndex2 << "\n\n"; 

        // rightPlayer.ReduceAlpha(keyIndex1);
        // rightPlayer.ReduceAlpha(keyIndex2);
        }
    else if(rightPlayer.registers[0] + rightPlayer.registers[1] != mode.pogisijessie && rightPlayer.index >=2){
        rightPlayer.health -=2;

        // int keyIndex1 = std::distance(rightPlayer.registers, std::find(rightPlayer.registers, rightPlayer.registers + 2, rightPlayer.registers[0]));
        // int keyIndex2 = std::distance(rightPlayer.registers, std::find(rightPlayer.registers, rightPlayer.registers + 2, rightPlayer.registers[1]));

        // std::cout << keyIndex1 << std::endl << keyIndex2 << "\n\n"; 

        // rightPlayer.ReduceAlpha(keyIndex1);
        // rightPlayer.ReduceAlpha(keyIndex2);
    }

}

void Player::Register(){
    
        int keyIndex1 = std::distance(registers, std::find(registers, registers + 2, registers[0]));
        int keyIndex2 = std::distance(registers, std::find(registers, registers + 2, registers[1]));
        /* -------------flush COOLDOWNMODE----------------------------- */
        /* -------------reset the flag when lkeyx is pressed------------*/
        if(index>=2){
            mode.EvaluateShowdownMode();    // first is this, then the index; 
                                            // we need to access the value of index inside evaluateshowdonmode function

            // ----------TODO I CANT REDUCE THE ALPHA FOR NOW
            
            alphaflag = true;
            ResetAlpha();
            previousKeymode= 6;
            keymode =6;


            index = 0;
            registers[0] = -1;
            registers[1] = -1;
            key1bool = false;
            key2bool = false;
            key3bool = false;
            key4bool = false;
        }

        // if(alphaflag==true){
        //     ReduceAlpha(3);
        //     ReduceAlpha(2);
        // }
        // record if key is pressed 
        // AND if the values in the record will equate to the pogisijessie
        // and if the previous key is not the same key pressed
        if(lkey1 && key1bool == false) {
            registers[index] = lkey1; 
            key1bool = true;
            index++;
            keymode = 0;}
        if(lkey2 && key2bool == false) {
            registers[index] = lkey2;
            key2bool = true;
            index++;
            keymode = 1;}
        if(lkey3 && key3bool == false) {
            registers[index] = lkey3;
            key3bool = true;
            index++;
            keymode = 2;}
        if(lkey4 && key4bool == false) {
            registers[index] = lkey4;
            key4bool = true;
            index++;
            keymode = 3;}
}

void Player::BindIfKeyPressed(){

    lkey1=0;lkey2=0;lkey3=0;lkey4=0;
    if(IsKeyPressed(key1) && lkey1 != registers[0]) {lkey1 = addends1; }
    if(IsKeyPressed(key2) && lkey2 != registers[0]) {lkey2 = addends2; }
    if(IsKeyPressed(key3) && lkey3 != registers[0]) {lkey3 = useless1; }
    if(IsKeyPressed(key4) && lkey4 != registers[0]) {lkey4 = useless2; }
    
}


void Player::DrawHealth(char whatPosition){
    if(whatPosition == 'R')
        DrawText(TextFormat("health: %i", Player::health), GetScreenWidth() * 0.8, GetScreenHeight() * 0.1, 30, RED);
        
    else 
        DrawText(TextFormat("health: %i", Player::health), GetScreenWidth() * 0.1, GetScreenHeight() * 0.1, 30, RED);
}

void Player::ResetHealth(){
    keymode = 6;
    previousKeymode = 6;
    ResetAlpha();

    Player::health = MAXHEALTH;
}



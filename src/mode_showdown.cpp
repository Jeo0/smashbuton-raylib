#include "globalVariables.h"
#include "mode_showdown.h"


void Player::DrawOptions(char whatPosition){
    if(whatPosition == 'R'){
        DrawText(TextFormat("%i :%c", addends1, key1), GetScreenWidth()*0.8, GetScreenHeight() * 0.2, 50, BLUE );
        DrawText(TextFormat("%i :%c", addends2, key2), GetScreenWidth()*0.8, GetScreenHeight() * 0.4, 50, BLUE );
        DrawText(TextFormat("%i :%c", useless1, key3), GetScreenWidth()*0.8, GetScreenHeight() * 0.6, 50, BLUE );
        DrawText(TextFormat("%i :%c", useless2, key4), GetScreenWidth()*0.8, GetScreenHeight() * 0.8, 50, BLUE );
    }
    else {
        DrawText(TextFormat("%c: %i", key1, addends1), 100, GetScreenHeight() * 0.2, 50, ORANGE);
        DrawText(TextFormat("%c: %i", key2, addends2), 100, GetScreenHeight() * 0.4, 50, ORANGE);
        DrawText(TextFormat("%c: %i", key3, useless1), 100, GetScreenHeight() * 0.6, 50, ORANGE);
        DrawText(TextFormat("%c: %i", key4, useless2), 100, GetScreenHeight() * 0.8, 50, ORANGE);
    }
}

void Player::DrawAnimateRegisters(char whatPosition){
    if(whatPosition == 'L'){

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
    return (leftPlayer.point>=5 || rightPlayer.point >=5);
}

bool Modes::CheckIf_showdownModeDone_andAdd_points(){
    // update player points
    if (leftPlayer.health<= 0){
        rightPlayer.point+=1;
        return true;
    }
    else if(rightPlayer.health <=0) {
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
        }
    else if(leftPlayer.registers[0] + leftPlayer.registers[1] != mode.pogisijessie && leftPlayer.index >= 2)
        leftPlayer.health -=2;

    // REDUCE left enemy's health if correct combi & +1, else REDUCE right health 
    if(rightPlayer.registers[0] + rightPlayer.registers[1] == mode.pogisijessie && rightPlayer.index >=2){
        leftPlayer.health -=2;
        rightPlayer.health +=1;
        rightPlayer.greenFlag = true;       // flag for drawing green
        }
    else if(rightPlayer.registers[0] + rightPlayer.registers[1] != mode.pogisijessie && rightPlayer.index >=2)
        rightPlayer.health -=2;
    


}

void Player::Register(){
    
        /* -------------flush COOLDOWNMODE----------------------------- */
        /* -------------reset the flag when lkeyx is pressed------------*/
        if(index>=2){
            mode.EvaluateShowdownMode();    // first is this, then the index; 
                                            // we need to access the value of index inside evaluateshowdonmode function
            index = 0;
            registers[0] = -1;
            registers[1] = -1;
            key1bool = false;
            key2bool = false;
            key3bool = false;
            key4bool = false;
        }
        // record if key is pressed 
        // AND if the values in the record will equate to the pogisijessie
        // and if the previous key is not the same key pressed
        if(lkey1 && key1bool == false) {
            registers[index] = lkey1; 
            key1bool = true;
            index++;}
        if(lkey2 && key2bool == false) {
            registers[index] = lkey2;
            key2bool = true;
            index++;}
        if(lkey3 && key3bool == false) {
            registers[index] = lkey3;
            key3bool = true;
            index++;}
        if(lkey4 && key4bool == false) {
            registers[index] = lkey4;
            key4bool = true;
            index++;}
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
        DrawText(TextFormat("health: %i", Player::health), GetScreenWidth() * 0.2, GetScreenHeight() * 0.1, 30, RED);
}

void Player::ResetHealth(){
    Player::health = MAXHEALTH;
}
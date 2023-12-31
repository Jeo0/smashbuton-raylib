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



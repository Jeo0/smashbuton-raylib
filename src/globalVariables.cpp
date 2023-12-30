#include "globalVariables.h"

Player::Player(uint one, uint two, uint three, uint four){
    // randomized already
    key1 = one;
    key2 = two;
    key3 = three;
    key4 = four;
}


void Modes::CheckIfPause_and_PauseAccordingly(){
    // pause if needed
    if(IsKeyPressed(KEY_SPACE)){
        pause = !pause;
    }

    // else dont change the state

}



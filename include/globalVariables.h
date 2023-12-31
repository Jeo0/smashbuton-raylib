#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#define MINPOGISIJESSIE 21
#define MAXPOGISIJESSIE 189

#define MAXHEALTH 40

#include "raylib.h"
#include "InitializeFirstGameState.h"

/* global typedefs */
typedef unsigned int uint;

/* game modes */
typedef enum { READY, COOLDOWN, SHOWDOWN, RESULTS, PAUSE} GamePhase;

class Modes{
public:
    /* things for manipulating game states */
    uint pogisijessie;
    bool pause = false;
    GamePhase state;     

    /* timer related functions */
    int t1, t2, timeElapsed;
    
    void InitializeFirstGameState();
    void GenerateNew_pogisijessie();
    void GenerateNew_numbers();
    void CheckIfPause_and_PauseAccordingly();
    bool CheckIf_onePlayer_reached_5_matchPoints();
    bool CheckIf_showdownModeDone_andAdd_points();
    void EvaluateShowdownMode();

    void DrawPogisijessie();

};
inline Modes mode;






/* player class */
class Player{
public:
    uint health;
    uint point;
    float allpha[4] {1.0f, 1.0f, 1.0f, 1.0f};
    bool amready = false;

    
    uint addends1, addends2, useless1, useless2;
    uint key1, key2, key3, key4;                    // w a s d i j k l
    bool key1bool=false, key2bool=false, key3bool=false, key4bool=false;    // responsible if wasdijkl is pressed
    uint lkey1=0, lkey2=0, lkey3=0, lkey4=0;        // for bindings flags
    uint index = 0;


    int registers[2] = {-1, -1};

    Player(uint, uint, uint, uint);
    void ShuffleArray(uint, uint, uint, uint);
    void BindIfKeyPressed();
    void Register();          // lkey1, lkey2, lkey3, lkey4
    void ResetHealth();
    void ResetAlpha_and_lkey();
    void ReduceAlpha(uint);                     // pass index
    void Draw_ready(char, Color, uint, float, uint);   // 

    bool CheckIfReady();
    void Ready_check();

    // if char == L, left;      char == R, right
    // default = left
    void DrawOptions(char);
    void DrawRegisters(char);
    void DrawHealth(char);
    void Draw_IsReady(char);
};
inline Player leftPlayer = Player(KEY_W, KEY_A, KEY_S, KEY_D);
inline Player rightPlayer = Player(KEY_I, KEY_J, KEY_K, KEY_L);


#endif
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#define MINPOGISIJESSIE 21
#define MAXPOGISIJESSIE 189


#define MAXHEALTH 40
#define MAXPOINTS 5

#include "raylib.h"
#include "InitializeFirstGameState.h"

/* global typedefs */
typedef unsigned int uint;

/* game modes */
typedef enum { READY, COOLDOWN, SHOWDOWN, RESULTS, PAUSE} GamePhase;

//char pause_str[] = "PAUSE";
//Vector2 PAUSE_DIM = MeasureTextEx(GetFontDefault(), pause_str, 100, 10);

class Modes{
public:
    /* things for manipulating game states */
    uint pogisijessie;
    bool pause = false;
    char winnerFlag = 'L';          // default
    GamePhase state;     

    //Image image;
    //Texture2D texture;

    /* timer related functions */
    int t1, t2, timeElapsed;
    
    void InitializeFirstGameState();
    void GenerateNew_pogisijessie();
    void GenerateNew_numbers();
    bool CheckIfPause();
    bool CheckIf_onePlayer_reached_5_matchPoints();
    bool CheckIf_showdownModeDone_andAdd_points();
    void EvaluateShowdownMode();

    void DrawPogisijessie();
    void DrawShowdown();
    void ShowInstructions();

};
inline Modes mode;
//inline Image image = LoadImage("textures/instructions.png");     // Loaded in CPU memory (RAM)
//inline Texture2D texture = LoadTextureFromImage(mode.image);          // Image converted to texture, GPU memory (VRAM)









/* player class */
class Player{
public:
    int health;
    uint point;
    float alpha[4] {1.0f, 1.0f, 1.0f, 1.0f};
    bool amready = false;

    
    uint addends1, addends2, useless1, useless2;
    uint key1, key2, key3, key4;                    // w a s d i j k l
    bool key1bool=false, key2bool=false, key3bool=false, key4bool=false;    // responsible if wasdijkl is pressed
    uint lkey1=0, lkey2=0, lkey3=0, lkey4=0;        // for bindings flags
    uint index = 0;


    int registers[2] = {-1, -1};
    bool greenFlag = false;                     // for drawing correct combination

    Player(uint, uint, uint, uint);
    void ShuffleArray(uint, uint, uint, uint);
    void BindIfKeyPressed();
    void Register();          // lkey1, lkey2, lkey3, lkey4
    void ResetHealth();
    void ResetAlpha();
    void Reset_lkey();
    void ReduceAlpha(uint);                     // pass index
    void Draw_ready(char, Color, uint, float, uint);   // 

    bool CheckIfReady();
    void Ready_check();
    void ResetPoints();

    // if char == L, left;      char == R, right
    // default = left
    void DrawOptions(char);
    void DrawRegisters(char);
    void DrawHealth(char);
    void Draw_IsReady(char);
    void DrawAnimateRegisters(char);
    void DrawResults(char);
};
inline Player leftPlayer = Player(KEY_W, KEY_A, KEY_S, KEY_D);
inline Player rightPlayer = Player(KEY_I, KEY_J, KEY_K, KEY_L);



class VOIDS : public Player{
public:
    VOIDS(uint, uint, uint, uint);
};

#endif
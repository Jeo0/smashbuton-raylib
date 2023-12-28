#ifndef INITIALIZEALL_HPP_
#define INITIALIZEALL_HPP_
#define MAXPOGISIJESSIE 179
#define MINPOGISIJESSIE 21


const int screenWidth = 800;
const int screenHeight = 600;
inline const char* pogi = "Smash";

typedef unsigned int uint;

inline bool pause;
inline uint pogisijessie;
inline double startTime;
uint GenerateNew_pogisijessie();
void GenerateNew_numbers();

void InitializeAll();

class Player{
public:
    uint addends1, addends2, useless1, useless2;
    uint key1, key2, key3, key4;
    uint point;
    uint original_one, original_two, original_three, original_four;
    Player(uint one, uint two, uint three, uint four);
    void DrawOptions();
    void RandomizeBindings(uint one, uint two, uint three, uint four);
};

void MatchInitialize();
void WaitFor_xseconds(float startTime, float xtime);


inline Player leftPlayer = Player(KEY_W, KEY_A, KEY_S, KEY_D);
inline Player rightPlayer = Player(KEY_I, KEY_J, KEY_K, KEY_L);

// random bindings



#endif
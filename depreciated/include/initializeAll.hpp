/*#ifndef INITIALIZEALL_HPP_
#define INITIALIZEALL_HPP_
#define MAXPOGISIJESSIE 179
#define MINPOGISIJESSIE 21


const int screenWidth = 1280;
const int screenHeight = 960;
inline const char* pogi = "Smash";

typedef unsigned int uint;

inline bool pause;
inline uint pogisijessie;
inline double startTime;


void InitializeAll();

class Player{
public:
    uint addends1, addends2, useless1, useless2;
    uint key1, key2, key3, key4;
    uint point;
    uint health;
    Player(uint one, uint two, uint three, uint four);
    void DrawOptions();
};

class GameMatch{
public:
    bool readyMode;
    bool coolDownMode;
    bool showDownMode;
    bool rewardingMode;
    bool pause;

    GameMatch(bool pause, bool readyMode, bool coolDownMode, bool showDownMode, bool rewardingMode);
    void GenerateNew_pogisijessie();
    void GenerateNew_numbers();
    void Pause();
};
inline GameMatch gameMatch = GameMatch(false, false, false, false, false);


void MatchInitialize();
void WaitFor_xseconds(float startTime, float xtime);


inline Player leftPlayer = Player(KEY_W, KEY_A, KEY_S, KeyboardKey::KEY_D);
inline Player rightPlayer = Player(KEY_I, KEY_J, KEY_K, KEY_L);




#endif
*/
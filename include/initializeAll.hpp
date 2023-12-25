#ifndef INITIALIZEALL_HPP_
#define INITIALIZEALL_HPP_


const int screenWidth = 800;
const int screenHeight = 600;
inline const char* pogi = "Smash";

typedef unsigned int uint;

inline bool space;
inline uint pogisijessie;

void InitializeAll();

class Player{
public:
    uint pogisijessie;
    uint addends1, addends2, useless1, useless2;
    Player(uint one, uint two, uint three, uint four);
};

#endif
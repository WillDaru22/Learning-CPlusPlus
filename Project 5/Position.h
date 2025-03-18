// Position.h
#ifndef POSITION_GUARD
#define POSITION_GUARD
#include <iostream>

class Position {
private:
    float x, y;
public:
    Position(float init_x, float init_y);
    float operator-(const Position other);
    void Read(std::istream& s);
};
#endif

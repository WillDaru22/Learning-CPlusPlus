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
    Position operator+(Position that);
    Position operator/(float denominator);
    float GetX() const;
    float GetY() const;
    void Read(std::istream& s);
};
#endif

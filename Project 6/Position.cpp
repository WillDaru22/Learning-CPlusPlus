// Position.cpp
#include <iostream>
#include <string>
#include <math.h>
#include "Position.h"

Position::Position(float init_x, float init_y) {
    x = init_x;
    y = init_y;
}

float Position::operator-(const Position other) {
    return sqrt(pow(x-other.x, 2) + pow(y - other.y, 2));
}

Position Position::operator+(Position that) {
    Position* newPos = new Position(GetX() + that.GetX(), GetY() + that.GetY());
    return *newPos;
}

Position Position::operator/(float denominator) {
    Position* newPosit = new Position(GetX()/denominator, GetY()/denominator);
    return *newPosit;
}

void Position::Read(std::istream& s) {
    std::string xs;
    std::getline(s, xs, ' ');
    std::string ys;
    std::getline(s, ys);
    x = stof(xs);
    y = stof(ys);
}

float Position::GetX() const {
    return x;
}

float Position::GetY() const {
    return y;
}

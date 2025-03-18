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

void Position::Read(std::istream& s) {
    std::string xs;
    std::getline(s, xs, ' ');
    std::string ys;
    std::getline(s, ys);
    x = stof(xs);
    y = stof(ys);
}

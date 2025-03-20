#include <iostream>
#include "CityLocation.h"

using namespace std;

bool CityLocation::Reserve() {
    if (reservations > 0) {
        reservations--;
        return true;
    }
    return false;
}

void CityLocation::Print() const {
    cout << "*** Off-Campus ***" << endl
         << "Location:     " << name    << endl
         << "Address:      " << address << endl
         << "Hours:        " << hours   << endl
         << "Reservations: " << reservations << endl
         << "Position:     " << x << ","  << y << endl;
         //<< "Press enter to return to menu." << endl;
}

void CityLocation::Read(std::istream& s) {
    std::string strx;
    std::string stry;
    getline(s, name, ',');
    while (s.peek() == ' ') { s.get(); } // not strictly necessary, but if there's space between ',' and next item, ignore it.
    getline(s, address, ',');
    while (s.peek() == ' ') { s.get(); }
    getline(s, hours, ',');
    while (s.peek() == ' ') { s.get(); }
    getline(s, strx, ',');
    x = std::stof(strx);
    while (s.peek() == ' ') { s.get(); }
    getline(s, stry, ',');
    //cout << stry;
    y = std::stof(stry);
    s >> reservations;
    while (s.peek() == '\n') { s.get(); }
    posit = Position(x, y);
}

void CityLocation::Write(std::ostream& s) const {
    s << "citylocation" << endl;
    s << name << "," << address << "," << hours << "," << x << "," << y << "," << reservations << endl;
}

Location* CityLocation::Clone() { return new CityLocation(name, address, hours, reservations); }

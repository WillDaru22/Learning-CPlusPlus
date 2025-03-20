#include <iostream>
#include "CampusLocation.h"

using namespace std;

bool CampusLocation::Reserve() {
    return false;
}

void CampusLocation::Print() const {
    cout << "*** On-Campus ***" << endl
         << "Location:     " << name    << endl
         << "Address:      " << address << endl
         << "Hours:        " << hours   << endl
         << "Reservations: None" << endl
         << "Position:     " << x << ","  << y << endl;
         //<< "Press enter to return to menu." << endl;
}

void CampusLocation::Read(std::istream& s) {
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
    getline(s, stry);
    //cout << stry;
    y = std::stof(stry);
    while (s.peek() == '\n') { s.get(); }
    posit = Position(x, y);
}

void CampusLocation::Write(std::ostream& s) const {
    s << "campuslocation" << endl;
    s << name << "," << address << "," << hours << "," << x << "," << y << endl;
}

Location* CampusLocation::Clone() { return new CampusLocation(name, address, hours); }

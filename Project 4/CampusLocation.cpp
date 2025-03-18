// CampusLocation.cpp - WillDaru22
#include "CampusLocation.h"
#include <iostream>
#include <string>

CampusLocation::CampusLocation() : Location("Kohl Center: Gate C", "601 W Dayton St", "8:30am-4:30pm", 0) {  // using the sample output

}

bool CampusLocation::Reserve() {
    return false;
}

void CampusLocation::Cancel() {
    return;
}

void CampusLocation::Print() const {
    std::cout << "*** On-Campus ***\n";
    std::cout << "Location:     "  << name << "\n";
    std::cout << "Address:      " << address << "\n";
    std::cout << "Hours:        " << hours << "\n";
    std::cout << "Reservations: " << "None" << "\n";
}

void CampusLocation::Read(std::istream& s) {
    std::getline(s, name, ',');
    std::getline(s, address, ',');
    std::getline(s, hours);
}

void CampusLocation::Write(std::ostream& s) const {
    s << "campuslocation\n";
    s << name << ", " << address << ", " << hours << "\n";
}
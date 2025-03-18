// CityLocation.cpp - WillDaru22
#include "CityLocation.h"
#include <iostream>
#include <string>

CityLocation::CityLocation() : Location("Town Hall", "123 Fake Street", "6:00am - 8:00pm", 2) {  // default constructor, let's say start with 2 reservation allowed

}

bool CityLocation::Reserve() {
    if(is_reservable == 0) {
        return false;
    }
    else {
        is_reservable--;
        return true;
    }
}

void CityLocation::Cancel() {
    is_reservable++;
}

void CityLocation::Print() const {
    std::cout << "*** Off-Campus ***\n";
    std::cout << "Location:     "  << name << "\n";
    std::cout << "Address:      " << address << "\n";
    std::cout << "Hours:        " << hours << "\n";
    std::cout << "Reservations: " << is_reservable << "\n";
}

void CityLocation::Read(std::istream& s) {
    std::getline(s, name, ',');
    std::getline(s, address, ',');
    std::getline(s, hours, ',');
    std::string reserve_holder;
    std::getline(s, reserve_holder);
    is_reservable = std::stoi(reserve_holder);
}

void CityLocation::Write(std::ostream& s) const {
    s << "citylocation\n";
    s << name << ", " << address << ", " << hours << ", " << is_reservable << "\n";
}
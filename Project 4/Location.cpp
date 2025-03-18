// Location.cpp - WillDaru22
#include "Location.h"
#include <iostream>
#include <string>

std::string name;
std::string address;
std::string hours;
int is_reservable;

Location::Location() {
    name = "";
    address = "";
    hours = "";
    is_reservable = 0;
}

Location::Location(std::string n, std::string a, std::string h, int reservation) {
    name = n;
    address = a;
    hours = h;
    is_reservable = reservation;
}

Location::Location(const Location& l) {
    name = l.name;
    address = l.address;
    hours = l.hours;
    is_reservable = l.is_reservable;
}

bool Location::IsReservable() const {
    if(is_reservable == 0) {
        return false;
    }
    else {
        return true;
    }
}


std::string Location::to_string() const {
    return name;
}

// void Location::Print() const {
//     std::cout << "Location: "  << name << "\n";
//     std::cout << "Address: " << address << "\n";
//     std::cout << "Hours: " << hours << "\n";
//     if(allow_reservation == true) {
//         std::cout << "Allows Reservations: Yes\n";
//     }
//     else {
//         std::cout << "Allows Reservations: No\n";
//     }
//     //std::cout << "Press enter to return to menu.\n";
// }
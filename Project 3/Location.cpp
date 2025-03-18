// Location.cpp WillDaru22
#include "Location.h"
#include <iostream>
#include <string>

std::string name;
std::string address;
std::string hours;
bool allow_reservation;

Location::Location() {
    name = "";
    address = "";
    hours = "";
    allow_reservation = NULL;
}

Location::Location(std::string n, std::string a, std::string h, bool res) {
    name = n;
    address = a;
    hours = h;
    allow_reservation = res;
}

Location::Location(const Location& l) {
    name = l.name;
    address = l.address;
    hours = l.hours;
    allow_reservation = l.allow_reservation;
}

bool Location::IsReservable() const {
    return allow_reservation;
}


std::string Location::to_string() const {
    return name;
}

void Location::Print() const {
    std::cout << "Location: "  << name << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Hours: " << hours << "\n";
    if(allow_reservation == true) {
        std::cout << "Allows Reservations: Yes\n";
    }
    else {
        std::cout << "Allows Reservations: No\n";
    }
    //std::cout << "Press enter to return to menu.\n";
}

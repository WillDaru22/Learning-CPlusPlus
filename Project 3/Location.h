// Location.h WillDaru22
#ifndef LOCATION_GUARD
#define LOCATION_GUARD
#include <iostream>

class Location {
    std::string name;
    std::string address;
    std::string hours;
    bool allow_reservation;

    public: Location();

    Location(std::string name, std::string address, std::string hours, bool allow_reservations);

    public: Location(const Location& copy_from);

    bool IsReservable() const;

    std::string to_string() const;

    void Print() const;
};
#endif

// Location.h - WillDaru22
#ifndef LOCATION_GUARD
#define LOCATION_GUARD
#include <iostream>

class Location {
    protected:
        std::string name;
        std::string address;
        std::string hours;
        int is_reservable;

    public: Location();

    Location(std::string name, std::string address, std::string hours, int reservation);

    public: Location(const Location& copy_from);

    bool IsReservable() const;

    std::string to_string() const;

    virtual void Print() const = 0;

    virtual void Read(std::istream& s) = 0;

    virtual void Write(std::ostream& s) const = 0;

    virtual bool Reserve() = 0;

    virtual void Cancel() = 0;
};
#endif

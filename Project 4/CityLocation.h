// CityLocation.h - WillDaru22
#ifndef CITY_GUARD
#define CITY_GUARD
#include <iostream>
#include "Location.h"
class CityLocation : public Location {
    
    public:
        CityLocation();

        bool Reserve();

        void Cancel();
        
        void Print() const;

        void Read(std::istream& s);

        void Write(std::ostream& s) const;
};
#endif

// CampusLocation.h - WillDaru22
#ifndef CAMPUS_GUARD
#define CAMPUS_GUARD
#include <iostream>
#include "Location.h"
class CampusLocation: public Location {
    
    public:
        CampusLocation();

        bool Reserve();

        void Cancel();

        void Print() const;

        void Read(std::istream& s);

        void Write(std::ostream& s) const;
};

#endif
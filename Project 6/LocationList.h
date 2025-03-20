#ifndef LOCATION_LIST
#define LOCATION_LIST

#include <string>
#include <vector>
#include <algorithm>
#include "Location.h"

class LocationList {
    class Closer {
        private:
            Position pose = Position(0.0, 0.0);
        public:
            Closer(Position p) {
                pose = p;
            }
        bool operator()(Location* a, Location* b) {
            if(a->operator-(pose) < b->operator-(pose)) {
                return true;
            }
            else {
                return false;
            }
        }
    };
private:
    std::vector<Location*> list;
    int count, size;

    //int Grow();
public:
    LocationList();
    ~LocationList();
    int GetCount() const { return count; }
    Location* GetLocation(int i) const { return list[i]; }
    void AddLocation(Location* new_loc);
    void FromFile(std::string fname);
    void ToFile(std::string fname);
    void Sort(Position p);
};

#endif

#ifndef LOCATION_LIST
#define LOCATION_LIST

#include <string>
#include <vector>
#include "Location.h"

class LocationList {
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
};

#endif

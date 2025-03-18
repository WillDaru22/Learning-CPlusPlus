// LocationList.h - WillDaru22
#ifndef LIST_GUARD
#define LIST_GUARD
#include "Location.h"

class LocationList {
    Location ** locations;
    int num_locations;
    int array_size;

    public: LocationList();

    ~LocationList();

    int GetCount() const;

    Location* GetLocation(int) const;

    void AddLocation(Location* new_loc);

    void FromFile(std::string fname);

    void ToFile(std::string fname);

    private:
        void Grow();
};
#endif

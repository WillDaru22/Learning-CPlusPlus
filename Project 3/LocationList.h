// LocationList.h WillDaru22
#ifndef LIST_GUARD
#define LIST_GUARD
#include "Location.h"

class LocationList {
    Location * locations;
    int num_locations;
    int array_size;

    public: LocationList();

    ~LocationList();

    int GetCount() const;

    Location GetLocation(int) const;

    void AddLocation(const Location& new_loc);

    private:
        void Grow();
};
#endif

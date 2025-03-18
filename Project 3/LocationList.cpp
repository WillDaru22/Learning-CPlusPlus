// LocationList.cpp WillDaru22
#include "LocationList.h"
#include <iostream>

Location * locations;
int num_locations;
int array_size;

LocationList::LocationList() {
    num_locations = 0;
    array_size = 16;
    locations = new Location[16];
}

LocationList::~LocationList() {
    delete []locations;
}

int LocationList::GetCount() const {
    return num_locations;
}

Location LocationList::GetLocation(int index) const{
    return locations[index];
}

void LocationList::Grow() {
    array_size = array_size*2;
    Location *newArr = new Location[array_size];
    for(int i = 0; i < num_locations; i++) {  // copy to new array
        newArr[i] = locations[i];
    }
    delete []locations;
    locations = newArr;
}

void LocationList::AddLocation(const Location& new_loc) {
    if(num_locations < array_size) {
        locations[num_locations] = Location(new_loc);
        num_locations++;
    }
    else {
        Grow();
        locations[num_locations] = Location(new_loc);
        num_locations++;
    }
}

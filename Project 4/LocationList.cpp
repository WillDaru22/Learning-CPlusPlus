// LocationList.cpp - WillDaru22
#include "LocationList.h"
#include "CampusLocation.h"
#include "CityLocation.h"
#include <iostream>
#include <fstream>
#include <string>

Location** locations;
int num_locations;
int array_size;

LocationList::LocationList() {
    num_locations = 0;
    array_size = 16;
    locations = new Location*[16];
}

LocationList::~LocationList() {
    for(int i = 0; i < array_size; i++) {
        delete[] locations[i];
    }
    delete[] locations;
}

int LocationList::GetCount() const {
    return num_locations;
}

Location* LocationList::GetLocation(int index) const{
    return locations[index];
}

void LocationList::Grow() {  // hoping I did this right, kept wanting to use malloc
    array_size = array_size*2;
    Location** newArr = new Location*[array_size];
    for(int i = 0; i < num_locations; i++) {  // copy to new array
        newArr[i] = locations[i];
    }
    for(int i = 0; i < array_size/2; i++) {
        delete[] locations;
    }
    locations = newArr;
}

void LocationList::AddLocation(Location* new_loc) {  // bug is somewhere in here or the other area.  Already a day late and 20 minutes left before late again so idk.
    if(num_locations < array_size) {
        locations[num_locations] = new_loc;
        num_locations++;
    }
    else {
        Grow();
        locations[num_locations] = new_loc;
        num_locations++;
    }
}

void LocationList::FromFile(std::string fname) {  // bug somewhere in here where locations are not getting added to the list or in AddLocation
    std::ifstream lfs (fname);
    std::string loc_holder;
    std::string line;
    std::string campus = "campuslocation";
    std::string city = "citylocation";
    int loc_num;
    if(lfs.is_open()) {
        std::getline(lfs, loc_holder);
        loc_num = std::stoi(loc_holder);  // convert to int
        for(int i = 0; i < loc_num; i++) {
            std::getline(lfs, line);
            if(line.compare(campus) == 0) {  // here if bug is
                CampusLocation* cam = new CampusLocation();
                LocationList::AddLocation(cam);
                cam->Read(lfs);
            }
            else if(line.compare(city) == 0) {  // here if bug is
                CityLocation* cit = new CityLocation();
                LocationList::AddLocation(cit);
                cit->Read(lfs);
            }
            else {
            }
            line.clear();
        }
    }
    else {
        std::cout << "Unable to open file in location list for reading\n";
        return;
    }
    lfs.close();
}

void LocationList::ToFile(std::string fname) {
    std::ofstream lofs (fname, std::ofstream::trunc);
    if(lofs.is_open()) {
        lofs << LocationList::GetCount();
        for(int i = 0; i < LocationList::GetCount(); i++) {
            LocationList::GetLocation(i)->Write(lofs);
        }
    }
    else {
        std::cout << "Unable to open file in location list for writing\n";
        return;
    }
    //std::cout << "Crash in location List\n";
    lofs.close();  // causes crashes I guess, maybe fixed
}

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "Location.h"
#include "LocationList.h"
#include "CampusLocation.h"
#include "CityLocation.h"

using namespace std;

// int LocationList::Grow() {
//     if (count >= size) {
//         size *= 2;
//         //cout << "making new list of size " << to_string(size) << endl;
//         Location** new_list = new Location*[size];
//         for (int i = 0; i < count; i++) {
//             new_list[i] = list[i];
//             //std::cout << "made copy of location " << to_string(i) << std::endl;
//         }
//         //std::cout << "ready to delete list. " << endl;
//         delete [] list;
//         //std::cout << "deleted list." << endl;
//         list = new_list;
//     }
//     return size;
// }

LocationList::LocationList() {
    size = 8;
    count = 0;
    std::vector<Location*> list(8, 0);
}

LocationList::~LocationList() {
    for (int i = 0; i < count; i++) {
        delete list[i];
    }
    list.clear();
}

void LocationList::AddLocation(Location* new_loc) {
    if (count >= size) {
        //int new_size = Grow();
        //std::cout << "Grew LocationList to size " << new_size << std::endl;
    }
    list.push_back(new_loc);
    count++;
}

void LocationList::FromFile(std::string fname) {
    ifstream infile;
    infile.open(fname);
    if (infile.good()) {
        // don't forget to clear list before re-loading.
        for (int i = 0; i < count; i++) {
            delete list[i];
        }
        count = 0;

        string next_line;
        Location* next_loc;

        getline(infile, next_line);
        int num_locs = stoi(next_line);
        for (int i = 0; i < num_locs; i++) {
            getline(infile, next_line);
            if (next_line == "campuslocation")
                next_loc = new CampusLocation();
            else
                next_loc = new CityLocation();
            next_loc->Read(infile);
            AddLocation(next_loc);
        }
    }
    infile.close();
}

void LocationList::ToFile(std::string fname) {
    ofstream outfile;
    outfile.open(fname);
    if (outfile.good()) {
        outfile << count << endl;
        for (int i = 0; i < count; i++) {
            list[i]->Write(outfile);
        }
    }
    outfile.close();
}

void LocationList::Sort(Position p) {
    sort(list.begin(), list.end(), Closer(p));
}

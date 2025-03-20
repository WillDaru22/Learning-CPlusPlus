#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"

using namespace std;

// functor struct to sum up the positions
struct User::Sum {
    Position sum = Position(0.0, 0.0);
    void operator()(Position* next) {sum = sum.operator+(*next); }
};

void User::SetLast(const std::string new_last) {
    l_name = new_last;
    user_filename = l_name + ".txt";
    reservations_filename = l_name + "_reservations.txt";
}

void User::SetUnits(bool set_metric) {
// only try to change if there's a change to make.
    if (is_metric != set_metric) {
        if (set_metric) {
            // If we're going to metric, divide imperial by conversion factor.
            height /= 3.28;
            weight /= 2.20;
        }
        else {
            // If we're going to imperial, multiply metric by conversion factor.
            height *= 3.28;
            weight *= 2.20;
        }
        is_metric = set_metric;
    }
}

void User::MakeReservation(Location* reserve) {
    if (reserve->IsReservable()) {
        // Use clone function so the reservation here doesn't have same location as in master list - avoids double-deletion.
        reservations.AddLocation(reserve->Clone());
    }
}

void User::PrintData() const {
   cout << "Your data:" << endl
        << "Name:   " << to_string() << endl
        << "Age:    " << age << endl
        << "Height: " << height << " " << (is_metric ? "m" : "ft" ) << endl
        << "Weight: " << weight << " " << (is_metric ? "kg": "lbs") << endl
        << "Press enter to return to menu.";
}

void User::PrintReservations() const {
    cout << "Here are your reservations:" << endl;
    for (int i = 0; i < reservations.GetCount(); i++) {
        reservations.GetLocation(i)->Print();
    cout << "Press enter to return to menu." << endl;
    }
}

void User::Read(bool& is_imperial, std::string fname) {
    ifstream user_file;

    if (fname != "") {
        int i = 0;
        while(fname[i] != '.') i++; // find the '.' in the filename, so we can get the part with just the name.
        string r_fname = fname.substr(0,i) + "_reservations.txt";

        user_file.open(fname);
        reservations.FromFile(r_fname);
    }
    else {
        user_file.open(user_filename);
        reservations.FromFile(reservations_filename);
    }
    if (user_file.good()) {
        user_file >> f_name >> l_name >> age >> height >> weight >> is_imperial;
        is_metric = !is_imperial;
        user_filename = l_name + ".txt";
        reservations_filename = l_name + "_reservations.txt";
        positions_filename = l_name + "_positions.txt";
    }
    user_file.close();
    PosReadHelper();
}

// helper function for read for positions
void User::PosReadHelper() {
    ifstream position_file;
    if (positions_filename != "") {
        position_file.open(positions_filename);
    }
    if (position_file.good()) {
        for(int i = 0; i < 24; i++) {
            pos.push_back(new Position(0, 0));
            pos.back()->Read(position_file);
        }
    }
    position_file.close();
}

void User::Write(const bool is_imperial) {
    ofstream user_file;

    user_file.open(user_filename);
    if (user_file.good()) {
        user_file << f_name << " " << l_name << " " << age << " " << height << " " << weight << " " << is_imperial;
        reservations.ToFile(reservations_filename);
    }
    user_file.close();
}

int User::CheckExposures() {
    ifstream contacts;
    int exposures = 0;
    contacts.open("databases.txt");
    if (contacts.good()) {
        std::string peoples;
        std::string dummy;
        std::vector<Position*> person(24);
        getline(contacts, peoples);
        int people = stoi(peoples);
        for(int i = 0; i < people; i++) {
            for(int j = 0; j < 24; j++) {  // read persons data
                person.push_back(new Position(0, 0));
                person.back()->Read(contacts);
            }
            for(int n = 0; n < 24; n++) {
                float dist = pos[n]->operator-(*person[n]);
                if(dist < 6) {  // if any pair is small enough, mark as exposure then break out of loop
                    exposures++;
                    break;
                }
            }
            // reset vector to use again
            for (int k = 0; k < 24; k++) {
                delete person[k];
            }
            person.clear();
            getline(contacts, dummy);  // get rid of dummy line
        }
    }
    contacts.close();
    return exposures;
}

Position User::AveragePosition() const {
    Sum result = std::for_each(pos.begin(), pos.end(), Sum());
    return result.sum.operator/(24.0);
}

// User.cpp - WillDaru22
#include "Location.h"
#include "LocationList.h"
#include "User.h"
#include <iostream>
#include <string>
#include <fstream>

std::string first_name;
std::string last_name;
int age;
double height;
double weight;
int units;
LocationList* reservations;
std::string user_filename;
std::string reservations_filename;

User::User() {
    first_name = "";
    last_name = "";
    age = 0;
    height = 0.0;
    weight = 0.0;
    units = 0;
    LocationList* reservations = new LocationList;
    user_filename = "default.txt";
    reservations_filename = "default_reservations.txt";
}

// series of getters and setters here
void User::setFName(std::string name) {
    first_name = name;
}

std::string User::getFName() const{
    return first_name;
}

void User::setLName(std::string name) {  // updated to change filenames too
    last_name = name;
    user_filename = name + ".txt";
    reservations_filename = name + "_reservations.txt";
}

std::string User::getLName() const{
    return last_name;
}

void User::setAge(int a) {
    age = a;
}

int User::getAge() const{
    return age;
}

void User::setHeight(double h) {
    height = h;
}

double User::getHeight() const{
    return height;
}

void User::setWeight(double w) {
    weight = w;
}

double User::getWeight() const{
    return weight;
}

void User::setUnits(int u) {
    units = u;
}

int User::getUnits() const{
    return units;
}

LocationList User::getLL() const {
    return reservations;
}

void User::setLL(LocationList* L) {
    reservations = *L;
}

std::string User::getFilename() const {
    return user_filename;
}

void User::setFilename(std::string fname) {
    user_filename = fname;
}

std::string User::getReservationFile() const {
    return reservations_filename;
}

void User::setReservationFile(std::string fname) {
    reservations_filename = fname;
}

// actual code
void User::MakeReservation(Location* new_reservation) {
    reservations.AddLocation(new_reservation);
}

std::string User::to_string() {
    return first_name + " " + last_name;
}

void User::PrintData() const{
    std::cout << "Your data:\n";
    std::cout << "Name:   " << first_name << " " << last_name << "\n";
    std::cout << "Age:    " << age << "\n";
    if(units == 0) {  // units is 0, use imperial
        std::cout << "Height: " << height << " ft\n";
        std::cout << "Weight: " << weight << " lbs\n";
    }
    else {  // units is 1, use metric
        std::cout << "Height: " << height << " m\n";
        std::cout << "Weight: " << weight << " kg\n";
    }
}

void User::PrintReservations() {
    std::cout << "Here are your reservations:\n";
    for(int i = 0; i < reservations.GetCount(); i++) {
        reservations.GetLocation(i)->Print();
    }
}

void User::Read(bool& is_imperial, std::string fname = "") {
    std::string line;
    if(fname.compare("")) {
        std::ifstream fs (getFilename());
        if(fs.is_open()) {
            // first name
            std::getline(fs, line, ' ');
            setFName(line);
            line.clear();
            // last name
            std::getline(fs, line, ' ');
            setLName(line);
            line.clear();
            // age
            std::getline(fs, line, ' ');
            setAge(std::stoi(line));
            line.clear();
            // height
            std::getline(fs, line, ' ');
            setHeight(std::stod(line));
            line.clear();
            // weight
            std::getline(fs, line, ' ');
            setWeight(std::stod(line));
            line.clear();
            // unit
            std::getline(fs, line);
            setUnits(std::stoi(line));
            line.clear();
        }
        else {
            std::cout << "Unable to open file in user for reading\n";
            return;
        }
        fs.close();
    }
    else {
        std::ifstream fs (fname);
        if(fs.is_open()) {
            // first name
            std::getline(fs, line, ' ');
            setFName(line);
            line.clear();
            // last name
            std::getline(fs, line, ' ');
            setLName(line);
            line.clear();
            // age
            std::getline(fs, line, ' ');
            setAge(std::stoi(line));
            line.clear();
            // height
            std::getline(fs, line, ' ');
            setHeight(std::stod(line));
            line.clear();
            // weight
            std::getline(fs, line, ' ');
            setWeight(std::stod(line));
            line.clear();
            // unit
            std::getline(fs, line);
            setUnits(std::stoi(line));
            line.clear();
        }
        else {
            std::cout << "Unable to open file in user for reading\n";
            return;
        }
        fs.close();
    }
    getLL().FromFile(getReservationFile());
}

void User::Write(const bool is_imperial) {
    std::ofstream fs (getFilename(), std::ofstream::trunc);
    if(fs.is_open()) {
        fs << getFName() << " " << getLName() <<  " " << getAge() << " " << getHeight() << " " << getWeight() << " " << getUnits() << "\n";
    }
    else {
        std::cout << "Unable to open file in user for writing\n";
        return;
    }
    fs.close();  // causing crashes, maybe fixed
    getLL().ToFile(getReservationFile());
}

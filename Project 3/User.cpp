// User.cpp - WillDaru22
#include "Location.h"
#include "LocationList.h"
#include "User.h"
#include <iostream>
#include <string>

std::string first_name;
std::string last_name;
int age;
double height;
double weight;
int units;
LocationList* reservations;

User::User() {
    first_name = "";
    last_name = "";
    age = 0;
    height = 0.0;
    weight = 0.0;
    units = 0;
    LocationList *reservations = new LocationList;
}

// series of getters and setters here
void User::setFName(std::string name) {
    first_name = name;
}

std::string User::getFName() const{
    return first_name;
}

void User::setLName(std::string name) {
    last_name = name;
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

// actual code
void User::MakeReservation(const Location& new_reservation) {
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
        reservations.GetLocation(i).Print();
    }
}

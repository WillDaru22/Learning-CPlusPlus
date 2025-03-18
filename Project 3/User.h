// User.h - WillDaru22
#ifndef USER_GUARD
#define USER_GUARD
#include "Location.h"
#include "LocationList.h"
#include <iostream>

class User {
    std::string first_name;
    std::string last_name;
    int age;
    float height;
    float weight;
    LocationList reservations;

    public: User();
    
    void MakeReservation(const Location& new_reservation);

    std::string to_string();

    void PrintData() const;

    public: void PrintReservations();

    // getters and setters
    void setFName(std::string name);

    std::string getFName() const;

    void setLName(std::string name);

    std::string getLName() const;

    void setAge(int a);

    int getAge() const;

    void setHeight(double h);

    double getHeight() const;

    void setWeight(double w);

    double getWeight() const;

    void setUnits(int u);

    int getUnits() const;
};
#endif

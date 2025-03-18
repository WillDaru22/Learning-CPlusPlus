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
    std::string user_filename;
    std::string reservations_filename;

    public: User();
    
    void MakeReservation(Location* new_reservation);

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

    LocationList getLL() const;

    void setLL(LocationList* L);

    std::string getFilename() const;

    void setFilename(std::string fname);

    std::string getReservationFile() const;

    void setReservationFile(std::string fname);

    void Read(bool& is_imperial, std::string fname);

    void Write(const bool is_imperial);
};
#endif

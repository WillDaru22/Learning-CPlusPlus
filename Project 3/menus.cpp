// Learning project 3 - WillDaru22
// menus.cpp imeplementation file for menus.h

#include <iostream>
#include "menus.h"
#include "LocationList.h"
#include "User.h"
#include <string>

void printMainMenu() {
    std::cout << "Welcome (back) to Safe-ish Badgers!\n";
    std::cout << "[1] View testing locations\n";
    std::cout << "[2] Make test reservation\n";
    std::cout << "[3] Use symptom checker\n";
    std::cout << "[4] View my reservations\n";
    std::cout << "[5] View my personal data\n";
    std::cout << "[6] Adjust my personal data\n";
    std::cout << "[7] Change setttings\n";
    std::cout << "[8] Exit program\n";
    std::cout << "Please enter a menu item:\n";
}

void printTestingLocations(const LocationList& locations) {
    std::cout << "Testing Locations:\n";
    for(int i = 0; i < locations.GetCount(); i++) {
        std::cout << "[" << i+1 << "] " << locations.GetLocation(i).to_string() << "\n";
    }
    std::cout << "[" << locations.GetCount()+1 << "] Return to main menu\n";
    std::cout << "Choose a location for more information, or return to the menu:\n";
}

void printSymptomChecker(std::string symptoms[], bool selected[]) {
    std::cout << "Select your symptoms:\n";
    for(int i = 0; i < 6; i++) {
        if (selected[i] == true) {
            std::cout << "[" << i+1 << "*] " << symptoms[i] << "\n";
        }
        else {
            std::cout << "[" << i+1 <<"]  " << symptoms[i] << "\n";
        }
    }
    std::cout << "[7]  Submit Symptoms\n";
    std::cout << "[8]  Cancel and return to main menu\n";
}

void printUserDataMenu(const User& user) {
        std::cout << "Set your personal data:\n";
        std::cout << "[1] First name (" << user.getFName() << ")\n";
        std::cout << "[2] Last name (" << user.getLName() << ")\n";
        std::cout << "[3] Age (" << user.getAge() << ")\n";
        if(user.getUnits() == 0) {  // Use imperial
            std::cout << "[4] Height (" << user.getHeight() << " ft)\n";
            std::cout << "[5] Weight (" << user.getWeight() << " lbs)\n";
        }
        else {  // use metric
            std::cout << "[4] Height (" << user.getHeight() << " m)\n";
            std::cout << "[5] Weight (" << user.getWeight() << " kg)\n";
        }
}

void printSettingsMenu(const bool is_metric) {
        std::cout << "Change your app settings:\n";
        if(is_metric == false) {  // units is 0, imperial
            std::cout << "[1] Switch units (imperial)\n";
        }
        else {  // units is 1, metric
            std::cout << "[1] Switch units (metric)\n";
        }
        std::cout << "[2] Return to main menu\n";
        std::cout << "Please enter a menu item\n";
}

void printReservationLocations(const LocationList& locations) {
    std::cout << "Testing Locations:\n";
    for(int i = 0; i < locations.GetCount(); i++) {
        if(locations.GetLocation(i).IsReservable() == true) {
            std::cout << "[" << i << "] " << locations.GetLocation(i).to_string() << "\n";
        }
    }
    //std::cout << "[" << locations.GetCount()+1 << "] Return to main menu\n";
    std::cout << "Choose a location to reserve, or return to the menu:\n";
}

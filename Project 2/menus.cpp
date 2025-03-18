// Learning C++ project 2 - WillDaru22
// menus.cpp imeplementation file for menus.h

#include <iostream>
#include "menus.h"
#include <string>

void printMainMenu() {
    std::cout << "Welcome (back) to Safe-ish Badgers!\n";
    std::cout << "[1] View testing locations\n";
    std::cout << "[2] Use symptom checker\n";
    std::cout << "[3] Exit program\n";
    std::cout << "Please enter a menu item:\n";
}

void printTestingLocations(std::string locations[], int count) {
    std::cout << "Testing Locations:\n";
    for(int i = 0; i < count; i++) {
        std::cout << "[" << i+1 << "] " << locations[i] << "\n";
    }
    std::cout << "[" << count+1 << "] Return to main menu\n";
    std::cout << "Choose a location for more information, or return to the menu:\n";
}

void printDetails(std::string name, std::string address, std::string hours) {
    std::cout << "Location: "  << name << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Hours: " << hours << "\n";
    std::cout << "Press enter to return to menu.\n";
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

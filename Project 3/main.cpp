// Learning C++ Project 3 - WillDaru22
// Main.cpp file to handle main functions of the program

#include <iostream>
#include "menus.h"
#include "User.h"
#include "LocationList.h"
#include "Location.h"
#include <string>
#include <limits>

// Function for handling the testing locations menu and inputs
void locationMenu(const LocationList& locations) {
    int inp = 0;
    do {
        printTestingLocations(locations);
        std::cin >> inp;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            // cout << "Please enter a menu item:";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(inp == 1 || inp == 2 || inp == 3 || inp == 4 || inp ==5) {  // view details of selection
            do {
                locations.GetLocation(inp-1).Print();
                std::cout << "Press enter to return to menu.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            }
            while(true);
        }
        else if(inp == 6) {  // back to menu
            return;
        }
        else {  // any other value, do nothing

        }
    }
    while(true);

}

// Function for handling the symptom checker menu and toggles
void symptomChecker() {
    std::string symptoms[6] = {"Fever", "Cough", "Shortness of breath", "Loss of taste or smell", "Fatigue", "Sore throat"};
    bool selected[6] = {false, false, false, false, false, false};
    int inp = 0;
    int symptom_count = 0;
    do {
        printSymptomChecker(symptoms, selected);
        std::cin >> inp;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            // cout << "Please enter a menu item:";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(inp == 1 || inp == 2 || inp == 3 || inp == 4 || inp == 5 || inp == 6) {  // flip bool value depending on toggle
            selected[inp-1] = !selected[inp-1];
        }
        else if(inp == 7) {  // submit symptoms
            for(int i = 0; i < 6; i++) {
                if(selected[i] == true) {
                    symptom_count++;
                }
            }
            if(symptom_count > 2) {  // if more than 2 symptoms
                std::cout << "Please go to an available testing site to be tested for Covid-19\n";
                std::cout << "Press enter to return to main menu.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            else if(symptom_count == 1 || symptom_count == 2) {  // if 1 or 2
                std::cout << "Please stay home and monitor your symptoms.  If your symptoms persist or you develop new symptoms,\n";
                std::cout << "please go to an available testing site to be tested for Covid-19.\n";
                std::cout << "Press enter to return to main menu.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            else {  // no symptoms
                std::cout << "You seem to be feeling fine.  Remember to test regularly for Covid-19.\n";
                std::cout << "Press enter to return to main menu.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            // do not need to reset symptom count since we return to the main menu and it gets reset the next time we run
        }
        else if(inp == 8) {  // back to menu
            return;
        }
        else {  // any other number, do nothing and back to loop

        }
    }
    while(true);
}

void setData(User& user) {
    int entry = 0;
    do {
        printUserDataMenu(user);
        std::cout << "[6] Return to main menu\n";
        std::cout << "Please enter a menu item:\n";
        std::cin >> entry;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(entry == 1) {
            do {
                std::string newFName;
                std::cout << "Please enter your first name:\n";
                std::cin >> newFName;
                if(std::cin.fail()) {  // failure check
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    user.setFName(newFName);
                    break;
                }
            } while(true);

        }
        else if(entry == 2) {
            do {
                std::string newLName;
                std::cout << "Please enter your last name:\n";
                std::cin >> newLName;
                if(std::cin.fail()) {  // failure check
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    user.setLName(newLName);
                    break;
                }
            } while(true);
        }
        else if(entry == 3) {
            do {
                int newAge = 0;
                std::cout << "Please enter your age:\n";
                std::cin >> newAge;
                if(std::cin.fail()) {  // failure check
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    if(newAge < 0 || newAge > 122) {
                        continue;
                    }
                    else {
                        user.setAge(newAge);
                        break;
                    }
                }
            } while(true);
        }
        else if(entry == 4) {
            do {
                double newHeight = 0.0;
                std::cout << "Please enter your height:\n";
                std::cin >> newHeight;
                if(std::cin.fail()) {  // failure check
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    if(user.getUnits() == 0) {  // check imp
                        if(newHeight < 0 || newHeight > 9.0) {
                            continue;
                        }
                        else {
                            user.setHeight(newHeight);
                            break;
                        }
                    }
                    else {  // check metric
                        if(newHeight < 0 || newHeight > 2.75) {
                            continue;
                        }
                        else {
                            user.setHeight(newHeight);
                            break;
                        }
                    }
                }
            } while(true);
        }
        else if(entry == 5) {
            do {
                double newWeight = 0.0;
                std::cout << "Please enter your weight:\n";
                std::cin >> newWeight;
                if(std::cin.fail()) {  // failure check
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    if(user.getUnits() == 0) {  // check imp
                        if(newWeight < 0 || newWeight > 975) {
                            continue;
                        }
                        else {
                            user.setWeight(newWeight);
                            break;
                        }
                    }
                    else {  // check metric
                        if(newWeight < 0 || newWeight > 445) {
                            continue;
                        }
                        else {
                            user.setWeight(newWeight);
                            break;
                        }
                    }
                }
            } while(true);
        }
        else if(entry == 6) {
            return;
        }
        else {

        }
    } while(true);
}

void viewData(const User& user) {
    int inp = 0;
    user.PrintData();
    std::cout << "Press enter to return to main menu.\n";
    //std::cin >> inp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

void viewReservations(User& user) {
    int inp = 0;
    user.PrintReservations();
    std::cout << "Press enter to return to main menu.\n";
    //std::cin >> inp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

void changeSettings(User& user) {
    bool metric = false;  // default value just to catch errors
    int entry = 0;
    do {
        if(user.getUnits() == 0) {
            metric = false;
        }
        else {
            metric = true;
        }
        printSettingsMenu(metric);
        std::cin >> entry;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(entry == 1) {
            if(user.getUnits() == 0) {
                user.setUnits(1);
                user.setHeight(user.getHeight()/3.28);
                user.setWeight(user.getWeight()/2.20);
            }
            else {
                user.setUnits(0);
                user.setHeight(user.getHeight()*3.28);
                user.setWeight(user.getWeight()*2.20);
            }
        }
        else if (entry == 2) {
            return;
        }
        else {

        }
    } while(true);
}

void makeReserveMenu(User& user, LocationList& locations) {
    int inp = 0;
    do {
        printReservationLocations(locations);
        std::cout << "[" << locations.GetCount() << "] Return to main menu.\n";
        std::cin >> inp;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(inp == 0 || inp == 1 || inp == 4) {
            user.MakeReservation(locations.GetLocation(inp));
        }
        else if(inp == locations.GetCount()) {
            return;
        }
        else {

        }
    }
    while(true);
}

// Main function
int main(int argc, const char* argv[]) {
    //startup
    int choice = 0;
    User *current_user = new User;
    LocationList *current_locations = new LocationList;
    Location *kohl = new Location("Kohl Center, Gate C", "601 W Dayton St", "8:30am-4:30pm", true);
    Location *dejope = new Location("Dejope Hall, 1165", "640 Elm Dr", "9:30am-5:30pm", true);
    Location *park = new Location("21 N Park St, 1106", "21 N Park St", "7:30am-3:30pm", false);
    Location *shell = new Location("Shell, 110", "1430 Monroe St", "8:30am-4:30pm", false);
    Location *engin = new Location("Mechanical Engineering Building, 1184", "1513 University Ave", "6:30am-2:30pm", true);
    current_locations->AddLocation(*kohl);
    current_locations->AddLocation(*dejope);
    current_locations->AddLocation(*park);
    current_locations->AddLocation(*shell);
    current_locations->AddLocation(*engin);
    //current_locations->GetLocation(0).Print();  // debug

    // main loop
    do {
        printMainMenu();
        std::cin >> choice;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            // cout << "Please enter a menu item:";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(choice == 1) {  // locations menu
            locationMenu(*current_locations);
        }
        else if(choice == 2) {  // Make reservation
            makeReserveMenu(*current_user, *current_locations);
        }
        else if(choice == 3) {  // symptom checker
            symptomChecker();
        }
        else if(choice == 4) {  // view reservations
            viewReservations(*current_user);
        }
        else if(choice == 5) {  // view personal data
            viewData(*current_user);
        }
        else if(choice == 6) {  // Adjust personal data
            setData(*current_user);
        }
        else if(choice == 7) {  // change settings
            changeSettings(*current_user);
        }
        else if(choice == 8) {  // exit
            exit(0);
        }
        else {  // no specified number, do nothing

        }
    }
    while(true);
}

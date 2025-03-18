// Learning C++ Project 2 - WillDaru22
// Main.cpp file to hanlde main functions of the program

#include <iostream>
#include "menus.h"
#include <string>
#include <limits>

// Function for handling the testing locations menu and inputs
void locationMenu() {
    std::string locations[5] = {"Kohl Center, Gate C", "Dejope Hall, 1165", "21 N Park St, 1106", "Shell, 110", "Mechanical Engineering Building, 1184"};
    std::string addresss[5] = {"601 W Dayton St", "640 Elm Dr", "21 N Park St", "1430 Monroe St", "1513 University Ave"};
    std::string l_hours[5] = {"8:30am-4:30pm", "9:30am-5:30pm", "7:30am-3:30pm", "8:30am-4:30pm", "6:30am-2:30pm"};
    int inp = 0;
    do {
        printTestingLocations(locations, 5);
        std::cin >> inp;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            // cout << "Please enter a menu item:";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(inp == 1 || inp == 2 || inp == 3 || inp == 4 || inp ==5) {  // view details of selection
            do {
                printDetails(locations[inp-1], addresss[inp-1], l_hours[inp-1]);
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

// Main function
int main(int argc, const char* argv[]) {
    int choice = 0;

    do {
        printMainMenu();
        std::cin >> choice;
        if(std::cin.fail()) {  // failure check
            std::cin.clear();
            // cout << "Please enter a menu item:";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(choice == 1) {  // locations menu
            locationMenu();
        }
        else if(choice == 2) {  // symptom checker
            symptomChecker();
        }
        else if(choice == 3) {  // exit
            exit(0);
        }
        else {  // no specified number, do nothing

        }
    }
    while(true);
}

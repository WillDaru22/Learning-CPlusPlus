// WillDaru22
// Learning C++ Project 1

// Acknowledgements
// Fixing infinite loop when bad input in cin.  Turns out not needed after reading prompt but leaving it in anyway since it seems good practice for handling such an issue
// https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function for handling the view user data menu
void viewDataMenu(string first_name, string last_name, int age,double height,double weight, int units) {
    cout << "Your data:\n";
    cout << "Name:   " << first_name << " " << last_name << "\n";
    cout << "Age:    " << age << "\n";
    if(units == 0) {  // units is 0, use imperial
        cout << "Height: " << height << " ft\n";
        cout << "Weight: " << weight << " lbs\n";
    }
    else {  // units is 1, use metric
        cout << "Height: " << height << " m\n";
        cout << "Weight: " << weight << " kg\n";
    }

    int entry = 0;
    do {
        cout << "Enter any number to return to menu.\n";
        cin >> entry;
        if(cin.fail()) {  // failure check
            cin.clear();
            // cout << "Enter any number to return to menu.\n";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return;
    } while(true);
}

// Function for handling the set user data menu
void setDataMenu(string& first_name, string& last_name, int& age,double& height,double& weight, int units) {
    int entry = 0;
    string newFName = "";
    string newLName = "";
    int newAge = 0;
    double newHeight = 0.0;
    double newWeight = 0.0;
    do {
        cout << "Set your personal data:\n";
        cout << "[1] First name (" << first_name << ")\n";
        cout << "[2] Last name (" << last_name << ")\n";
        cout << "[3] Age (" << age << ")\n";
        if(units == 0) {  // Use imperial
            cout << "[4] Height (" << height << " ft)\n";
            cout << "[5] Weight (" << weight << " lbs)\n";
        }
        else {  // use metric
            cout << "[4] Height (" << height << " m)\n";
            cout << "[5] Weight (" << weight << " kg)\n";
        }
        cout << "[6] Return to main menu\n";
        cout << "Please enter a menu item:\n";
        cin >> entry;
        if(cin.fail()) {  // failure check
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(entry == 1) {
            do {
                cout << "Please enter your first name:\n";
                cin >> newFName;
                if(cin.fail()) {  // failure check
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    first_name = newFName;
                    break;
                }
            } while(true);

        }
        else if(entry == 2) {
            do {
                cout << "Please enter your last name:\n";
                cin >> newLName;
                if(cin.fail()) {  // failure check
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    last_name = newLName;
                    break;
                }
            } while(true);
        }
        else if(entry == 3) {
            do {
                cout << "Please enter your age:\n";
                cin >> newAge;
                if(cin.fail()) {  // failure check
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    if(newAge < 0 || newAge > 122) {
                        continue;
                    }
                    else {
                        age = newAge;
                        break;
                    }
                }
            } while(true);
        }
        else if(entry == 4) {
            do {
                cout << "Please enter your height:\n";
                cin >> newHeight;
                if(cin.fail()) {  // failure check
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    if(units == 0) {  // check imp
                        if(newHeight < 0 || newHeight > 9.0) {
                            continue;
                        }
                        else {
                            height = newHeight;
                            break;
                        }
                    }
                    else {  // check metric
                        if(newHeight < 0 || newHeight > 2.75) {
                            continue;
                        }
                        else {
                            height = newHeight;
                            break;
                        }
                    }
                }
            } while(true);
        }
        else if(entry == 5) {
            do {
                cout << "Please enter your weight:\n";
                cin >> newWeight;
                if(cin.fail()) {  // failure check
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else {
                    if(units == 0) {  // check imp
                        if(newWeight < 0 || newWeight > 975) {
                            continue;
                        }
                        else {
                            weight = newWeight;
                            break;
                        }
                    }
                    else {  // check metric
                        if(newWeight < 0 || newWeight > 445) {
                            continue;
                        }
                        else {
                            weight = newWeight;
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

// Function for handling the change settings menu
int changeSettingsMenu(int units) {
    int x = units;
    int entry = 0;
    do {
        cout << "Change your app settings:\n";
        if(x == 0) {  // units is 0, imperial
            cout << "[1] Switch units (imperial)\n";
        }
        else {  // units is 1, metric
            cout << "[1] Switch units (metric)\n";
        }
        cout << "[2] Return to main menu\n";
        cout << "Please enter a menu item\n";
        cin >> entry;
        if(cin.fail()) {  // failure check
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(entry == 1) {
            if(x == 0) {
                x = 1;
            }
            else {
                x = 0;
            }
        }
        else if (entry == 2) {
            return x;
        }
        else {

        }
    } while(true);
}

// Main method
int main(int argc, const char* argv[]) {

    int choice = 0;

    // variables to store user data
    string first_name = "";
    string last_name = "";
    int age = 0;
    double height = 0.0;
    double weight = 0.0;
    int units = 0;

    do {
        cout << "Welcome to Safe-ish Badgers!\n";
        cout << "[1] View my personal data\n";
        cout << "[2] Adjust my personal data\n";
        cout << "[3] Change settings\n";
        cout << "[4] exit program\n";
        cout << "Please enter a menu item:";
        cin >> choice;
        if(cin.fail()) {  // failure check
            cin.clear();
            // cout << "Please enter a menu item:";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(choice == 1) {
            viewDataMenu(first_name, last_name, age, height, weight, units);
        }
        else if(choice == 2) {
            setDataMenu(first_name, last_name, age, height, weight, units);
        }
        else if(choice == 3) {
            if(units == 0) {  // imperial
                units = changeSettingsMenu(units);
                if(units == 0) {  // unchanged do nothing
                }
                else {  // convert to metric
                    height = height / 3.28;  // ft to m
                    weight = weight / 2.20;  // lbs to kg
                }
            }
            else {  // metric
                units = changeSettingsMenu(units);
                if(units == 0) {  // convert to imperial
                    height = height * 3.28;  // m to ft
                    weight = weight * 2.20;  // kg to lbs
                }
                else {  // unchanged do nothing
                }
            }
        }
        else if(choice == 4) {
            exit(0);
        }
        else {

        }
    }
    while(true);
}

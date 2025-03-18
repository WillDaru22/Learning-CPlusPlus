// menus header file for learning C++.  willdaru22
#ifndef MENU_GUARD
#define MENU_GUARD
#include <iostream>

void printMainMenu();

void printTestingLocations(std::string locations[], int count);

void printDetails(std::string name, std::string address, std::string hours);

void printSymptomChecker(std::string symptoms[], bool selected[]);
#endif

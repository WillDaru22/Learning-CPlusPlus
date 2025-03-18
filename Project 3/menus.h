// menus header file for learning C++ p3.  WillDaru22
#ifndef MENU_GUARD
#define MENU_GUARD
#include <iostream>
#include "LocationList.h"
#include "User.h"

void printMainMenu();

void printTestingLocations(const LocationList&);

void printSymptomChecker(std::string symptoms[], bool selected[]);

void printUserDataMenu(const User& user);

void printSettingsMenu(const bool is_metric);

void printReservationLocations(const LocationList& locations);

#endif

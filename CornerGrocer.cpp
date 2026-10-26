
/*
 * CornerGrocer.cpp
 * Developer: Drew Coleman
 * Purpose: Provide a menu for analyzing grocery
 * purchases and viewing item frequencies.
 */

#include <iostream>
#include <string>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

// Display the main menu.
void displayMenu() {
    cout << endl;
    cout << string(45, '=') << endl;
    cout << "         CORNER GROCER TRACKER" << endl;
    cout << string(45, '=') << endl;
    cout << "1. Search for a grocery item" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display purchase histogram" << endl;
    cout << "4. Exit program" << endl;
    cout << string(45, '=') << endl;
    cout << "Enter your choice (1-4): ";
}

// Run the menu until the user chooses to exit.
void runApplication() {
    GroceryTracker tracker;

    // Load the purchase records when the program starts.
    if (!tracker.loadItems("CS210_Project_Three_Input_File.txt")) {
        cout << "Unable to load grocery data. Program ending." << endl;
        return;
    }

    // Automatically create the required backup file.
    if (!tracker.createBackup("frequency.dat")) {
        cout << "Unable to create the backup file." << endl;
        return;
    }

    cout << "Welcome to the Corner Grocer!" << endl;
    cout << "Grocery purchase records loaded successfully." << endl;
    cout << "Backup file created: frequency.dat" << endl;

    int menuChoice = 0;

    while (menuChoice != 4) {
        displayMenu();

        // Check that the user enters a valid menu number.
        if (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number from 1 to 4."
                << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (menuChoice) {
        case 1: {
            string itemName;

            cout << endl;
            cout << "Enter the grocery item to search for: ";
            getline(cin, itemName);

            tracker.searchItem(itemName);
            break;
        }

        case 2:
            tracker.displayFrequencies();
            break;

        case 3:
            tracker.displayHistogram();
            break;

        case 4:
            cout << endl;
            cout << "Thank you for using Corner Grocer!" << endl;
            break;

        default:
            cout << "Invalid option. Please choose 1, 2, 3, or 4."
                << endl;
            break;
        }
    }
}

int main() {
    runApplication();
    return 0;
}

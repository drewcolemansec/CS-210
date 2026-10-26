
/*
 * GroceryTracker.cpp
 * Developer: Drew Coleman
 * Purpose: Read grocery purchase records, count item
 * frequencies, and display purchase reports.
 */

#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

// Read each grocery item and count its occurrences.
bool GroceryTracker::loadItems(const string& t_fileName) {
    ifstream inputFile(t_fileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open " << t_fileName << endl;
        return false;
    }

    m_itemFrequencies.clear();

    string itemName;

    // Each word in the file represents one purchase.
    while (inputFile >> itemName) {
        ++m_itemFrequencies[itemName];
    }

    inputFile.close();

    return !m_itemFrequencies.empty();
}

// Save all item frequencies to a backup file.
bool GroceryTracker::createBackup(const string& t_fileName) const {
    ofstream outputFile(t_fileName);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not create " << t_fileName << endl;
        return false;
    }

    for (const auto& item : m_itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
    return true;
}

// Find how many times a specific item was purchased.
void GroceryTracker::searchItem(const string& t_itemName) const {
    string searchName = t_itemName;

    // Allow users to search without matching capitalization.
    transform(searchName.begin(), searchName.end(),
        searchName.begin(),
        [](unsigned char c) {
            return static_cast<char>(tolower(c));
        });

    for (const auto& item : m_itemFrequencies) {
        string currentName = item.first;

        transform(currentName.begin(), currentName.end(),
            currentName.begin(),
            [](unsigned char c) {
                return static_cast<char>(tolower(c));
            });

        if (currentName == searchName) {
            cout << endl;
            cout << item.first << " were purchased "
                << item.second << " time(s)." << endl;
            return;
        }
    }

    cout << endl;
    cout << "No purchases found for " << t_itemName << "." << endl;
}

// Display every grocery item with its purchase count.
void GroceryTracker::displayFrequencies() const {
    cout << endl;
    cout << "GROCERY ITEM FREQUENCIES" << endl;
    cout << string(35, '-') << endl;

    for (const auto& item : m_itemFrequencies) {
        cout << left << setw(20) << item.first
            << right << item.second << endl;
    }
}

// Display purchase counts using asterisks.
void GroceryTracker::displayHistogram() const {
    cout << endl;
    cout << "GROCERY PURCHASE HISTOGRAM" << endl;
    cout << string(35, '-') << endl;

    for (const auto& item : m_itemFrequencies) {
        cout << left << setw(20) << item.first
            << string(item.second, '*') << endl;
    }
}

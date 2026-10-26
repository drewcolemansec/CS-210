#pragma once

#ifndef CORNERGROCER_GROCERYTRACKER_H_
#define CORNERGROCER_GROCERYTRACKER_H_

#include <map>
#include <string>

using namespace std;

// Tracks grocery purchases and their frequencies.
class GroceryTracker {
public:
    // Read grocery items from the input file.
    bool loadItems(const string& t_fileName);

    // Create a backup of all item frequencies.
    bool createBackup(const string& t_fileName) const;

    // Display how many times a specific item was purchased.
    void searchItem(const string& t_itemName) const;

    // Display all items and their purchase counts.
    void displayFrequencies() const;

    // Display purchase frequencies as a histogram.
    void displayHistogram() const;

private:
    // Store each grocery item and its purchase frequency.
    map<string, int> m_itemFrequencies;
};

#endif // CORNERGROCER_GROCERYTRACKER_H_

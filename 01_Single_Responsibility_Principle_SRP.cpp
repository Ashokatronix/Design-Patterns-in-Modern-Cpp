//
// Created by ashok on 23-04-2026.
// Example 1: Single Responsibility Principle (SRP)
// File: 01_Single_Responsibility_Principle_SRP.cpp
//
// Used for standard stream I/O such as cout and cin.
// In this example, it is included but not currently used.
#include <iostream>
// Used for C-style input/output functions such as printf and scanf.
// In this example, getchar() comes from this header.
#include <cstdio>
// Used for std::ofstream to write journal data to a file.
#include <fstream>
// Used for std::string to store the journal title and each entry text.
#include <string>
// Used for std::vector, a dynamic array container.
// Here it stores multiple journal entries as vector<string>.
#include <vector>
using namespace std;

// Journal is responsible for holding journal data and domain behavior.
// In SRP terms, this class should focus on journal content, not file saving.
struct Journal {
    string  titile;
    vector<string> entries;

    Journal(const string& titile) : titile(titile) {}

    // Adds a numbered entry like "1: I ate a bug".
    // to_string converts the integer count to string.
    void add_entry(const string& entry) {
        static int count = 1;
        entries.push_back(to_string(count++) + ": " + entry);
    }

    // This save function works, but it mixes persistence logic into Journal.
    // That is why it is not the preferred SRP design.
    void save(const string& filename) {
        // ofstream means "output file stream".
        // It opens/creates a file and lets us write text into it using <<.
        ofstream ofs(filename);
        for (auto& e : entries)
            ofs << e << endl;
    }
};

// PersistenceManager handles saving Journal data to external storage.
// This is a better SRP design because file persistence is separated
// from the Journal class itself.
struct PersistenceManager {
    static void save(const Journal& j, const string& filename) {
        // Good use of ofstream: persistence logic stays outside Journal.
        ofstream ofs(filename);
        for (auto& e : j.entries)
            ofs << e << endl;
    }
};

int main() {
    Journal journal("Dear Diary");
    journal.add_entry("I ate a bug");
    journal.add_entry("I love you");

    // Avoid this in an SRP example because it makes Journal manage persistence.
    // journal.save("diary.txt");

    // Preferred design: let a dedicated persistence class save the journal.
    PersistenceManager pm;
    pm.save(journal, "diary.txt");

    getchar();
    return 0;
}

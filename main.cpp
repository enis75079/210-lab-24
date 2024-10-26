/*

lab24: GM3K2
COMSC-210
Naveen Islam
IDE: vscode

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> &trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> &trip);
int main_menu();

// main function
int main() {
    srand(time(0));
    bool again = true;
    // creates a class Goat set
    set<Goat> goats;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    int num = 0;
    // while true, continue to run main menu
    while (again) {
        num = main_menu();
        if (num == 1) {
            add_goat(goats, names, colors);
        } else if (num == 2) {
            delete_goat(goats);
        } else if (num == 3) {
            display_trip(goats);
        } else if (num == 4) {
            cout << "Program terminated" << endl;
            again = false;
        } else {
            cout << "input is invalid. Program terminated" << endl;
            again = false;
        }
    }
    return 0;
}

// main menu function. outputs menu and obtains users selection dependent on an int value input
int main_menu() {
    int userNum = 0;
    bool again = true;
    while(again) {
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> userNum;
        cout << endl;

        // if user inputs a value beyond the range of the intended values, returns the function
        if ((userNum < 1)  || (userNum > 4)) {
            return userNum;
        }
        return userNum;
    }
}

// add goat function. generates a random name, color, and age. creates a new goat object and adds it to the parameter list
void add_goat(set<Goat> &goats, string goatNames[], string goatColors[]) {
    int nameNum = rand() % SZ_NAMES;
    string goatName = goatNames[nameNum];  

    int colorNum = rand() % SZ_COLORS;
    string goatColor = goatColors[colorNum];

    int age = rand() % MAX_AGE + 1;
    Goat newGoat(goatName, age, goatColor);
    goats.push_back(newGoat);
    cout << endl;

}

// delete goat function. reads user input from select_goat() function and deletes the object in that index
void delete_goat(set<Goat> &goats) {
    int deleteGoat = select_goat(goats) - 1;

    // goes through the list to find the user's desired index
    auto it = goats.begin();
    advance(it, deleteGoat);
    cout << "deleted " << it->get_name() << "." << endl;
    cout << endl;
    goats.erase(it);
    // displays the list after the user deletes an item from the list 
    display_trip(goats);
}

// select goat function. used in the delete goat function. user inputs a number that they want to delete from the list that is displayed.
int select_goat(set<Goat> &goats) {
    int i = 1;    
    int userNum = 0;
    // outputs current list
    for (const Goat &x : goats) {
        cout << "[" << i++ << "] " << x << endl;
    }
    cout << "\nDelete a goat: " << endl;
    cout << "Choice --> ";
    cin >> userNum;
    cout << endl;
    return userNum;
}

// display trip function. outputs the current list in a formatted fashion
void display_trip(set<Goat> &goats) {
    if (goats.empty()) {
        cout << "no goats" << endl;
        return;
    }
    int i = 1;
    cout << "current list: " << endl;
    cout << endl;
    for (const Goat &goat : goats) {
        cout << "[" << i++ << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ") " << endl;
    }
    cout << endl;
}
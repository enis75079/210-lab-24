// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors

    // string name parameter
    Goat(string n) {
        name = n;
        age = 0;
        color = "";
    }

    // integer age and string color parameter
    Goat(int a, string c) {
        name = "";
        age = a;
        color = c;
    }

    // string name, integer age, and string color parameter
    Goat(string n, int a, string c) {
        name = n;
        age = a;
        color = c;
    }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    bool operator<(const Goat& x) const {
        
    }
    
    // write overloaded < operator for the std::list
    friend ostream& operator<<(ostream& os, const Goat& goat) {
        os << goat.get_name() << " (Color: " << goat.get_color() << ", Age: " << goat.get_age() << ")";
        return os;
    }
};

#endif
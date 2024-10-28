#pragma once
#include <string>
#include <iostream>

using namespace std;

class Transport {
protected:
    string name;
    double speed;
    int capacity;

public:
    Transport(string n, double s, int c) : name(n), speed(s), capacity(c) {}

    void Output() const {
        cout << "Transport Name: " << name << "\nSpeed: " << speed << "\nCapacity: " << capacity << endl;
    }

    void Input() {
        cout << "Enter transport name: "; cin >> name;
        cout << "Enter speed: "; cin >> speed;
        cout << "Enter capacity: "; cin >> capacity;
    }
};

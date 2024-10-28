#include "Circle.h"
#include <iostream>

using namespace std;

void Circle::setDiameter(double d) {
    diameter = d;
}

double Circle::getDiameter() const {
    return diameter;
}

void Circle::input() {
    cout << "Enter diameter of circle: ";
    cin >> diameter;
}

void Circle::output() const {
    cout << "Circle diameter: " << diameter << endl;
}

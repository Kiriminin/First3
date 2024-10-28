#include "SquareCircle.h"
#include <iostream>

using namespace std;

SquareCircle::SquareCircle() : Square(), Circle() {}
SquareCircle::SquareCircle(double s, double d) : Square(s), Circle(d) {}

bool SquareCircle::canCircleFitInSquare() const {
    return getDiameter() <= getSide();
}

void SquareCircle::input() {
    Square::input();
    Circle::input();
}

void SquareCircle::output() const {
    Square::output();
    Circle::output();

    if (canCircleFitInSquare()) {
        cout << "The circle can fit inside the square" << endl;
    }
    else {
        cout << "The circle cannot fit inside the square" << endl;
    }
}
#include "Square.h"
#include <iostream>

using namespace std;


void Square::setSide(double s) {
	side = s;
}

double Square::getSide() const {
	return side;
}

void Square::input() {
	cout << "Enter side length of square: ";
	cin >> side;
}

void Square::output() const {
	cout << "Square side length: " << side << endl;
}
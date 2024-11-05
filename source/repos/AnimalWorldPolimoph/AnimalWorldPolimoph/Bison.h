#pragma once
#include "Herbivore.h"
#include <iostream>

using namespace std;

class Bison : public Herbivore {
public:
	Bison() {
		weight = 300;
	}

	void eat_grass() {
		weight += 15;
		cout << "Bison eats grass, weight: " << weight << endl;
	}
};


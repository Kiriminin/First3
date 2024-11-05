#pragma once
#include "Herbivore.h"
#include <iostream>

using namespace std;

class Kangaroo : public Herbivore {
public:
	Kangaroo() {
		weight = 200;
	}

	void eat_grass() {

		weight += 10;
		cout << "Kangaroo eats grass, weight: " << weight << endl;
	}
};


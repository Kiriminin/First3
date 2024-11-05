#pragma once
#include "Carnivore.h"
#include <iostream>

using namespace std;

class AustralianWolf : public Carnivore {
public:
	AustralianWolf() {
		power = 180;
	}

	void eat(Herbivore* herbivore) {
		if (herbivore->alive() and power > herbivore->get_weight()) {
			power += 10;
			cout << "Australian wolf eats herbivore, power: " << power << endl;
		}
		else {
			power -= 10;
			cout << "Australian wolf fails to eat, power: " << power << endl;
		}
	}
};


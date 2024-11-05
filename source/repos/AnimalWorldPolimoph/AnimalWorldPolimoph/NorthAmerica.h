#pragma once
#include "Continent.h"
#include "Wolf.h"
#include "Bison.h"

class NorthAmerica : public Continent {
	Herbivore* create_herbivore() override {
		return new Bison();
	}

	Carnivore* create_carnivore() override {
		return new Wolf();
	}
};


#pragma once
#include <vector>
#include "Continent.h"

using namespace std;

class AnimalWorld {
private:
	vector <Continent*> continents;
	vector <Herbivore*> herbivores;
	vector <Carnivore*> carnivores;
public:
	void add_continent(Continent* continent);
	void meals_herbivores();
	void nutrition_carnivores();
};

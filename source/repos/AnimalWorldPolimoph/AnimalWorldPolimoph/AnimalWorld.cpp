#include "AnimalWorld.h"
#include <iostream>

using namespace std;

void AnimalWorld::add_continent(Continent* continent) {
    continents.push_back(continent);

    herbivores.push_back(continent->create_herbivore());
    carnivores.push_back(continent->create_carnivore());
}

void AnimalWorld::meals_herbivores() {
    for (auto& herbivore : herbivores) {
        herbivore->eat_grass();
    }
}

void AnimalWorld::nutrition_carnivores() {
    for (auto& carnivore : carnivores) {
        for (auto& herbivore : herbivores) {
            carnivore->eat(herbivore);
        }
    }
}
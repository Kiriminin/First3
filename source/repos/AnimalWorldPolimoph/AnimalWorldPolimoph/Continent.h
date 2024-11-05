#pragma once
#include "Herbivore.h"
#include "Carnivore.h"

using namespace std;

class Continent {
public:
    virtual Herbivore* create_herbivore() = 0;
    virtual Carnivore* create_carnivore() = 0;
};

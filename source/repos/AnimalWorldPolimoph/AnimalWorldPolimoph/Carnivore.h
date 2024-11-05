#pragma once
#include "Herbivore.h"

using namespace std;

class Carnivore {
protected:
    int power;

public:
    Carnivore() : power(0) {}

    virtual void eat(Herbivore* herbivore) = 0;

    int get_power() const { return power; }
};

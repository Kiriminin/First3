#pragma once
#include "Continent.h"
#include "Wildebeest.h"
#include "Lion.h"

class Africa : public Continent {
public:
    Herbivore* create_herbivore() override {
        return new Wildebeest();
    }

    Carnivore* create_carnivore() override {
        return new Lion();
    }
};
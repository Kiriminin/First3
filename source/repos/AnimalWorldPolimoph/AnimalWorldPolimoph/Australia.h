#pragma once
#include "Continent.h"
#include "Kangaroo.h"
#include "AustralianWolf.h"

class Australia : public Continent {
    Herbivore* create_herbivore() override {
        return new Kangaroo();
    }

    Carnivore* create_carnivore() override {
        return new AustralianWolf();
    }
};

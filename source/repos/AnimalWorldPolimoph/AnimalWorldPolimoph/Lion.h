#pragma once
#include "Carnivore.h"
#include <iostream>

using namespace std;

class Lion : public Carnivore {
public:
    Lion() {
        power = 200;
    }

    void eat(Herbivore* herbivore) override {
        if (herbivore->alive() and power > herbivore->get_weight()) {
            power += 10;
            cout << "Lion eats herbivore, power: " << power << endl;
        }
        else {
            power -= 10;
            cout << "Lion fails to eat, power: " << power << endl;
        }
    }
};

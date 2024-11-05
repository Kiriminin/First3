#pragma once
#include "Carnivore.h"
#include <iostream>

using namespace std;

class Wolf : public Carnivore {
public:
    Wolf() {
        power = 200;
    }

    void eat(Herbivore* herbivore) {
        if (herbivore->alive() and power > herbivore->get_weight()) {
            power += 10;
            cout << "Wolf eats herbivore, power: " << power << endl;
        }
        else {
            power -= 10;
            cout << "Wolf fails to eat, power: " << power << endl;
        }
    }
};


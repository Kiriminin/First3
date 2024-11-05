#pragma once
#include "Herbivore.h"
#include <iostream>

using namespace std;

class Wildebeest : public Herbivore {
public:
    Wildebeest() {
        weight = 150;
    }

    void eat_grass() override {
        weight += 10;
        cout << "Wildebeest eats grass, weight: " << weight << endl;
    }
};  

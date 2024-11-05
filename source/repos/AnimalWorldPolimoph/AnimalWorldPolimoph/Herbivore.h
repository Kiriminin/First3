#pragma once

using namespace std;

class Herbivore {
protected:
    int weight;
    bool is_alive;

public:
    Herbivore() : weight(0), is_alive(true) {}

    virtual void eat_grass() = 0;

    int get_weight() const { return weight; }

    bool alive() const { return is_alive; }
};

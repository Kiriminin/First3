#pragma once
#include <iostream>

class Square
{
    double side;

public:
    Square() : side(0) {}
    Square(double s) : side(s) {}

    void setSide(double s);
    double getSide() const;

    void input();
    void output() const;
};
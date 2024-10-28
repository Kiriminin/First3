#pragma once
#include <iostream>

class Circle
{
    double diameter;
public:
    Circle() : diameter(0) {}
    Circle(double d) : diameter(d) {}
    void setDiameter(double d);
    double getDiameter() const;
    void input();
    void output() const;
};
#pragma once
#include "Square.h"
#include "Circle.h"

class SquareCircle : public Square, public Circle
{
public:
    SquareCircle();
    SquareCircle(double s, double d);

    bool canCircleFitInSquare() const;

    void input();
    void output() const;
};
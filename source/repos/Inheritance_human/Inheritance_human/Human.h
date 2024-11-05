#pragma once
class Human  // Base_class
{
protected:
    char* name;
    int age;
    double salary;

public:
    Human();
    Human(const char*, int, double);
    virtual void Output() = 0;
    virtual void Salary() = 0;
    void Input();

    virtual ~Human() = 0;
}; 

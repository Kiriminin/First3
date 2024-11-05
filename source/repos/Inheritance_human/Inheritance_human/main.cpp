#include "Student.h"
#include "Programmer.h"
#include <iostream>
using namespace std;

int main()
{
    Human* people[2];

    people[0] = new Student("Helen", 23, 1500.0, "It_Step");

    people[1] = new Student("Vlad", 19, 1000.0, "Technikum");

    for (int i = 0; i < 2; ++i)
    {
        people[i]->Output();
        people[i]->Salary();
        cout << endl;
    }

    for (int i = 0; i < 2; ++i)
    {
        delete people[i];
    }

    return 0;
}
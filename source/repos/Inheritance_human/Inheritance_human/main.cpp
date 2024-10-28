#include "Student.h"
#include "Programmer.h"
#include <iostream>
using namespace std;

int main()
{
    Human* people[2];

    people[0] = new Student("Alice", 20, 1000.0, "Harvard");

    people[1] = new Student("Bob", 18, 1000.0, "Krutoi unik");

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
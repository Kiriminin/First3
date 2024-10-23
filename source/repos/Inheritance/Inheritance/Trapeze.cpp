#include "Trapeze.h"
#include <iostream>
using namespace std;
void Trapeze::ShowArea() const
{
	cout << ((m_value1 + m_value2) * height) / 2 << endl;
}
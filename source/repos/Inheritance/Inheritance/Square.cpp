#include "Square.h"
#include <iostream>
using namespace std;
void Square::ShowArea() const
{
	cout << "Area of rectangle: " << m_value1 * m_value2 << endl;
}
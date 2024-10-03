#include <iostream>
#include "Vector.h"
using namespace std;

int main() {

	// Создаем объект вектора с 5 элементами
	MyVector obj1(5);
	// Заполняем объект случайными числами
	obj1.InputRand();
	// Выводим объект на экран
	obj1.Print(); 

	MyVector obj2 = obj1 - 2;    // Уменьшаем размер obj1 на 2 элемента (вызывается перегруженный оператор '-')
	// Выводим obj2 на экран
	obj2.Print();


	MyVector obj3 = obj1 + 5;
	obj3.Print();
	
	// Создаем еще один объект вектора с 2 элементами
	MyVector obj4(2);
	obj4.InputRand();
	obj4.Print();

	// Складываем два вектора (obj1 и obj4), результат сохраняется в obj5
	MyVector obj5 = obj1 + obj4;
	obj5.Print();

	// Умножаем все элементы obj1 на 3 (вызывается перегруженный оператор '*')
	MyVector obj6 = obj1 * 3;
	obj6.Print();
	
	// Уменьшаем obj1 на 5 элементов с начала (вызывается внешний оператор '5 - obj1')
	MyVector obj7 = 5 - obj1;
	
	return 0;
}
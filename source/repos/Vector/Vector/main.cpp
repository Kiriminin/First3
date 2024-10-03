#include <iostream>
#include "Vector.h"
using namespace std;

int main() {

	// ������� ������ ������� � 5 ����������
	MyVector obj1(5);
	// ��������� ������ ���������� �������
	obj1.InputRand();
	// ������� ������ �� �����
	obj1.Print(); 

	MyVector obj2 = obj1 - 2;    // ��������� ������ obj1 �� 2 �������� (���������� ������������� �������� '-')
	// ������� obj2 �� �����
	obj2.Print();


	MyVector obj3 = obj1 + 5;
	obj3.Print();
	
	// ������� ��� ���� ������ ������� � 2 ����������
	MyVector obj4(2);
	obj4.InputRand();
	obj4.Print();

	// ���������� ��� ������� (obj1 � obj4), ��������� ����������� � obj5
	MyVector obj5 = obj1 + obj4;
	obj5.Print();

	// �������� ��� �������� obj1 �� 3 (���������� ������������� �������� '*')
	MyVector obj6 = obj1 * 3;
	obj6.Print();
	
	// ��������� obj1 �� 5 ��������� � ������ (���������� ������� �������� '5 - obj1')
	MyVector obj7 = 5 - obj1;
	
	return 0;
}
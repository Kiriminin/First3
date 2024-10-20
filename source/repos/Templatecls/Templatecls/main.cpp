#include <iostream> 

#include "Doo.h" // ���������� ������������ ���� � ��������� ������� Doo
#include "Max.h"  // ���������� ������������ ���� � ��������� ������� Maximum

using namespace std; // ���������� ������������ ���� std ��� ��������� ����


// ����������� ���������� ��� ������ Maximum � ������ int � int
typedef Maximum<int, int> My_int;

int main()
{
    //Foo<int> obj1(10); 
    //obj1.Show(); 

    //Foo<char> obj2('A'); 
    //obj2.Show(); 

    //Foo<double> obj3(2.6); 
    //obj3.Show(); 

    // ������� ������ ������ Maximum<int, int> � ����� ���������� 10 � 20
    My_int obj4(10, 20);// Maximum<int, int> obj4(10, 20); 
    cout << obj4.MaxValue() << endl << endl; // ������� ������������ �������� �� 10 � 20

    // ������� ������ ������ Maximum<int, char> � ���������� 10 � 'A'
    Maximum<int, char> obj5(10, 'A');
    // ������� ������������ �������� (����� ������ � �������� 'A')
    cout << obj5.MaxValue() << endl << endl;

    // ������� ������ ������ Maximum<char, int> � ���������� 'A' � 10
    Maximum<char, int> obj6('A', 10);
    cout << obj6.MaxValue() << endl << endl;  // ������� ������������ �������� (����� �������� 'A' � ������ 10)

    // ������� ������ ������ Maximum<double, int> � ���������� 5.7 � 2
    Maximum<double, int> obj7(5.7, 2);
    cout << obj7.MaxValue() << endl << endl;  // ������� ������������ �������� ����� 5.7 � 2


    return 0; // ��������� ���������� ���������
}
#include <iostream> 

#include "Doo.h" // Подключаем заголовочный файл с шаблонным классом Doo
#include "Max.h"  // Подключаем заголовочный файл с шаблонным классом Maximum

using namespace std; // Используем пространство имен std для упрощения кода


// Определение псевдонима для класса Maximum с типами int и int
typedef Maximum<int, int> My_int;

int main()
{
    //Foo<int> obj1(10); 
    //obj1.Show(); 

    //Foo<char> obj2('A'); 
    //obj2.Show(); 

    //Foo<double> obj3(2.6); 
    //obj3.Show(); 

    // Создаем объект класса Maximum<int, int> с двумя значениями 10 и 20
    My_int obj4(10, 20);// Maximum<int, int> obj4(10, 20); 
    cout << obj4.MaxValue() << endl << endl; // Выводим максимальное значение из 10 и 20

    // Создаем объект класса Maximum<int, char> с значениями 10 и 'A'
    Maximum<int, char> obj5(10, 'A');
    // Выводим максимальное значение (между числом и символом 'A')
    cout << obj5.MaxValue() << endl << endl;

    // Создаем объект класса Maximum<char, int> с значениями 'A' и 10
    Maximum<char, int> obj6('A', 10);
    cout << obj6.MaxValue() << endl << endl;  // Выводим максимальное значение (между символом 'A' и числом 10)

    // Создаем объект класса Maximum<double, int> с значениями 5.7 и 2
    Maximum<double, int> obj7(5.7, 2);
    cout << obj7.MaxValue() << endl << endl;  // Выводим максимальное значение между 5.7 и 2


    return 0; // Завершаем выполнение программы
}
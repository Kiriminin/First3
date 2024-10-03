#pragma once
#include <iostream>

class MyVector {
private:
    int* arr; // Указатель на динамический массив
    int size; // Текущий размер массива
   
    // Дружественные операторы для ввода-вывода
    friend ostream& operator<<(ostream& os, MyVector obj);
    friend istream& operator>>(istream& is, MyVector& obj);

public:
    MyVector();   // Конструктор по умолчанию
    MyVector(int s); // Конструктор с параметром (размер массива)
    ~MyVector(); // Деструктор для очистки памяти

    void InputRand();  // Заполнение массива случайными числами
    void Print();  // Вывод массива на экран
     
    void PushBack(int a);  // Добавить элемент в конец
    int PopBack(); // Удалить элемент с конца и вернуть его

    void PushForward(int a); // Добавить элемент в начало
    int PopForward();  // Удалить элемент с начала и вернуть его

    void PushIndex(int a, int index); // Добавить элемент по индексу
    int RemoveAtIndex(int index); // Удаление элемента по индексу

    void AppendArray(int newArr[], int newSize); // Добавить массив в конец
    int* getArray() const;  // Возвращает указатель на массив
    int getSize() const;  // Возвращает текущий размер массива
    void setArray(int* newArr, int newSize); // Задать новый массив и его размер
    
    // Перегруженные операторы для работы с объектами класса
    MyVector operator-(int a); // Уменьшить размер на a элементов
    MyVector operator+(int a);
    MyVector operator*(int a);
    
    // Объединение двух векторов
    MyVector operator+(const MyVector& obj);

    MyVector& operator++(); // Префиксный инкремент (добавить элемент 0 в начало)
    MyVector operator++(int);
    MyVector& operator--(); // Префиксный декремент (удалить элемент с начала)
    MyVector operator--(int);

    MyVector& operator+=(int a);
    MyVector& operator-=(int a);
    MyVector& operator*=(int a);

    MyVector& operator=(const MyVector& obj); // Оператор присваивания
};
MyVector operator-(int a, const MyVector& obj); // Удалить первые a элементов вектора
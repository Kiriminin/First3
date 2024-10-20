#pragma once

#include <iostream> 

// Шаблонный класс Doo, который управляет динамически выделяемым ресурсом (указателем на значение)
template <typename Type>
class Doo
{
private:

    // Указатель на значение типа Type
    Type* m_value;
public:

    // Конструктор, который принимает значение по константной ссылке и выделяет память под него
    Doo(const Type& value);

    // Конструктор копирования, который делает глубокую копию объекта
    Doo(const Doo& obj);

    // Деструктор, который освобождает динамически выделенную память
    ~Doo();

    // Метод для вывода значения
    void Show();
};

// Реализация конструктора, принимающего значение
template <typename Type>
Doo<Type>::Doo(const Type& value)
{
    std::cout << "<Type>" << std::endl;

    // Выделяем память и инициализируем указатель значением
    m_value = new Type(value);
}

// Реализация конструктора копирования
template <typename Type>
Doo<Type>::Doo(const Doo<Type>& obj)
{
    // Выделяем память для нового объекта и копируем значение из оригинала
    m_value = new Type(*obj.m_value);
}

// Реализация деструктора
template <typename Type>
Doo<Type>::~Doo()
{
    // Освобождаем память, выделенную под массив (но используется new, должно быть delete, а не delete[])
    delete[] m_value;
}

// Метод для вывода значения на консоль
template <typename Type>
void Doo<Type>::Show()
{
    std::cout << *m_value << std::endl << std::endl;
}

// Специализация шаблона для типа char (работает иначе, чем для остальных типов)
template <>
class Doo<char>
{
private:

    // Указатель на символ (char)
    char* m_value;

public:

    // Конструктор, который принимает значение типа char по ссылке и выделяет память
    Doo(const char& value);

    // Конструктор копирования для char
    Doo(const Doo& obj);

    // Деструктор, который освобождает память
    ~Doo();

    // Метод для вывода символа
    void Show();
};

// Реализация конструктора для типа char
Doo<char>::Doo(const char& value)
{
    std::cout << "<char>" << std::endl;

    // Выделяем память под символ
    m_value = new char(value);
}

// Реализация конструктора копирования для char
Doo<char>::Doo(const Doo<char>& obj)
{
    // Выделяем память для нового символа и копируем значение
    m_value = new char(*obj.m_value);
}

// Реализация деструктора для типа char
Doo<char>::~Doo()
{
    // Освобождаем память, выделенную под символ
    delete[] m_value;
}
// Метод для вывода символа на консоль
void Doo<char>::Show()
{
    std::cout << *m_value << std::endl << std::endl;
}
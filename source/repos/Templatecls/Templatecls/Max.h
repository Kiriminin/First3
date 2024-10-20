#pragma once 

#include <iostream> 

// Шаблонный класс Maximum для нахождения максимального значения между двумя элементами разного типа
template <typename Type1, typename Type2>
class Maximum
{
private:
    // Переменные для хранения двух значений, которые будут сравниваться
    Type1 m_value1;
    Type2 m_value2;

public:

    // Конструктор, принимающий два значения
    Maximum(Type1 value1, Type2 value2);
    
    // Метод для возвращения максимального значения
    Type1 MaxValue();
};
// Реализация конструктора для шаблонного класса
template <typename Type1, typename Type2>
Maximum<Type1, Type2>::Maximum(Type1 value1, Type2 value2) :
    m_value1(value1),
    m_value2(value2)
{
    std::cout << "<Type1, Type2>" << std::endl;
}
// Реализация метода MaxValue для сравнения двух значений
template <typename Type1, typename Type2>
Type1 Maximum<Type1, Type2>::MaxValue()
{
    // Возвращаем большее из двух значений, сравнивая их
    return m_value1 > m_value2 ? m_value1 : m_value2;
}

// Специализация шаблона для работы с типом char* (строки C-style)
template <>
class Maximum<char*, char*>
{
private:

    // Переменные для хранения двух строк
    char* m_value1;
    char* m_value2;

public:

    // Конструктор, принимающий две строки
    Maximum(char* value1, char* value2);

    // Метод для возвращения "большей" строки на основе сравнения strcmp
    char* MaxValue();
};
// Реализация конструктора для работы с char* (строками)
Maximum<char*, char*>::Maximum(char* value1, char* value2) :
    m_value1(value1),
    m_value2(value2)
{
    std::cout << "<char*, char*>" << std::endl;
}
// Реализация метода MaxValue для строк, использующий strcmp для сравнения строк
char* Maximum<char*, char*>::MaxValue()
{
    // Сравнение строк с помощью strcmp и возврат "большей" строки
    return strcmp(m_value1, m_value2) > 0 ? m_value1 : m_value2;
}

// Шаблонная специализация для случая, когда второй параметр - это тип char
template <typename Type>
class Maximum <Type, char>
{
private:

    // Переменные для хранения значения произвольного типа и символа
    Type m_value1;
    char m_value2;

public:

    // Конструктор, принимающий значение типа Type и символ
    Maximum(Type value1, char value2) :
        m_value1(value1),
        m_value2(value2)
    {
        std::cout << "<Type, char>" << std::endl;
    }
    // Метод для возвращения большего значения
    Type MaxValue();
};
// Реализация метода MaxValue для случая с типом Type и char
template <typename Type>
Type Maximum<Type, char>::MaxValue()
{
    // Сравниваем значение Type с символом и возвращаем большее
    return m_value1 > m_value2 ? m_value1 : m_value2;
}

// Шаблонная специализация для случая, когда первый параметр - это тип double
template <typename Type>
class Maximum <double, Type>
{
private:
    // Переменные для хранения значения типа double и значения типа Type
    double m_value1;
    TItem m_value2;

public:
    
    // Конструктор, принимающий double и значение типа Type
    Maximum(double value1, Type value2);

    // Метод для возвращения большего значения
    Type MaxValue();
};

// Реализация конструктора для случая с double и Type
template <typename Type>
Maximum<double, Type>::Maximum(double value1, Type value2) :
    m_value1(value1),
    m_value2(value2)
{
    std::cout << "<double, Type>" << std::endl;
}

template <typename Type>
Type Maximum<double, Type>::MaxValue()
{
    // Сравниваем значение double с Type и возвращаем большее
    return m_value1 > m_value2 ? m_value1 : m_value2;
}

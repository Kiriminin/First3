#pragma once 

#include <iostream> 

// ��������� ����� Maximum ��� ���������� ������������� �������� ����� ����� ���������� ������� ����
template <typename Type1, typename Type2>
class Maximum
{
private:
    // ���������� ��� �������� ���� ��������, ������� ����� ������������
    Type1 m_value1;
    Type2 m_value2;

public:

    // �����������, ����������� ��� ��������
    Maximum(Type1 value1, Type2 value2);
    
    // ����� ��� ����������� ������������� ��������
    Type1 MaxValue();
};
// ���������� ������������ ��� ���������� ������
template <typename Type1, typename Type2>
Maximum<Type1, Type2>::Maximum(Type1 value1, Type2 value2) :
    m_value1(value1),
    m_value2(value2)
{
    std::cout << "<Type1, Type2>" << std::endl;
}
// ���������� ������ MaxValue ��� ��������� ���� ��������
template <typename Type1, typename Type2>
Type1 Maximum<Type1, Type2>::MaxValue()
{
    // ���������� ������� �� ���� ��������, ��������� ��
    return m_value1 > m_value2 ? m_value1 : m_value2;
}

// ������������� ������� ��� ������ � ����� char* (������ C-style)
template <>
class Maximum<char*, char*>
{
private:

    // ���������� ��� �������� ���� �����
    char* m_value1;
    char* m_value2;

public:

    // �����������, ����������� ��� ������
    Maximum(char* value1, char* value2);

    // ����� ��� ����������� "�������" ������ �� ������ ��������� strcmp
    char* MaxValue();
};
// ���������� ������������ ��� ������ � char* (��������)
Maximum<char*, char*>::Maximum(char* value1, char* value2) :
    m_value1(value1),
    m_value2(value2)
{
    std::cout << "<char*, char*>" << std::endl;
}
// ���������� ������ MaxValue ��� �����, ������������ strcmp ��� ��������� �����
char* Maximum<char*, char*>::MaxValue()
{
    // ��������� ����� � ������� strcmp � ������� "�������" ������
    return strcmp(m_value1, m_value2) > 0 ? m_value1 : m_value2;
}

// ��������� ������������� ��� ������, ����� ������ �������� - ��� ��� char
template <typename Type>
class Maximum <Type, char>
{
private:

    // ���������� ��� �������� �������� ������������� ���� � �������
    Type m_value1;
    char m_value2;

public:

    // �����������, ����������� �������� ���� Type � ������
    Maximum(Type value1, char value2) :
        m_value1(value1),
        m_value2(value2)
    {
        std::cout << "<Type, char>" << std::endl;
    }
    // ����� ��� ����������� �������� ��������
    Type MaxValue();
};
// ���������� ������ MaxValue ��� ������ � ����� Type � char
template <typename Type>
Type Maximum<Type, char>::MaxValue()
{
    // ���������� �������� Type � �������� � ���������� �������
    return m_value1 > m_value2 ? m_value1 : m_value2;
}

// ��������� ������������� ��� ������, ����� ������ �������� - ��� ��� double
template <typename Type>
class Maximum <double, Type>
{
private:
    // ���������� ��� �������� �������� ���� double � �������� ���� Type
    double m_value1;
    TItem m_value2;

public:
    
    // �����������, ����������� double � �������� ���� Type
    Maximum(double value1, Type value2);

    // ����� ��� ����������� �������� ��������
    Type MaxValue();
};

// ���������� ������������ ��� ������ � double � Type
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
    // ���������� �������� double � Type � ���������� �������
    return m_value1 > m_value2 ? m_value1 : m_value2;
}

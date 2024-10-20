#pragma once

#include <iostream> 

// ��������� ����� Doo, ������� ��������� ����������� ���������� �������� (���������� �� ��������)
template <typename Type>
class Doo
{
private:

    // ��������� �� �������� ���� Type
    Type* m_value;
public:

    // �����������, ������� ��������� �������� �� ����������� ������ � �������� ������ ��� ����
    Doo(const Type& value);

    // ����������� �����������, ������� ������ �������� ����� �������
    Doo(const Doo& obj);

    // ����������, ������� ����������� ����������� ���������� ������
    ~Doo();

    // ����� ��� ������ ��������
    void Show();
};

// ���������� ������������, ������������ ��������
template <typename Type>
Doo<Type>::Doo(const Type& value)
{
    std::cout << "<Type>" << std::endl;

    // �������� ������ � �������������� ��������� ���������
    m_value = new Type(value);
}

// ���������� ������������ �����������
template <typename Type>
Doo<Type>::Doo(const Doo<Type>& obj)
{
    // �������� ������ ��� ������ ������� � �������� �������� �� ���������
    m_value = new Type(*obj.m_value);
}

// ���������� �����������
template <typename Type>
Doo<Type>::~Doo()
{
    // ����������� ������, ���������� ��� ������ (�� ������������ new, ������ ���� delete, � �� delete[])
    delete[] m_value;
}

// ����� ��� ������ �������� �� �������
template <typename Type>
void Doo<Type>::Show()
{
    std::cout << *m_value << std::endl << std::endl;
}

// ������������� ������� ��� ���� char (�������� �����, ��� ��� ��������� �����)
template <>
class Doo<char>
{
private:

    // ��������� �� ������ (char)
    char* m_value;

public:

    // �����������, ������� ��������� �������� ���� char �� ������ � �������� ������
    Doo(const char& value);

    // ����������� ����������� ��� char
    Doo(const Doo& obj);

    // ����������, ������� ����������� ������
    ~Doo();

    // ����� ��� ������ �������
    void Show();
};

// ���������� ������������ ��� ���� char
Doo<char>::Doo(const char& value)
{
    std::cout << "<char>" << std::endl;

    // �������� ������ ��� ������
    m_value = new char(value);
}

// ���������� ������������ ����������� ��� char
Doo<char>::Doo(const Doo<char>& obj)
{
    // �������� ������ ��� ������ ������� � �������� ��������
    m_value = new char(*obj.m_value);
}

// ���������� ����������� ��� ���� char
Doo<char>::~Doo()
{
    // ����������� ������, ���������� ��� ������
    delete[] m_value;
}
// ����� ��� ������ ������� �� �������
void Doo<char>::Show()
{
    std::cout << *m_value << std::endl << std::endl;
}
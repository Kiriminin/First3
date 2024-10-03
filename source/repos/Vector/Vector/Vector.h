#pragma once
#include <iostream>

class MyVector {
private:
    int* arr; // ��������� �� ������������ ������
    int size; // ������� ������ �������
   
    // ������������� ��������� ��� �����-������
    friend ostream& operator<<(ostream& os, MyVector obj);
    friend istream& operator>>(istream& is, MyVector& obj);

public:
    MyVector();   // ����������� �� ���������
    MyVector(int s); // ����������� � ���������� (������ �������)
    ~MyVector(); // ���������� ��� ������� ������

    void InputRand();  // ���������� ������� ���������� �������
    void Print();  // ����� ������� �� �����
     
    void PushBack(int a);  // �������� ������� � �����
    int PopBack(); // ������� ������� � ����� � ������� ���

    void PushForward(int a); // �������� ������� � ������
    int PopForward();  // ������� ������� � ������ � ������� ���

    void PushIndex(int a, int index); // �������� ������� �� �������
    int RemoveAtIndex(int index); // �������� �������� �� �������

    void AppendArray(int newArr[], int newSize); // �������� ������ � �����
    int* getArray() const;  // ���������� ��������� �� ������
    int getSize() const;  // ���������� ������� ������ �������
    void setArray(int* newArr, int newSize); // ������ ����� ������ � ��� ������
    
    // ������������� ��������� ��� ������ � ��������� ������
    MyVector operator-(int a); // ��������� ������ �� a ���������
    MyVector operator+(int a);
    MyVector operator*(int a);
    
    // ����������� ���� ��������
    MyVector operator+(const MyVector& obj);

    MyVector& operator++(); // ���������� ��������� (�������� ������� 0 � ������)
    MyVector operator++(int);
    MyVector& operator--(); // ���������� ��������� (������� ������� � ������)
    MyVector operator--(int);

    MyVector& operator+=(int a);
    MyVector& operator-=(int a);
    MyVector& operator*=(int a);

    MyVector& operator=(const MyVector& obj); // �������� ������������
};
MyVector operator-(int a, const MyVector& obj); // ������� ������ a ��������� �������
#include "MyString.h"
#include <iostream>

using namespace std;

// ������������� ����������� ����� ��� ������������ ���������� ��������
int MyString::countLiveObj = 0;
int MyString::countCreatedObj = 0;

// ����������� �� ���������, ������� ������ ������ 80 ��������
MyString::MyString() {
    strLength = 80; // ��������� ����� ������ �� ���������
    strData = new char[strLength + 1]; // ��������� ������ ��� ������ + 1 ��� ������� ����� ������
    for (size_t i = 0; i <= strLength; ++i) {
        strData[i] = '\0'; // ������������� ���� �������� � ������ ������� ���������
    }

    // ���������� ��������� ��������� � ����� ��������
    countCreatedObj++;
    countLiveObj++;
}

// �����������, ������� ��������� ������ ������
MyString::MyString(int size) {
    if (size < 0) size = 0; // ��������� ������� �� 0, ���� ������ ������������� ��������
    strLength = static_cast<size_t>(size); // ���������� ������� � ���� size_t
    strData = new char[strLength + 1]; // ��������� ������ ��� ������
    for (size_t i = 0; i <= strLength; ++i) {
        strData[i] = '\0'; // ������������� �������� ������ �������� ����������
    }

    // ���������� �������� ����� ��������
    countLiveObj++;
}

// ����������� �����������, ������� ������� ����� ������ �� ������ ������������
MyString::MyString(const MyString& other) {
    strLength = other.strLength; // ����������� ����� ������
    strData = new char[strLength + 1]; // ��������� ������ ��� ����� ������
    strcpy_s(strData, strLength + 1, other.strData); // ����������� ����������� ������ ������ � ����� ������
    countCreatedObj++; // ���������� �������� ��������� ��������
    countLiveObj++; // ���������� �������� ����� ��������
}

// ����������, ����������� ������, ������� �������
MyString::~MyString() {
    delete[] strData; // ������������ ������, ������� �������
    countLiveObj--; // ���������� �������� ����� ��������
}

// ����� ��� ����������� ����������� ����� ������ � ������
void MyString::MyStrcpy(MyString& obj) {
    if (strData == nullptr) return; // ���� ������� ������ �����, ������ �� ������
    delete[] obj.strData; // ������������ ������, ������� ������� � ������� ����������

    obj.strLength = strLength; // ����������� ����� ������� ������
    obj.strData = new char[strLength + 1]; // ��������� ������ ��� ����� ������

    for (int i = 0; i < strLength; i++) {
        obj.strData[i] = strData[i]; // ����������� �������� �� ������� ������
    }

    obj.strData[strLength] = '\0'; // ��������� ������� ����� ������
}

// ����� ��� ������ ��������� � ������� ������
bool MyString::MyStrStr(const char* substr) {
    if (strData == nullptr || substr == nullptr) return false; // �������� �� ������� ���������
    // �������� ������ ���������
}
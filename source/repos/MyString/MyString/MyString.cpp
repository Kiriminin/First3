#include "MyString.h"
#include <iostream>

using namespace std;

// Инициализация статических полей для отслеживания количества объектов
int MyString::countLiveObj = 0;
int MyString::countCreatedObj = 0;

// Конструктор по умолчанию, создает строку длиной 80 символов
MyString::MyString() {
    strLength = 80; // Установка длины строки по умолчанию
    strData = new char[strLength + 1]; // Выделение памяти для строки + 1 для символа конца строки
    for (size_t i = 0; i <= strLength; ++i) {
        strData[i] = '\0'; // Инициализация всех символов в строке нулевым значением
    }

    // Увеличение счетчиков созданных и живых объектов
    countCreatedObj++;
    countLiveObj++;
}

// Конструктор, который принимает размер строки
MyString::MyString(int size) {
    if (size < 0) size = 0; // Установка размера на 0, если задано отрицательное значение
    strLength = size;
    strData = new char[strLength + 1]; // Выделение памяти для строки
    for (int i = 0U; i <= strLength; ++i) { // 0U unsigned
        strData[i] = '\0'; // Инициализация символов строки нулевыми значениями
    }

    // Увеличение счетчика живых объектов
    countCreatedObj++;
    countLiveObj++;
}

// Конструктор копирования, который создает новую строку на основе существующей
MyString::MyString(const char* initStr) {
    if (initStr == nullptr) {
        strLength = 0;
        strData = new char[1];
        strData[0] = '\0';
    }
    else {
        strLength = strlen(initStr);
        strData = new char[strLength + 1];
        strcpy_s(strData, strLength + 1, initStr);
    }

    countCreatedObj++;
    countLiveObj++; // Увеличение счетчика живых объектов
}


MyString::MyString(const MyString& other) {
    strLength = other.strLength;
    strData = new char[strLength + 1];
    strcpy_s(strData, strLength + 1, other.strData);

    countCreatedObj++;
    countLiveObj++;
}


MyString::MyString(MyString&& obj) {
    strData = obj.strData;
    strLength = obj.strLength;
    obj.strData = nullptr;
    obj.strLength = 0;
}

MyString& MyString::operator=(MyString&& obj) {
    if (strData != nullptr) delete[] strData;

    strData = obj.strData;
    strLength = obj.strLength;
    obj.strData = nullptr;
    obj.strLength = 0;

    return *this;
}

MyString::MyString(initializer_list<char> a) {
    strLength = a.size();
    strData = new char[strLength + 1];

    for (auto x = a.begin(); x != a.end(); ++x) {
        *strData = *x;
        strData++;
    }
    *strData = '\0';
    strData -= strLength;
}

MyString::~MyString() {
    delete[] strData;
    countLiveObj--;
}

void MyString::MyStrcpy(MyString& obj) {
    if (strData == nullptr) return;
    delete[] obj.strData;

    obj.strLength = strLength;
    obj.strData = new char[strLength + 1];

    for (int i = 0; i < strLength; i++) {
        obj.strData[i] = strData[i];
    }

    obj.strData[strLength] = '\0';
}

bool MyString::MyStrStr(const char* substr) {
    if (strData == nullptr or substr == nullptr) return false;

    for (int i = 0; strData[i] != '\0'; i++) {
        int j = 0;

        while (substr[j] != '\0' and strData[i + j] != '\0' and strData[i + j] == substr[j]) {
            j++;
        }

        if (substr[j] == '\0') return true;
    }

    return false;
}
int MyString::MyChr(char c) {
    if (strData == nullptr) return -1;

    for (int i = 0; strData[i] != '\0'; i++) {
        if (strData[i] == c) {
            return i;
        }
    }

    return -1;
}
int MyString::MyStrLen() {
    if (strData == nullptr) return 0;

    int strLength = 0;

    while (strData[strLength] != '\0') {
        strLength++;
    }

    return strLength;
}
void MyString::MyStrCat(MyString& b) {
    if (strData == nullptr) return;
    if (b.strData == nullptr) return;

    int newLength = MyStrLen() + b.MyStrLen();
    char* newStr = new char[newLength + 1];

    int i = 0;
    for (; strData[i] != '\0'; i++) {
        newStr[i] = strData[i];
    }

    for (int j = 0; b.strData[j] != '\0'; j++, i++) {
        newStr[i] = b.strData[j];
    }

    newStr[newLength] = '\0';
    delete[] strData;
    strData = newStr;
    strLength = newLength;
}
void MyString::MyDelChr(char c) {
    if (strData == nullptr) return;

    int j = 0;

    for (int i = 0; strData[i] != '\0'; i++) {
        if (strData[i] != c) {
            strData[j++] = strData[i];
        }
    }

    strData = '\0';
    strLength = j;
}
int MyString::MyStrCmp(MyString& b) {
    if (strData == nullptr && b.strData == nullptr) return 0;
    if (strData == nullptr) return -1;
    if (b.strData == nullptr) return 1;

    int i = 0;
    while (strData[i] != '\0' && b.strData[i] != '\0') {
        if (strData[i] < b.strData[i]) return -1;
        if (strData[i] > b.strData[i]) return 1;
        i++;
    }

    if (strData[i] == '\0' && b.strData[i] == '\0') return 0;
    if (strData[i] == '\0') return -1;
    return 1;
}
MyString& MyString::operator+=(const char* appendStr) {
    if (appendStr == nullptr) return *this;

    MyString temp(appendStr);

    MyStrCat(temp);

    return *this;
}
MyString operator+(const char* prefixStr, const MyString& myStr) {
    if (prefixStr == nullptr) return myStr;

    MyString result(prefixStr);

    MyString temp(myStr);
    result.MyStrCat(temp);

    return result;
}
void MyString::Print() {
    if (strData == nullptr) {
        cout << "[null]" << endl;
    }
    else {
        cout << strData << endl;
    }
}
void MyString::Input() {
    char buffer[1024];
    cout << "Enter a string: ";

    cin.getline(buffer, 1024);

    delete[] strData;

    strLength = strlen(buffer);
    strData = new char[strLength + 1];
    strcpy_s(strData, strLength + 1, buffer);
}
void MyString::GetCountLiveObj() {
    cout << "Number of live objects: " << countLiveObj << endl;
}

void MyString::GetCountCreatedObj() {
    cout << "Total number of objects created: " << countCreatedObj << endl;
}

MyString MyString::operator=(const MyString& obj) {
    if (this == &obj) return *this;
    delete[] strData;

    strLength = obj.strLength;
    strData = new char[strLength + 1];
    strcpy_s(strData, strLength + 1, obj.strData);

    return *this;
}
MyString MyString::operator[](int index) {
    return strData[index];
}

void MyString::operator()() {
    Print();
}

ostream& operator<<(ostream& os, MyString obj) {
    obj.Print();
    return os;
}

istream& operator>>(istream& is, MyString& obj) {
    obj.Input();
    return is;
}
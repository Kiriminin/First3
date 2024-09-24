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
    strLength = static_cast<size_t>(size); // Приведение размера к типу size_t
    strData = new char[strLength + 1]; // Выделение памяти для строки
    for (size_t i = 0; i <= strLength; ++i) {
        strData[i] = '\0'; // Инициализация символов строки нулевыми значениями
    }

    // Увеличение счетчика живых объектов
    countLiveObj++;
}

// Конструктор копирования, который создает новую строку на основе существующей
MyString::MyString(const MyString& other) {
    strLength = other.strLength; // Копирование длины строки
    strData = new char[strLength + 1]; // Выделение памяти для новой строки
    strcpy_s(strData, strLength + 1, other.strData); // Копирование содержимого другой строки в новую строку
    countCreatedObj++; // Увеличение счетчика созданных объектов
    countLiveObj++; // Увеличение счетчика живых объектов
}

// Деструктор, освобождает память, занятую строкой
MyString::~MyString() {
    delete[] strData; // Освобождение памяти, занятой строкой
    countLiveObj--; // Уменьшение счетчика живых объектов
}

// Метод для копирования содержимого одной строки в другую
void MyString::MyStrcpy(MyString& obj) {
    if (strData == nullptr) return; // Если текущая строка пуста, ничего не делать
    delete[] obj.strData; // Освобождение памяти, занятой строкой в объекте назначения

    obj.strLength = strLength; // Копирование длины текущей строки
    obj.strData = new char[strLength + 1]; // Выделение памяти для новой строки

    for (int i = 0; i < strLength; i++) {
        obj.strData[i] = strData[i]; // Копирование символов из текущей строки
    }

    obj.strData[strLength] = '\0'; // Установка символа конца строки
}

// Метод для поиска подстроки в текущей строке
bool MyString::MyStrStr(const char* substr) {
    if (strData == nullptr || substr == nullptr) return false; // Проверка на нулевые указатели
    // Алгоритм поиска подстроки
}
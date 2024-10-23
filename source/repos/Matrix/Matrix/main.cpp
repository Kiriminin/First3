#include<iostream>
#include "Matrix.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем объект матрицы размером 2x2 с элементами типа Point
    Matrix<Point> mat1(2, 2);

    // Заполняем матрицу случайными значениями (так как метод Input генерирует случайные данные)
    mat1.Input();

    // Выводим матрицу на экран
    mat1.Print();

    return 0;
}
#include<iostream>
#include "Matrix.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // ������� ������ ������� �������� 2x2 � ���������� ���� Point
    Matrix<Point> mat1(2, 2);

    // ��������� ������� ���������� ���������� (��� ��� ����� Input ���������� ��������� ������)
    mat1.Input();

    // ������� ������� �� �����
    mat1.Print();

    return 0;
}
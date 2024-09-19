#include "Point3D.h"
#include<iostream>
using namespace std;

int Point3D::objectCount = 0;

// ����������� �� ���������
Point3D::Point3D() : x(0), y(0), z(0) {
    objectCount++;
}

// ����������������� �����������
Point3D::Point3D(int x, int y, int z) : x(x), y(y), z(z) {
    objectCount++;
}

// ����������
Point3D::~Point3D() {
    objectCount--;
}

// ����� ��� ������������� ���������
void Point3D::Init(int x, int y, int z) {

}

// ����� ��� ����������� ���������
void Point3D::Show() const {
    cout << x << "\t" << y << "\t" << z << endl;
}

// ����� ��� ��������� ����� ���� ��������
Point3D Point3D::Sum(Point3D& other) {
    Point3D result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}

// ����� ��� ��������� ���� ��������
Point3D Point3D::Mult(Point3D& other) {
    Point3D result;
    result.x = x * other.x;
    result.y = y * other.y;
    result.z = z * other.z;
    return result;
}

// ����� ��� ���������� ���������
Point3D& Point3D::Summ(int x, int y, int z) {
    x += x;
    y += y;
    z += z;
    return *this;
}

// ����� ��� ���������� ���������
Point3D& Point3D::Minim(int x, int y, int z) {
    x -= x;
    y -= y;
    z -= z;
    return *this;
}

// ����� ��� ��������� ���������
Point3D& Point3D::Multiply(int x, int y, int z) {
    x *= x;
    y *= y;
    z *= z;
    return *this;
}

// ����� ��� ������� ���������
Point3D& Point3D::Divide(int x, int y, int z) {
    if (x == 0 || y == 0 || z == 0) return *this;
    x /= x;
    y /= y;
    z /= z;
    return *this;
}

// ����������� ����� ��� ��������� ���������� ��������
void Point3D::GetObjectCount() {
    cout << "Current number of Point3D objects: " << objectCount << endl;
}
#include <iostream>

using namespace std;

// �����, �������������� ����� � ������������ x � y
class Point {
private:
    int x, y; // ���������� �����

public:
    // ����������� �� ���������, �������������� x � y ���������� 0
    Point() : x(0), y(0) {}
    // ����������� � ����������� ��� ������������� ��������� x � y
    Point(int _x, int _y) : x(_x), y(_y) {}
    // ����������� � ����� ����������, ������� ����������� ���������� �������� x � y
    Point(int value) : x(value), y(value) {}

    // ����� ��� ��������� �������� x
    int getX() const {
        return x;
    }

    // ����� ��� ��������� �������� y
    int getY() const {
        return y;
    }

    // ����� ��� ��������� �������� x
    void setX(int _x) {
        x = _x;
    }

    // ����� ��� ��������� �������� y
    void setY(int _y) {
        y = _y;
    }

    // ���������� ��������� + ��� �������� ���� �����
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // ���������� ��������� - ��� ��������� ����� ����� �� ������
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    // ���������� ��������� * ��� ��������� ��������� �� ������
    Point operator*(int value) const {
        return Point(x * value, y * value);
    }

    // ���������� ��������� / ��� ������� ��������� �� ������
    Point operator/(int value) const {
        if (value == 0) {
            cout << "������: ������� �� ����" << endl;
            return *this;
        }
        return Point(x / value, y / value);
    }

    // ���������� ��������� >> ��� ����� ��������� ����� ����� �������
    friend istream& operator>>(istream& in, Point& p) {
        cout << "������� ���������� (x � y) ����� ������: ";
        in >> p.x >> p.y;
        return in;
    }

    // ���������� ��������� << ��� ������ ��������� �����
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

// ��������� ����� ��� ������ � ���������� ���������
template <typename T>
class Matrix {
    T** ptr; // ��������� �� ������ ��������� �������
    int str; // ���������� �����
    int st;  // ���������� ��������

public:
    // ������������ � �����������
    Matrix();
    Matrix(int _str, int _st);
    Matrix(const Matrix<T>& arr);
    ~Matrix();

    // �������� ��� ���������
    Matrix<T> SumMatrix(const Matrix<T>& arr2);
    Matrix<T> MultiMatrix(const Matrix<T>& arr2);

    // ������ ��� ����� � ������ �������
    void Input();
    void InputFromKeyboard();
    void Print() const;

    // ���������� ����������
    Matrix<T> operator+(const Matrix<T>& arr2);
    Matrix<T> operator-(const Matrix<T>& arr2);
    Matrix<T> operator*(const Matrix<T>& arr2);
    Matrix<T> operator/(const T& value);
    
    // ���������� ��������� ������������
    Matrix<T>& operator=(const Matrix<T>& arr);
};

// ����������� �� ���������, �������������� ������ �������
template <typename T>
Matrix<T>::Matrix() : ptr(nullptr), str(0), st(0) {}

// ����������� � ����������� ��� ������������� ������� �������� _str �� _st
template <typename T>
Matrix<T>::Matrix(int _str, int _st) : str(_str), st(_st) 
{
    // ��������� ������ ��� ������
    ptr = new T * [str]; 
    for (int i = 0; i < str; i++) 
    {
        // ��������� ������ ��� ������� � ������������� ������
        ptr[i] = new T[st]{ 0 }; 
    }
}

// ����������� �����������, ��������� ����� ������ �������
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& arr) : str(arr.str), st(arr.st) {
    ptr = new T * [str];
    for (int i = 0; i < str; i++) 
    {
        ptr[i] = new T[st];
        for (int j = 0; j < st; j++) 
        {
            // �������� ��������
            ptr[i][j] = arr.ptr[i][j];
        }
    }
}

// ����������, ������������� ������, ���������� ��� �������
template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < str; i++) 
    {
        // �������� �����
        delete[] ptr[i]; 
    }
    // �������� ������� ���������� �� ������
    delete[] ptr;
    cout << "����������\n";
}

// ���������� ��������� ������������
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& arr) {
    if (this == &arr) 
    {
        // ������ �� ����������������
        return *this;
    }
    // ������� ������ ������
    for (int i = 0; i < str; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;

    // �������� ����� ������
    str = arr.str;
    st = arr.st;
    ptr = new T * [str];
    for (int i = 0; i < str; i++) 
    {
        ptr[i] = new T[st];
        for (int j = 0; j < st; j++) 
        {
            ptr[i][j] = arr.ptr[i][j];
        }
    }

    return *this;
}
// ����� ��� �������� ���� ������
template <typename T>
Matrix<T> Matrix<T>::SumMatrix(const Matrix<T>& arr2) {
    if (str != arr2.str || st != arr2.st) {
        cout << "������� �� ���������" << endl;
        return Matrix<T>(); // ���������� ������ �������
    }

    Matrix<T> result(str, st);
    for (int i = 0; i < str; i++) 
    {
        for (int j = 0; j < st; j++) 
        {
            // ���������� ��������
            result.ptr[i][j] = ptr[i][j] + arr2.ptr[i][j];
        }
    }

    return result;
}

// ����� ��� ��������� ������
template <typename T>
Matrix<T> Matrix<T>::MultiMatrix(const Matrix<T>&arr2) {
    if (st != arr2.str) {
        cout << "���������� ����������� ������� � ������ ���������" << endl;
        return Matrix<T>();  // ���������� ������ �������
    }

    Matrix<T> result(str, arr2.st);
    for (int i = 0; i < str; i++) 
    {
        for (int j = 0; j < arr2.st; j++) 
        {
            result.ptr[i][j] = 0;
            for (int k = 0; k < st; k++) 
            {
                // �������� � ���������
                result.ptr[i][j] += ptr[i][k] * arr2.ptr[k][j];
            }
        }
    }

    return result;
}

// ����� ��� ����� ������� � ����������
template <typename T>
void Matrix<T>::InputFromKeyboard() {
    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            cin >> ptr[i][j];
        }
    }
}

// ����� ��� ���������� ������� ���������� �������
template <typename T>
void Matrix<T>::Input() {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            ptr[i][j] = rand() % 100;  // ��������� ���������� �������
        }
    }
}

// ����� ��� ������ ������� �� �����
template <typename T>
void Matrix<T>::Print() const {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            cout << ptr[i][j] << "\t"; // ������� �������� ����� ������
        }
        cout << endl;
    }
}

// ���������� ��������� + ��� �������� ������
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& arr2) {
    return SumMatrix(arr2);
}

// ���������� ��������� - ��� ��������� ������
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& arr2) {
    if (str != arr2.str || st != arr2.st) {
        cout << "������� �� ���������" << endl;
        return Matrix2D<T>(); // ���������� ������ �������
    }

    Matrix2D<T> rez(str, st);
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            rez.ptr[i][j] = ptr[i][j] - arr2.ptr[i][j]; // �������� ��������
        }
    }

    return rez;
}

// ���������� ��������� * ��� ��������� ������
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& arr2) {
    return MultiMatrix(arr2);
}

// ���������� ��������� / ��� ������� ������� �� ������
template <typename T>
Matrix<T> Matrix<T>::operator/(const T& value) {
    if (value == 0) {
        cout << "������: ������� �� ����" << endl;
        return Matrix2D<T>(); // ���������� ������ �������
    }

    Matrix<T> result(str, st);
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            result.ptr[i][j] = ptr[i][j] / value; // ����� �������� �� ������
        }
    }

    return result;
}

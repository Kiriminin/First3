#include <iostream>

using namespace std;

// Класс, представляющий точку с координатами x и y
class Point {
private:
    int x, y; // Координаты точки

public:
    // Конструктор по умолчанию, инициализирует x и y значениями 0
    Point() : x(0), y(0) {}
    // Конструктор с параметрами для инициализации координат x и y
    Point(int _x, int _y) : x(_x), y(_y) {}
    // Конструктор с одним параметром, который присваивает одинаковое значение x и y
    Point(int value) : x(value), y(value) {}

    // Метод для получения значения x
    int getX() const {
        return x;
    }

    // Метод для получения значения y
    int getY() const {
        return y;
    }

    // Метод для установки значения x
    void setX(int _x) {
        x = _x;
    }

    // Метод для установки значения y
    void setY(int _y) {
        y = _y;
    }

    // Перегрузка оператора + для сложения двух точек
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Перегрузка оператора - для вычитания одной точки из другой
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    // Перегрузка оператора * для умножения координат на скаляр
    Point operator*(int value) const {
        return Point(x * value, y * value);
    }

    // Перегрузка оператора / для деления координат на скаляр
    Point operator/(int value) const {
        if (value == 0) {
            cout << "Ошибка: деление на ноль" << endl;
            return *this;
        }
        return Point(x / value, y / value);
    }

    // Перегрузка оператора >> для ввода координат точки через консоль
    friend istream& operator>>(istream& in, Point& p) {
        cout << "Введите координаты (x и y) через пробел: ";
        in >> p.x >> p.y;
        return in;
    }

    // Перегрузка оператора << для вывода координат точки
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

// Шаблонный класс для работы с двумерными матрицами
template <typename T>
class Matrix {
    T** ptr; // Указатель на массив элементов матрицы
    int str; // Количество строк
    int st;  // Количество столбцов

public:
    // Конструкторы и деструкторы
    Matrix();
    Matrix(int _str, int _st);
    Matrix(const Matrix<T>& arr);
    ~Matrix();

    // Операции над матрицами
    Matrix<T> SumMatrix(const Matrix<T>& arr2);
    Matrix<T> MultiMatrix(const Matrix<T>& arr2);

    // Методы для ввода и вывода матрицы
    void Input();
    void InputFromKeyboard();
    void Print() const;

    // Перегрузка операторов
    Matrix<T> operator+(const Matrix<T>& arr2);
    Matrix<T> operator-(const Matrix<T>& arr2);
    Matrix<T> operator*(const Matrix<T>& arr2);
    Matrix<T> operator/(const T& value);
    
    // Перегрузка оператора присваивания
    Matrix<T>& operator=(const Matrix<T>& arr);
};

// Конструктор по умолчанию, инициализирует пустую матрицу
template <typename T>
Matrix<T>::Matrix() : ptr(nullptr), str(0), st(0) {}

// Конструктор с параметрами для инициализации матрицы размером _str на _st
template <typename T>
Matrix<T>::Matrix(int _str, int _st) : str(_str), st(_st) 
{
    // Выделение памяти под строки
    ptr = new T * [str]; 
    for (int i = 0; i < str; i++) 
    {
        // Выделение памяти под столбцы и инициализация нулями
        ptr[i] = new T[st]{ 0 }; 
    }
}

// Конструктор копирования, создающий копию другой матрицы
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& arr) : str(arr.str), st(arr.st) {
    ptr = new T * [str];
    for (int i = 0; i < str; i++) 
    {
        ptr[i] = new T[st];
        for (int j = 0; j < st; j++) 
        {
            // Копируем элементы
            ptr[i][j] = arr.ptr[i][j];
        }
    }
}

// Деструктор, освобождающий память, выделенную под матрицу
template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < str; i++) 
    {
        // Удаление строк
        delete[] ptr[i]; 
    }
    // Удаление массива указателей на строки
    delete[] ptr;
    cout << "Деструктор\n";
}

// Перегрузка оператора присваивания
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& arr) {
    if (this == &arr) 
    {
        // Защита от самоприсваивания
        return *this;
    }
    // Удаляем старые данные
    for (int i = 0; i < str; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;

    // Копируем новые данные
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
// Метод для сложения двух матриц
template <typename T>
Matrix<T> Matrix<T>::SumMatrix(const Matrix<T>& arr2) {
    if (str != arr2.str || st != arr2.st) {
        cout << "Размеры не совпадают" << endl;
        return Matrix<T>(); // Возвращаем пустую матрицу
    }

    Matrix<T> result(str, st);
    for (int i = 0; i < str; i++) 
    {
        for (int j = 0; j < st; j++) 
        {
            // Складываем элементы
            result.ptr[i][j] = ptr[i][j] + arr2.ptr[i][j];
        }
    }

    return result;
}

// Метод для умножения матриц
template <typename T>
Matrix<T> Matrix<T>::MultiMatrix(const Matrix<T>&arr2) {
    if (st != arr2.str) {
        cout << "Невозможно перемножить матрицы с такими размерами" << endl;
        return Matrix<T>();  // Возвращаем пустую матрицу
    }

    Matrix<T> result(str, arr2.st);
    for (int i = 0; i < str; i++) 
    {
        for (int j = 0; j < arr2.st; j++) 
        {
            result.ptr[i][j] = 0;
            for (int k = 0; k < st; k++) 
            {
                // Умножаем и суммируем
                result.ptr[i][j] += ptr[i][k] * arr2.ptr[k][j];
            }
        }
    }

    return result;
}

// Метод для ввода матрицы с клавиатуры
template <typename T>
void Matrix<T>::InputFromKeyboard() {
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            cin >> ptr[i][j];
        }
    }
}

// Метод для заполнения матрицы случайными числами
template <typename T>
void Matrix<T>::Input() {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            ptr[i][j] = rand() % 100;  // Заполняем случайными числами
        }
    }
}

// Метод для вывода матрицы на экран
template <typename T>
void Matrix<T>::Print() const {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            cout << ptr[i][j] << "\t"; // Выводим элементы через табуля
        }
        cout << endl;
    }
}

// Перегрузка оператора + для сложения матриц
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& arr2) {
    return SumMatrix(arr2);
}

// Перегрузка оператора - для вычитания матриц
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& arr2) {
    if (str != arr2.str || st != arr2.st) {
        cout << "Размеры не совпадают" << endl;
        return Matrix2D<T>(); // Возвращаем пустую матрицу
    }

    Matrix2D<T> rez(str, st);
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            rez.ptr[i][j] = ptr[i][j] - arr2.ptr[i][j]; // Вычитаем элементы
        }
    }

    return rez;
}

// Перегрузка оператора * для умножения матриц
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& arr2) {
    return MultiMatrix(arr2);
}

// Перегрузка оператора / для деления матрицы на скаляр
template <typename T>
Matrix<T> Matrix<T>::operator/(const T& value) {
    if (value == 0) {
        cout << "Ошибка: деление на ноль" << endl;
        return Matrix2D<T>(); // Возвращаем пустую матрицу
    }

    Matrix<T> result(str, st);
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < st; j++) {
            result.ptr[i][j] = ptr[i][j] / value; // Делим элементы на скаляр
        }
    }

    return result;
}

#include<iostream>
using namespace std;

class Point // создание нового типа!!
{
private:
	int x;
	int y;
public:
	Point() {}
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	void Print() // метод класса
	{
		cout << "X: " << x << "\tY: " << y << endl;
	}
	void Input(int a, int b) // метод класса
	{
		x = a;
		y = b;
	}

	Point Sum(Point& b)
	{
		Point sum(x + b.x, y + b.y);
		return sum;
	}
	int GetX()const
	{
		return x;
	}
	int GetY()const
	{
		return y;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}

	//Point operator+ (Point& b) // obj+obj
	//{
	//	Point sum(x + b.x, y + b.y);
	//	return sum;
	//}
	//Point operator+ (int b) // obj+int
	//{
	//	Point sum(x + b, y + b);
	//	return sum;
	//}

	//Point& operator++() // ++a
	//{
	//	x += 10;
	//	y += 10;
	//	return *this;
	//}
	//Point operator++(int) // a++
	//{
	//	Point temp(x, y);
	//	x += 10;
	//	y += 10;
	//	return temp;
	//}
	//Point& operator--() // --a
	//{
	//	x -= 10;
	//	y -= 10;
	//	return *this;
	//}
	//Point operator--(int) // a--
	//{
	//	Point temp(x, y);
	//	x -= 10;
	//	y -= 10;
	//	return temp;
	//}

	/////---- сокращенные формы
	//Point& operator += (int a) {
	//	x += a;
	//	y += a;
	//	return *this;
	//}
	//Point& operator-=(int a) {
	//	x -= a;     y -= a;
	//	return *this;
	//}
	//Point& operator*=(int a) {
	//	x *= a;
	//	y *= a;     return *this;
	//}
	//Point& operator/=(int a) {
	//	x /= a;     y /= a;
	//	return *this;
	//}
};

Point operator+(int a, Point& b) 
{ // int+ Point
	Point rez;
	rez.SetX(a + b.GetX());
	rez.SetY(a + b.GetY());
	return rez;
}
Point operator+(Point& b, int a) 
{// Point + int
	Point rez(b.GetX() + a, b.GetY() + a);
	return rez;
}
Point operator++(Point& obj) 
{// ++a
	obj.SetX(obj.GetX() + 10);
	obj.SetY(obj.GetY() + 10);
	return obj;
}
Point operator++(Point& obj, int) 
{// a++
	Point temp(obj.GetX(), obj.GetY());

	obj.SetX(obj.GetX() + 10);
	obj.SetY(obj.GetY() + 10);

	return temp;
}
Point operator-(const Point& a, const Point& b) 
{// POINT - POINT
	Point rez;
	rez.SetX(a.GetX() - b.GetX());
	rez.SetY(a.GetY() - b.GetY());
	return rez;
}
Point operator-(const Point& a, int b) // Point - INT
{
	Point rez;
	rez.SetX(a.GetX() - b);
	rez.SetY(a.GetY() - b);
	return rez;
}
Point operator*(const Point& a, int b) // Point * INT
{
	Point rez;
	rez.SetX(a.GetX() * b);
	rez.SetY(a.GetY() * b);
	return rez;
}
Point operator*(const Point& a, int b) // Point * INT
{
	Point rez;
	rez.SetX(a.GetX() * b);
	rez.SetY(a.GetY() * b);
	return rez;
}
Point operator--(Point& obj) {
	obj.SetX(obj.GetX() - 1);
	obj.SetY(obj.GetY() - 1);
	return obj;
}
Point operator--(Point& obj, int) 
{
	// a--
	Point temp = obj;
	obj.SetX(obj.GetX() - 1);
	obj.SetY(obj.GetY() - 1);
	return temp;
}
Point operator+=(Point& obj, int a) {
	obj.SetX(obj.GetX() + a);
	obj.SetY(obj.GetY() + a);
	return obj;
}
Point& operator-=(Point& obj, int a) {
	obj.SetX(obj.GetX() - a);
	obj.SetY(obj.GetY() - a);
	return obj;
}
Point& operator*=(Point& obj, int a) {
	obj.SetX(obj.GetX() * a);
	obj.SetY(obj.GetY() * a);
	return obj;
}



int main()
{
	Point a(10, 20);
	Point b(5, 15);

	Point result = a - b;     // вычитание двух объектов
	result = a - 10;          // вычитание числа
	result = a * 10;          // умножение на число
	result = --a;             // префиксный декремент
	result = a--;             // постфиксный декремент
	result += 10;
	result -= 10;
	result *= 10;

}
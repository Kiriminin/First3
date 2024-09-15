#include<iostream>
using namespace std;

class Point3D
{
    int x, y, z;
public:
    Point3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Point3D(int x, int y, int z)
    {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }

    void Init(int x, int y, int z)
    {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }

    void Show()
    {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    Point3D Sum(Point3D& b)
    {
        Point3D result;
        result.x = x + b.x;
        result.y = y + b.y;
        result.z = z + b.z;
        return result;
    }

    Point3D Mult(Point3D& b)
    {
        Point3D result;
        result.x = x * b.x;
        result.y = y * b.y;
        result.z = z * b.z;
        return result;
    }

    Point3D& Sum(int a, int b, int c)
    {
        x += a;
        y += b;
        z += c;
        return *this;
    }

};

int main()
{
    Point3D p1(1, 2, 3);
    p1.Show();

    Point3D p2(4, 5, 6);
    p2.Show();

    Point3D result = p1.Sum(p2);
    result.Show();

    p1.Sum(10, 20, 30);
    p1.Show();

    return 0;
}
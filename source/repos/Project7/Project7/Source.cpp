#include <iostream>
#include "Point3D.h"

using namespace std;

int main()
{
    Point3D p1(1, 2, 3);
    Point3D::GetObjectCount();

    Point3D p2(4, 5, 6);
    Point3D::GetObjectCount();

    Point3D p3 = p1.Sum(p2);
    p3.Show();
    Point3D::GetObjectCount();

    return 0;
}
#pragma once
class Point3D {
    int x, y, z;
    static int objectCount;
public:


    Point3D();
    Point3D(int x, int y, int z);
    ~Point3D();

    void Init(int x, int y, int z);
    void Show() const;

    Point3D Sum(Point3D& b);
    Point3D Mult(Point3D& b);

    Point3D& Summ(int x, int y, int z);
    Point3D& Minim(int x, int y, int z);
    Point3D& Multiply(int x, int y, int z);
    Point3D& Divide(int x, int y, int z);

    static void GetObjectCount();
};

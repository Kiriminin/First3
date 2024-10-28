#pragma once
#include <iostream>

using namespace std;


class Cpu {
private:
	int price;
	int capacity;
	string name;
public:
	int getPrice();
	int getCapacity();
	string getName();

	void setPrice(int a);
	void setCapacity(int a);
	void setName(string a);

	void Output();
};

class SSD {
private:
	int price;
	int capacity;
	string brand;
public:
	int getPrice();
	int getCapacity();
	string getBrand();

	void setPrice(int p);
	void setCapacity(int c);
	void setBrand(string b);

	void Output();
};

class RAM {
private:
	int price;
	int size;
	string type;
public:
	int getPrice();
	int getSize();
	string getType();

	void setPrice(int p);
	void setSize(int s);
	void setType(string t);

	void Output();
};


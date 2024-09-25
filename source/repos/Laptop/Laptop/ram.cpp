#include <iostream>
#include "Ram.h"
using namespace std;

Ram::Ram(const char* m, double pr)
{
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
	price = pr;
}

const char* Ram::GetModel()
{
	return model;
}

double Ram::GetPrice()
{
	return price;
}

void Ram::SetPrice(double pr)
{
	price = pr;
}

Ram::~Ram()
{
	delete[]model;
}
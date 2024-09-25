#include <iostream>
#include "Ssd.h"
using namespace std;

Ssd::Ssd(const char* m, double pr)
{
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
	price = pr;
}

const char* Ssd::GetModel()
{
	return model;
}

double Ssd::GetPrice()
{
	return price;
}

void Ssd::SetPrice(double pr)
{
	price = pr;
}

Ssd::~Ssd()
{
	delete[]model;
}
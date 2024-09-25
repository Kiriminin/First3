#pragma once
class Ssd
{
	char* model;
	double price;
public:
	Ssd(const char* m, double pr);
	const char* GetModel();
	double GetPrice();
	void SetPrice(double pr);
	~Ssd();
};
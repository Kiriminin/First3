#pragma once
class Ram
{
	char* model;
    double price;
public:

	Ram(const char* m, double pr);

	const char* GetModel();

	double GetPrice();

	void SetPrice(double pr);

	~Ram();
};

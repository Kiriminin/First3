#pragma once
class Cpu
{
    char* model;
	
	double price;

public:
	// Конструктор класса, принимающий модель и цену процессора
	Cpu(const char* m, double pr);
	// Метод для получения модели процессора
	const char* GetModel();
	
	double GetPrice();
	
	void SetPrice(double pr);
	// Деструктор класса для освобождения ресурсов
	~Cpu();
};

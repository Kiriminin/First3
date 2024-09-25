#pragma once
#include "Cpu.h"
#include "Ssd.h"
#include "Gpu.h"
#include "Ram.h"

class laptop
{
	char* name; // Указатель на строку, хранящую название ноутбука
	double price; // Цена ноутбука без учёта комплектующих
	Cpu cpu; // Объект другого класса без конструктора по умолчанию!
	Ram* ram; // Указатель на объект класса Ram
	Gpu* gpu;
	Ssd* ssd;
	/* добавляем остальные компоненты для ноутбука - указатели на объекты, для которых память выдел. в конструкторе класса Laptop
	*/
public:
	// Конструктор, который принимает название ноутбука, цену, параметры процессора и указатели на компоненты
	laptop(const char* n, double pr, const char* mcpu, double prcpu, Ram* r, Gpu* g, Ssd* s);
	double GetPrice();
	void Output();
	~laptop();
};


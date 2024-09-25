#include "laptop.h"
#include<iostream>
using namespace std;

// Конструктор класса laptop
// Инициализирует процессор (cpu) через список инициализации, а также получает указатели на оперативную память (ram), видеокарту (gpu) и SSD (ssd)
laptop::laptop(const char* n, double pr, const char* mcpu, double prcpu, Ram* r, Gpu* g, Ssd* s) 
	: cpu(mcpu, prcpu), ram(r), gpu(g), ssd(s)
{
	// Выделение памяти для строки name и копирование названия ноутбука
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	// Сохранение цены ноутбука
	price = pr;

	//ram = new Ram("Samsung", 200);
}
// Метод GetPrice
// Возвращает общую цену ноутбука, включая цену процессора, видеокарты, оперативной памяти и SSD
double laptop::GetPrice()
{
	// Возвращаем общую стоимость ноутбука
	return price + cpu.GetPrice() + gpu->GetPrice() + ram->GetPrice() + ssd->GetPrice();
}

void laptop::Output()
{
	// Выводим все характеристики ноутбука и его компонентов
	cout << "Model: " << name << endl
		 << "Cpu: " << cpu.GetModel() << endl
		 << "Ram: " << ram->GetModel() << " Price: " << ram->GetPrice() << endl
	     << "Gpu: " << gpu->GetModel() << " Price: " << gpu->GetPrice() << endl
	     << "Ssd: " << ssd->GetModel() << " Price: " << ssd->GetPrice() << endl
		 << "Laptop price = " << GetPrice() << " $\n";
}
// Деструктор класса laptop
// Освобождает динамически выделенную память для строки name, а также удаляет объекты ram, gpu, ssd
laptop::~laptop()
{
	// Освобождаем память, выделенную для строки name
	delete[] name;
	// Удаляем объекты ram, gpu и ssd, чтобы предотвратить утечку памяти
	delete ram;
	delete gpu;
	delete ssd;
}

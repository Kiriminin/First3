#include "Cpu.h"
#include<iostream>
using namespace std;

Cpu::Cpu(const char* m, double pr)
{
	// Выделение памяти для строки model и копирование в нее переданного значения m
	model = new char[strlen(m) + 1]; // +1 для символа окончания строки '\0'
	strcpy_s(model, strlen(m) + 1, m); // Копирование строки m в model
	price = pr; // Инициализация цены процессора
}
// Метод для получения модели процессора
const char* Cpu::GetModel()
{
	return model; // Возвращение строки с моделью процессора
}

double Cpu::GetPrice()
{
	return price;
}
// Метод для установки новой цены процессора
void Cpu::SetPrice(double pr)
{
	price = pr; // Установка новой цены
}
// Деструктор класса Cpu
Cpu::~Cpu()
{ 
	delete[]model; // Освобождение памяти, выделенной под строку model
}
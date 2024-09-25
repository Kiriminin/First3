#include <iostream>
#include "Gpu.h"
using namespace std;

Gpu::Gpu(const char* m, double pr)
{
	// Выделяем память для строки model, которая будет хранить название модели GPU
	// Используем strlen(m) для определения длины строки и добавляем 1 для нуль-терминатора
	model = new char[strlen(m) + 1];
	// Копируем строку m в выделенную память с помощью strcpy_s
	// Используем strlen(m) + 1 для правильного копирования всей строки вместе с нуль-терминатором
	strcpy_s(model, strlen(m) + 1, m);
	// Присваиваем переданное значение цены pr переменной price
	price = pr;
}
// Метод для получения модели GPU
// Возвращает указатель на строку с названием модели GPU
const char* Gpu::GetModel()
{
	return model;
}

double Gpu::GetPrice()
{
	return price;
}

void Gpu::SetPrice(double pr)
{
	price = pr;
}
// Деструктор класса Gpu
// Удаляет выделенную динамическую память для строки model
Gpu::~Gpu()
{
	// Удаляем массив символов, выделенный под строку model
	delete[]model;
}
#include<iostream>
#include"laptop.h"
#include "cpu.h"
using namespace std;

int main()
{
	// Создаем объект оперативной памяти Ram
	// Указываем название модели ("Vengeance LPX") и цену (205)
	Ram* ram1 = new Ram("Vengeance LPX", 205);
	Gpu* gpu1 = new Gpu("Asus GEFORCE GTX1060", 650);
	Ssd* ssd1 = new Ssd("Corsair ", 186);
	// Создаем объект ноутбука Laptop
	// Передаем название ноутбука ("HP"), цену (300.9), модель процессора ("AMD Ryzen 7000 ser,") и его цену (500.9)
	// Также передаем указатели на оперативную память, видеокарту и SSD
	laptop obj1("HP", 300.9, "AMD Ryzen 7000 ser,", 500.9, ram1, gpu1, ssd1);
	// Выводим информацию о первом объекте ноутбука
	obj1.Output();
	cout << endl;

	Ram* ram2 = new Ram("Kingston", 630);
	Gpu* gpu2 = new Gpu("AMD Radeon 680", 850);
	Ssd* ssd2 = new Ssd("Lenovo 320", 280);
	laptop obj2("Acer", 1002, "GeForce GTX3060", 400, ram2, gpu2, ssd2);
	obj2.Output();
	cout << endl;

	Ram* ram3 = new Ram("Trident Z Royal", 540);
	Gpu* gpu3 = new Gpu("AMD RADEON 355", 205);
	Ssd* ssd3 = new Ssd("G.Skill", 630);
	laptop obj3("Asus", 2080, "GEFORCE GTX 1050 ti", 305, ram3, gpu3, ssd3);
	obj3.Output();
	cout << endl;
	
	return 0;
}
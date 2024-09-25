#include "laptop.h"
#include<iostream>
using namespace std;

// ����������� ������ laptop
// �������������� ��������� (cpu) ����� ������ �������������, � ����� �������� ��������� �� ����������� ������ (ram), ���������� (gpu) � SSD (ssd)
laptop::laptop(const char* n, double pr, const char* mcpu, double prcpu, Ram* r, Gpu* g, Ssd* s) 
	: cpu(mcpu, prcpu), ram(r), gpu(g), ssd(s)
{
	// ��������� ������ ��� ������ name � ����������� �������� ��������
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	// ���������� ���� ��������
	price = pr;

	//ram = new Ram("Samsung", 200);
}
// ����� GetPrice
// ���������� ����� ���� ��������, ������� ���� ����������, ����������, ����������� ������ � SSD
double laptop::GetPrice()
{
	// ���������� ����� ��������� ��������
	return price + cpu.GetPrice() + gpu->GetPrice() + ram->GetPrice() + ssd->GetPrice();
}

void laptop::Output()
{
	// ������� ��� �������������� �������� � ��� �����������
	cout << "Model: " << name << endl
		 << "Cpu: " << cpu.GetModel() << endl
		 << "Ram: " << ram->GetModel() << " Price: " << ram->GetPrice() << endl
	     << "Gpu: " << gpu->GetModel() << " Price: " << gpu->GetPrice() << endl
	     << "Ssd: " << ssd->GetModel() << " Price: " << ssd->GetPrice() << endl
		 << "Laptop price = " << GetPrice() << " $\n";
}
// ���������� ������ laptop
// ����������� ����������� ���������� ������ ��� ������ name, � ����� ������� ������� ram, gpu, ssd
laptop::~laptop()
{
	// ����������� ������, ���������� ��� ������ name
	delete[] name;
	// ������� ������� ram, gpu � ssd, ����� ������������� ������ ������
	delete ram;
	delete gpu;
	delete ssd;
}

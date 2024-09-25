#pragma once
#include "Cpu.h"
#include "Ssd.h"
#include "Gpu.h"
#include "Ram.h"

class laptop
{
	char* name; // ��������� �� ������, �������� �������� ��������
	double price; // ���� �������� ��� ����� �������������
	Cpu cpu; // ������ ������� ������ ��� ������������ �� ���������!
	Ram* ram; // ��������� �� ������ ������ Ram
	Gpu* gpu;
	Ssd* ssd;
	/* ��������� ��������� ���������� ��� �������� - ��������� �� �������, ��� ������� ������ �����. � ������������ ������ Laptop
	*/
public:
	// �����������, ������� ��������� �������� ��������, ����, ��������� ���������� � ��������� �� ����������
	laptop(const char* n, double pr, const char* mcpu, double prcpu, Ram* r, Gpu* g, Ssd* s);
	double GetPrice();
	void Output();
	~laptop();
};


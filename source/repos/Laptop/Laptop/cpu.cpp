#include "Cpu.h"
#include<iostream>
using namespace std;

Cpu::Cpu(const char* m, double pr)
{
	// ��������� ������ ��� ������ model � ����������� � ��� ����������� �������� m
	model = new char[strlen(m) + 1]; // +1 ��� ������� ��������� ������ '\0'
	strcpy_s(model, strlen(m) + 1, m); // ����������� ������ m � model
	price = pr; // ������������� ���� ����������
}
// ����� ��� ��������� ������ ����������
const char* Cpu::GetModel()
{
	return model; // ����������� ������ � ������� ����������
}

double Cpu::GetPrice()
{
	return price;
}
// ����� ��� ��������� ����� ���� ����������
void Cpu::SetPrice(double pr)
{
	price = pr; // ��������� ����� ����
}
// ���������� ������ Cpu
Cpu::~Cpu()
{ 
	delete[]model; // ������������ ������, ���������� ��� ������ model
}
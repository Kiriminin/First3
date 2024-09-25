#include <iostream>
#include "Gpu.h"
using namespace std;

Gpu::Gpu(const char* m, double pr)
{
	// �������� ������ ��� ������ model, ������� ����� ������� �������� ������ GPU
	// ���������� strlen(m) ��� ����������� ����� ������ � ��������� 1 ��� ����-�����������
	model = new char[strlen(m) + 1];
	// �������� ������ m � ���������� ������ � ������� strcpy_s
	// ���������� strlen(m) + 1 ��� ����������� ����������� ���� ������ ������ � ����-������������
	strcpy_s(model, strlen(m) + 1, m);
	// ����������� ���������� �������� ���� pr ���������� price
	price = pr;
}
// ����� ��� ��������� ������ GPU
// ���������� ��������� �� ������ � ��������� ������ GPU
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
// ���������� ������ Gpu
// ������� ���������� ������������ ������ ��� ������ model
Gpu::~Gpu()
{
	// ������� ������ ��������, ���������� ��� ������ model
	delete[]model;
}
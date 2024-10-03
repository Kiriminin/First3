#include "Vector.h"
#include<iostream>
#include<Windows.h>
using namespace std;

MyVector::MyVector()
{
	arr = nullptr;
	size = 0;
}
MyVector::MyVector(int s)
{
	size = s;
	arr = new int[size] {0};
}
MyVector::~MyVector() {
	delete[]arr;
	size = 0;
}
void MyVector::InputRand() {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 41 - 20;
	}
}
void MyVector::Print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n---------------------------------------------------\n";
}

void MyVector::PushBack(int a) {
	int* temp = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = a;

	delete[] arr;

	arr = temp;
	size++;

}

int MyVector::PopBack() {
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = arr[i];
	}
	int el = arr[size - 1];

	delete[] arr;
	arr = temp;
	size--;

	return el;
}

void MyVector::PushForward(int a) {
	int* temp = new int[size + 1];
	temp[0] = a;

	for (int i = 0; i < size; i++) {
		temp[i + 1] = arr[i];
	}

	delete[] arr;
	arr = temp;
	size++;
}

int MyVector::PopForward() {
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = arr[i];
	}
	int el = arr[0];

	delete[] arr;
	arr = temp;
	size--;

	return el;
}

void MyVector::PushIndex(int a, int index) {
	int* temp = new int[size + 1];

	for (int i = 0; i < index; i++) {
		temp[i] = arr[i];
	}

	temp[index] = a;

	for (int i = index; i < size; i++) {
		temp[i + 1] = arr[i];
	}

	delete[] arr;

	arr = temp;
	size++;
}

int MyVector::RemoveAtIndex(int index) {
	int* temp = new int[size - 1];

	for (int i = 0; i < index; i++) {
		temp[i] = arr[i];
	}

	int el = arr[index - 1];

	for (int i = index + 1; i < size; i++) {
		temp[i - 1] = arr[i];
	}

	delete[] arr;

	arr = temp;
	size--;

	return el;
}

void MyVector::AppendArray(int newArr[], int newSize) {
	int* temp = new int[size + newSize];

	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}

	for (int i = 0; i < newSize; i++) {
		temp[size + i] = newArr[i];
	}

	delete[] arr;

	arr = temp;
	size += newSize;
}

int* MyVector::getArray() const {
	return arr;
}
int MyVector::getSize() const {
	return size;
}
void MyVector::setArray(int* newArr, int newSize) {
	if (arr != nullptr)	delete[] arr;
	arr = newArr;
	size = newSize;
}
MyVector MyVector::operator - (int a) {
	MyVector rez(size - a);
	for (int i = 0; i < rez.size; i++) {
		rez.arr[i] = this->arr[i];
	}
	return rez;
}

MyVector MyVector::operator + (int a) {
	MyVector rez(size + a);

	for (int i = 0; i < size; i++) {
		rez.arr[i] = this->arr[i];
	}

	for (int i = size; i < rez.size; i++) {
		rez.arr[i] = 0;
	}

	return rez;
}

MyVector MyVector::operator*(int a)
{
	MyVector rez(size);

	for (int i = 0; i < size; i++) 
	{
		rez.arr[i] = this->arr[i] * a;
	}
	return rez;
}

MyVector MyVector::operator+(const MyVector& obj)
{
	int newSize = this->size + obj.size;

	MyVector rez(newSize);

	for (int i = 0; i < this->size; i++) 
	{
		rez.arr[i] = this->arr[i];
	}

	for (int i = 0; i < obj.size; i++) 
	{
		rez.arr[this->size + i] = obj.arr[i];
	}

	return rez;
}

MyVector& MyVector::operator++() 
{
	PushForward(0);
	return *this;
}

MyVector MyVector::operator++(int) 
{
	MyVector temp = *this;
	PushForward(0);
	return temp;
	return temp;
}

MyVector& MyVector::operator--() 
{

		RemoveAtIndex(0);
		
		return *this;
	}

		MyVector MyVector::operator--(int) 
		{
			MyVector temp = *this;
			RemoveAtIndex(0);
			
			return temp;
		}

		MyVector& MyVector::operator+=(int a) {
			int* temp = new int[size + a];

			for (int i = 0; i < size; i++) 
			{
				temp[i] = arr[i];
			}

			for (int i = size; i < size + a; i++) 
			{
				temp[i] = 0;
			}

			delete[] arr;

			arr = temp;

			size += a;
		

			return *this;
		}

			MyVector& MyVector::operator-=(int a) {
				
				if (size >= a) {
					int* temp = new int[size - a];
					
					for (int i = 0; i < size - a; i++) 
					{
						temp[i] = arr[i];
					}

					delete[] arr;

					arr = temp;
					size -= a;
				}

				
				return *this;

			}

			MyVector& MyVector::operator*=(int a) {
				
				for (int i = 0; i < size; i++) 
				{
					arr[i] *= a;
				}

			
				return *this;
			}

			MyVector& MyVector::operator=(const MyVector & obj) 
			{
				if (this == &obj) return *this;
				
				if (arr != nullptr) delete[] arr;

				size = obj.size;
				arr = new int[size];
				
				for (int i = 0; i < size; i++) {
					arr[i] = obj.arr[i];
				}
				return *this;
			}


			ostream& operator<<(ostream & os, MyVector obj) 
			{
				obj.Print();
				return os;
			}
			istream& operator>>(istream & is, MyVector & obj) 
			{
				cout << "Size: ";
				is >> obj.size;
				
				if (obj.arr != nullptr) delete[] obj.arr;

				obj.arr = new int[obj.size];
				cout << "Elements: ";
				
				for (int i = 0; i < obj.size; i++) 
				{
					is >> obj.arr[i];
				}
				return is;
			}
			MyVector operator-(int a, const MyVector & obj) 
			{
				int newSize = obj.getSize() - a;
				
				if (newSize <= 0) return MyVector();
				int* newArr = new int[newSize];
				
				for (int i = 0; i < newSize; i++) 
				{
					newArr[i] = obj.getArray()[i + a];
				}
				MyVector rez;

				rez.setArray(newArr, newSize);

				return rez;
			}

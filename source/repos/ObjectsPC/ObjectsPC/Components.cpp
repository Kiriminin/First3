#include "Components.h"
#include <iostream>

using namespace std;

// Cpu
int Cpu::getPrice() {
	cout << price << endl;
	return price;
}

int Cpu::getCapacity() {
	cout << capacity << endl;
	return capacity;
}

string Cpu::getName() {
	cout << name << endl;
	return name;
}

void Cpu::setPrice(int a) {
	price = a;
}

void Cpu::setCapacity(int a) {
	capacity = a;
}

void Cpu::setName(string a) {
	name = a;
}

void Cpu::Output() {
	getPrice();
	getCapacity();
	getName();
}

// Ssd
int SSD::getPrice() {
	cout << price << endl;
	return price;
}

int SSD::getCapacity() {
	cout << capacity << endl;
	return capacity;
}

string SSD::getBrand() {
	cout << brand << endl;
	return brand;
}

void SSD::setPrice(int p) {
	price = p;
}

void SSD::setCapacity(int c) {
	capacity = c;
}

void SSD::setBrand(string b) {
	brand = b;
}

void SSD::Output() {
	getPrice();
	getCapacity();
	getBrand();
}

// Ram
int RAM::getPrice() {
	cout << price << endl;
	return price;
}

int RAM::getSize() {
	cout << size << endl;
	return size;
}

string RAM::getType() {
	cout << type << endl;
	return type;
}

void RAM::setPrice(int p) {
	price = p;
}

void RAM::setSize(int s) {
	size = s;
}

void RAM::setType(string t) {
	type = t;
}

void RAM::Output() {
	getPrice();
	getSize();
	getType();
}

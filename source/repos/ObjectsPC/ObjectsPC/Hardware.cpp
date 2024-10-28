#include "Hardware.h"
#include <iostream>

using namespace std;

// Keyboard
int Keyboard::getPrice() {
	cout << price << endl;
	return price;
}

string Keyboard::getLayout() {
	cout << layout << endl;
	return layout;
}

bool Keyboard::getIsMechanical() {
	cout << (isMechanical ? "Mechanical" : "Non-Mechanical") << endl;
	return isMechanical;
}

void Keyboard::setPrice(int p) {
	price = p;
}

void Keyboard::setLayout(string l) {
	layout = l;
}

void Keyboard::setIsMechanical(bool m) {
	isMechanical = m;
}

void Keyboard::Output() {
	getPrice();
	getLayout();
	getIsMechanical();
}

// Mouse
int Mouse::getPrice() {
	cout << price << endl;
	return price;
}

int Mouse::getDPI() {
	cout << dpi << endl;
	return dpi;
}

bool Mouse::getIsWireless() {
	cout << (isWireless ? "Wireless" : "Wired") << endl;
	return isWireless;
}

void Mouse::setPrice(int p) {
	price = p;
}

void Mouse::setDPI(int d) {
	dpi = d;
}

void Mouse::setIsWireless(bool w) {
	isWireless = w;
}

void Mouse::Output() {
	getPrice();
	getDPI();
	getIsWireless();
}

// Headphones
int Headphones::getPrice() {
	cout << price << endl;
	return price;
}

bool Headphones::getIsWireless() {
	cout << (isWireless ? "Wireless" : "Wired") << endl;
	return isWireless;
}

string Headphones::getType() {
	cout << type << endl;
	return type;
}

void Headphones::setPrice(int p) {
	price = p;
}

void Headphones::setIsWireless(bool w) {
	isWireless = w;
}

void Headphones::setType(string t) {
	type = t;
}

void Headphones::Output() {
	getPrice();
	getIsWireless();
	getType();
}

// Monitor
int Monitor::getPrice() {
	cout << price << endl;
	return price;
}

int Monitor::getSize() {
	cout << size << endl;
	return size;
}

string Monitor::getResolution() {
	cout << resolution << endl;
	return resolution;
}

void Monitor::setPrice(int p) {
	price = p;
}

void Monitor::setSize(int s) {
	size = s;
}

void Monitor::setResolution(string r) {
	resolution = r;
}

void Monitor::Output() {
	getPrice();
	getSize();
	getResolution();
}
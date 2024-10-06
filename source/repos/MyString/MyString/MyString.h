#pragma once
class MyString
{
	char* strData; // Указатель на динамически выделяемую строку
	int strLength; // Длина строки
	static int countLiveObj; // Счетчик живых объектов MyString
	static int countCreatedObj; // Счетчик созданных объектов MyString

public:
	MyString(); // Конструктор по умолчанию
	MyString(int size); // Конструктор, принимающий размер строки
	MyString(const char* initStr);  // Конструктор, инициализирующий строку заданным значением
	MyString(const MyString& other);
	MyString(MyString&& obj);
	MyString& operator=(MyString&& obj);
	MyString(initializer_list<char> a);
	~MyString();  // Деструктор

	void MyStrcpy(MyString& obj); // Метод для копирования содержимого строки в другой объект
	bool MyStrStr(const char* substr); // Метод для поиска подстроки в строке
	int MyChr(char c); // Метод для поиска символа в строке (возвращает индекс или -1)
	int MyStrLen(); // Метод для получения длины строки
	void MyStrCat(MyString& b); // Метод для объединения текущей строки с другой строкой
	void MyDelChr(char c); // Метод для удаления указанного символа из строки
	int MyStrCmp(MyString& b); // Метод для сравнения двух строк

	MyString& operator+=(const char* appendStr);

	void Print(); // Метод для вывода строки на экран
	void Input(); // Метод для ввода строки с клавиатуры

	static void GetCountLiveObj(); // Статический метод для получения количества живых (которые существуют в данный момент, они были созданны и ещё не уничтожены) объектов
	static void GetCountCreatedObj(); // Статический метод для получения количества созданных объектов
	
	MyString operator=(const MyString& obj);
	MyString operator[](int index);
	void operator()();
	
	friend ostream& operator<<(ostream& os, MyString obj);
	friend istream& operator>>(istream& is, MyString& obj);
}; 

// Перегруженный оператор вывода
ostream& operator<<(ostream& os, MyString obj);

// Перегруженный оператор ввода
istream& operator>>(istream& is, MyString& obj);
// Перегруженный оператор сложения строки и объекта MyString
MyString operator+(const char* prefixStr, const MyString& myStr);

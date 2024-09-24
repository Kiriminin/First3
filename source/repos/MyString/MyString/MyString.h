#pragma once
class MyString
{
	char* strData; // ��������� �� ����������� ���������� ������
	int strLength; // ����� ������
	static int countLiveObj; // ������� ����� �������� MyString
	static int countCreatedObj; // ������� ��������� �������� MyString

public:
	MyString(); // ����������� �� ���������
	MyString(int size); // �����������, ����������� ������ ������
	MyString(const char* initStr);  // �����������, ���������������� ������ �������� ���������
	MyString(const MyString& other);  // ����������� �����������
	~MyString();  // ����������

	void MyStrcpy(MyString& obj); // ����� ��� ����������� ����������� ������ � ������ ������
	bool MyStrStr(const char* substr); // ����� ��� ������ ��������� � ������
	int MyChr(char c); // ����� ��� ������ ������� � ������ (���������� ������ ��� -1)
	int MyStrLen(); // ����� ��� ��������� ����� ������
	void MyStrCat(MyString& b); // ����� ��� ����������� ������� ������ � ������ �������
	void MyDelChr(char c); // ����� ��� �������� ���������� ������� �� ������
	int MyStrCmp(MyString& b); // ����� ��� ��������� ���� �����

	void Print(); // ����� ��� ������ ������ �� �����
	void Input(); // ����� ��� ����� ������ � ����������

	static void GetCountLiveObj(); // ����������� ����� ��� ��������� ���������� ����� (������� ���������� � ������ ������, ��� ���� �������� � ��� �� ����������) ��������
	static void GetCountCreatedObj(); // ����������� ����� ��� ��������� ���������� ��������� ��������
}; 

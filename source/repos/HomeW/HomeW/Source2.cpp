#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

class Student {
    char* firstName;
    char* lastName;
    char* middleName;

    int birthDay;
    int birthMonth;
    int birthYear;

    int phoneNumber;

    char* nationality;

    char* college;
    int classNumber;

public:
    // Конструкторы и деструктор
    Student() : firstName(nullptr), lastName(nullptr), middleName(nullptr),
        birthDay(0), birthMonth(0), birthYear(0), phoneNumber(0),
        nationality(nullptr), college(nullptr), classNumber(0) {}

    Student(const char* fName, const char* lName, const char* mName,
        int day, int month, int year, int phone,
        const char* nation, const char* collegeName, int classNum) {

        firstName = new char[strlen(fName) + 1];
        strcpy_s(firstName, strlen(fName) + 1, fName);

        lastName = new char[strlen(lName) + 1];
        strcpy_s(lastName, strlen(lName) + 1, lName);

        middleName = new char[strlen(mName) + 1];
        strcpy_s(middleName, strlen(mName) + 1, mName);

        birthDay = day;
        birthMonth = month;
        birthYear = year;

        phoneNumber = phone;

        nationality = new char[strlen(nation) + 1];
        strcpy_s(nationality, strlen(nation) + 1, nation);

        college = new char[strlen(collegeName) + 1];
        strcpy_s(college, strlen(collegeName) + 1, collegeName);

        classNumber = classNum;
    }

    ~Student() {
        delete[] firstName;
        delete[] lastName;
        delete[] middleName;
        delete[] nationality;
        delete[] college;
    }

    // Сеттеры
    void setFirstName(const char* fName) {
        if (firstName != nullptr) {
            delete[] firstName;
        }
        firstName = new char[strlen(fName) + 1];
        strcpy_s(firstName, strlen(fName) + 1, fName);
    }

    void setLastName(const char* lName) {
        if (lastName != nullptr) {
            delete[] lastName;
        }
        lastName = new char[strlen(lName) + 1];
        strcpy_s(lastName, strlen(lName) + 1, lName);
    }

    void setMiddleName(const char* mName) {
        if (middleName != nullptr) {
            delete[] middleName;
        }
        middleName = new char[strlen(mName) + 1];
        strcpy_s(middleName, strlen(mName) + 1, mName);
    }

    void setBirthDay(int day) {
        birthDay = day;
    }

    void setBirthMonth(int month) {
        birthMonth = month;
    }

    void setBirthYear(int year) {
        birthYear = year;
    }

    void setPhoneNumber(int phone) {
        phoneNumber = phone;
    }

    void setNationality(const char* nation) {
        if (nationality != nullptr) {
            delete[] nationality;
        }
        nationality = new char[strlen(nation) + 1];
        strcpy_s(nationality, strlen(nation) + 1, nation);
    }

    void setCollege(const char* collegeName) {
        if (college != nullptr) {
            delete[] college;
        }
        college = new char[strlen(collegeName) + 1];
        strcpy_s(college, strlen(collegeName) + 1, collegeName);
    }

    void setClassNumber(int classNum) {
        classNumber = classNum;
    }

    // Геттеры
    const char* getFirstName() const {
        return firstName;
    }

    const char* getLastName() const {
        return lastName;
    }

    const char* getMiddleName() const {
        return middleName;
    }

    int getBirthDay() const {
        return birthDay;
    }

    int getBirthMonth() const {
        return birthMonth;
    }

    int getBirthYear() const {
        return birthYear;
    }

    int getPhoneNumber() const {
        return phoneNumber;
    }

    const char* getNationality() const {
        return nationality;
    }

    const char* getCollege() const {
        return college;
    }

    int getClassNumber() const {
        return classNumber;
    }

    // Функции
    void Input() {
        char bufferFirstName[100];
        char bufferLastName[100];
        char bufferMiddleName[100];
        char bufferNationality[100];
        char bufferCollege[100];

        cout << "Enter last name: ";
        cin.ignore();
        cin.getline(bufferLastName, 100);

        cout << "Enter first name: ";
        cin.getline(bufferFirstName, 100);

        cout << "Enter middle name: ";
        cin.getline(bufferMiddleName, 100);

        cout << "Enter country: ";
        cin.getline(bufferNationality, 100);

        cout << "Enter phone number: ";
        cin >> phoneNumber;
        cin.ignore();

        cout << "Enter day of birth: ";
        cin >> birthDay;
        cin.ignore();

        cout << "Enter month of birth: ";
        cin >> birthMonth;
        cin.ignore();

        cout << "Enter year of birth: ";
        cin >> birthYear;
        cin.ignore();

        cout << "Enter college name: ";
        cin.getline(bufferCollege, 100);

        cout << "Enter class number: ";
        cin >> classNumber;
        cin.ignore();

        setFirstName(bufferFirstName);
        setLastName(bufferLastName);
        setMiddleName(bufferMiddleName);
        setNationality(bufferNationality);
        setCollege(bufferCollege);
    }

    void PrintStudent() const {
        if (firstName != nullptr) cout << "First Name: " << firstName << endl;
        else cout << "First Name: N/A" << endl;

        if (lastName != nullptr) cout << "Last Name: " << lastName << endl;
        else cout << "Last Name: N/A" << endl;

        if (middleName != nullptr) cout << "Middle Name: " << middleName << endl;
        else cout << "Middle Name: N/A" << endl;

        cout << "Date of Birth: " << birthDay << "/" << birthMonth << "/" << birthYear << endl;

        cout << "Phone Number: " << phoneNumber << endl;

        if (nationality != nullptr) cout << "Country: " << nationality << endl;
        else cout << "Country: N/A" << endl;

        if (college != nullptr) cout << "College: " << college << endl;
        else cout << "College: N/A" << endl;

        cout << "Class Number: " << classNumber << endl;
    }
};

int main() {
    Student student1("John", "Doe", "Smith", 15, 5, 2000, 1234567890, "USA", "MIT", 101);
    student1.PrintStudent();

    Student student2;
    student2.Input();
    student2.PrintStudent();

    system("pause");
    return 0;
}
#include "AnimalWorld.h"
#include "Africa.h"
#include "NorthAmerica.h"
#include "Australia.h"
#include <iostream>

using namespace std;

void print_menu() {
    cout << "------ ���� ��� �������� -------" << endl;
    cout << "1) ������� ������� [�����]" << endl;
    cout << "2) ������� �������� [������� �������]" << endl;
    cout << "3) ������� �������� [��������]" << endl;
    cout << "4) ������ ���������" << endl;
    cout << "5) ������������ ����� ��������" << endl;
    cout << "6) �����" << endl;
    cout << "����� ����: ";
}

int main() {
    setlocale(LC_ALL, "ru");
    AnimalWorld world;
    bool is_running = true;
    int option;

    while (is_running) {
        system("cls");
        print_menu();
        cin >> option;

        switch (option) {
        case 1: {
            cout << "������� ������� ������" << endl;
            world.add_continent(new Africa());
            break;
        }
        case 2: {
            cout << "������ ��������� ������� �������" << endl;
            world.add_continent(new NorthAmerica());
            break;
        }
        case 3: {
            cout << "������ ������� ���������" << endl;
            world.add_continent(new Australia());
            break;
        }
        case 4: {
            cout << "� ��������� ��������  ���" << endl;
            world.meals_herbivores();
            break;
        }
        case 5: {
            cout << "�� �������� ������� �����" << endl;
            world.nutrition_carnivores();
            break;
        }
        case 6: {
            cout << "������ ������ �������" << endl;
            is_running = false;
            break;
        }
        default:
            cout << "����� ������� �������� �����" << endl;
            break;
        }
        cout << endl;
        system("pause");
    }

    return 0;
}
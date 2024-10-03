#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    MyString stringExample("HpHpHp");
    cout << "Len = " << stringExample.MyStrLen() << endl;
    stringExample.Print();

    stringExample.Input();
    stringExample.Print();

    MyString stringExample2("HipHipHip!");

    stringExample += " Hello for All";
    stringExample.Print();

    MyString stringExample3;
    stringExample3 = "Hello, " + stringExample2;
    stringExample3.Print();

    MyString::GetCountLiveObj();
    MyString::GetCountCreatedObj();

    return 0;
}
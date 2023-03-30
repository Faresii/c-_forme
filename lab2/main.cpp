#include <iostream>
#include <sstream>
#include <string>
#include "String_Class.h"
#include "String_Class.cpp"

using namespace std;

int main(){
        Str_pm str1;
        str1.Print();  
        // Конструктор с параметрами
    char str_norm[20];
    cout << "Введите строку (не больше 20 символов): " << endl;
    cin.getline(str_norm, 20);
    for(int i = 0; i < strlen(str_norm);i++) 
    {
        if(i > 20) return 0;
    }



    Str_pm str2(str_norm);
    str2.Print();

    cout << "строка в обратку : ";
    str2.operator--();
    cout << endl;


    cout << "строчная строка : ";
    str2.operator++();
    cout << endl;

    system("pause");
    return 0;
}

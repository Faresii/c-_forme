#include "String_Class.h"
#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;

	Str_pm::Str_pm()
	{
	cout << "Конструктор по умолчанию" << endl;
	this->n = strlen(s);
	this->s = new char[n + 1];
     
    //strcpy(this->s, s);
	}

    Str_pm::Str_pm(const char *str)
{
	cout << "Конструктор с параметрами" << endl;
    this->n = strlen(str);
	this->s = new char[n + 1];
     
    strcpy(this->s, str);

}

Str_pm::Str_pm(const Str_pm &Str_pm)
{
	n = Str_pm.n;
	s = new char[n + 1];
	//здесь может быть отказ в выделении памяти
	strcpy(s, Str_pm.s);
}

void Str_pm::Set_str_pm(const char *str)
{
	n = strlen(str);
	this->s = new char[n + 1];
	
}

void Str_pm::Print(){
	cout << "строка :" << s << endl;
}


void Str_pm::operator--(){

    for (int i = strlen(s) - 1;i >= 0; i--){
			cout << s[i];
		}
}

void Str_pm::operator++(){
	
	for( int i = 0; i < strlen(s); i ++ )
    {
 if(isupper(s[i]))
       
        s[i] = tolower(s[i]);

		cout << s[i];
    }     
	}


	Str_pm::~Str_pm() //деструктор
{
cout << "Деструктор" << endl;
delete[] s;
}

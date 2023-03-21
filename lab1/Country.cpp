#define _CRT_SECURE_NO_WARNINGS //Разрешение использование небезопасных функций
#include <iostream>
#include <cstring>
#include "Country.h"
using namespace std;


Country::Country(const char *str, const char *str1, const float _square) //конструктор по умолчанию
//Country(const char *str = "") - будет ошибкой, параметр по умолчанию уже указан в прототипе
{
	this->n = strlen(str);
	this->n1 = strlen(str1); //вычислили длину строки
	this->s = new char[n + 1];
	this->forma = new char[n1 + 1];
	this->square = _square;
	//выделили буфер
	//здесь может быть отказ в выделении памяти
	strcpy(this->s, str);
	strcpy(this->forma, str1); //скопировали в буфер строку
}

Country::Country(const Country & Country) //конструктор копирования
{
	n = Country.n; //извлекли длину строки
	n1 = Country.n1;
	s = new char[n + 1];
	forma = new char[n1 +1];
	//здесь может быть отказ в выделении памяти
	strcpy(s, Country.s);
	strcpy(forma, Country.forma); //скопировали в буфер строку

	square = Country.square;

}
Country::~Country() //деструктор
{
	delete[] s;
	delete[] forma; //т.к. буфер выделялся в динамической памяти, то освобождение ее при удалении объекта

	//delete square;
}

// Установка новых полей в конструкторе
void Country::set_Country(const char *str, const char *str1, float square)
{
	//Страна
	n = strlen(str);
	this->s = new char[n + 1];

	//Форма
	n1 = strlen(str1);
	this->forma = new char[n1 + 1];

	//Площадь
	this->square = square;
}

void Country::Print(void) // вывод на экран
{
	cout << "Country: " << s << endl;
	cout << "Forma: " << forma << endl;
	cout << "Square: " << square << endl;
}

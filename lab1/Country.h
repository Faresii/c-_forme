#include <string>
#ifndef COUNTRY_H
#define COUNTRY_H
class Country //Класс строки в динамической памяти
{
private:
	int n; 
	int n1;//длина строки (без учета завершающего „\0‟)
	char *s;
	char *forma;
	float square; //адрес буфера для строки в динамической памяти
	//память выделяется в конструкторе
	//ее следует освободить в деструкторе
	//также для класса следует переопределить
	//конструктор копирования и операторы
public:
	Country(const char *str = "", const char *str1 = "", float square = 0); //конструктор по умолчанию
	Country(const Country &); //конструктор копирования

	~Country(); //деструктор

	void set_Country(const char *str, const char *str1, float square);
	
	void Print(void); //вывод строки на экран
};

#endif

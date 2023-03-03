#include <iostream>
#include "Country.h"
#include "Country.cpp"

using namespace std;

	char s[10] = "Argentina";
	char forma[10] = " aaa bbbb";	
	float square = 10.5;

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	Country a; //конструктор по умолчанию
	cout << "КОНСТРУКТОР 1 (без параметров)" << endl;
	a.Print();
	cout << "......." << endl;


	Country b ("Afrika", "nuzhnaya", 6.5); //конструктор с переопределенным значением
	cout << "КОНСТРУКТОР 2 (с параметрами)" << endl;
	b.Print();
	cout << "......." << endl;


	Country c = b; //конструктор копирования
	cout << "\n" << "КОНСТРУКТОР 3 (копирования)" << endl;
	c.Print();
	cout << "......." << endl;

	Country *p = new Country(s, forma, square);
	cout << "\n" << "КОНСТРУКТОР 4 (создаем новые параметры)" << endl;
	p->Print();
	cout << "......." << endl;
	delete p;

	
	Country k;
	cout << "\n" << "КОНСТРУКТОР 5 (деструктор)" << endl;
	k.Print();
	cout << "......." << endl;
	
	
	system("pause");
	return 0;
}

#include <iostream>
#include "header.h"
#include "class.cpp"
#define LEN 80

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	char gosudarstvo[LEN];
	int a = 0;
	char country[LEN];

	while(1){
	cout << "ВЫБЕРЕТЕ ГОСУДАРСВТО : 1) РЕСПУБЛИКА 2) КОРОЛЕВСТВО 3) МОНАРХИЯ " << endl;
	cin >> a;

	if(a == 1){
	cout << "Введите страну" << endl;
	cin >> country;

	Republic r1(country, 17098);
	r1.Print();
	//break;
	}

	if(a == 2)
		{
	cout << "\nВведите страну" << endl;
	cin >> country;

	Kingdom k1(country, 242495);
	k1.Print();
	//break;
		}

	if(a == 3)
	{
	cout << "\nВведите страну" << endl;
	cin >> country;
	Monarchy* m1 = new Monarchy;
	m1->SetArea(35000);
	m1->SetName(country);
	m1->Print();
	delete m1;
	//break; // освобождение динамической памяти 
	}

	if (a > 3 || a < 1) {
		cout << "НЕКОРРЕКТНЫЙ ВВОД" << endl;
		return 0;
	}
	}
    system("pause");
	return 0;
}

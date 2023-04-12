#include <iostream>
#include <string>
#include <vector>
#include "Art.h"
#include<Windows.h> // нужно чтобы работало SetConsoleCP(1251); SetConsoleOutputCP(1251);

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); // чтобы могли писать на русском
	SetConsoleOutputCP(1251); // это для того же

	int a = 0;
	int count = 0;
	string art;
	vector <string> arrayArt; // vector динамический массив (шаблон, не являющийся изначально типом данных)

	while (1) {
		cout << "\nВЫБЕРЕТЕ ИСКУССТВО : 1) ТЕАТР 2) ЖИВОПИСЬ 3) МУЗЫКА " << endl;
		cin >> a;

		if (a == 1) 
		{
			cout << "\nВведите театр" << endl;
			cin >> art;
			

			Theater r1(art, 1709, 500);
			r1.Print();

		}

		if (a == 2)
		{
			cout << "\nВведите живопись" << endl;
			cin >> art;

			Painting p1(art, 242495, 2);
			p1.Print();

			
			
		}

		if (a == 3)
		{
			cout << "\nВведите музыку" << endl;
			cin >> art;
			Music* m1 = new Music;
			m1->SetCost(350);
			m1->SetName(art);
			m1->SetMusic(10);
			m1->Print();
			delete m1;

			
			
		}

		if (a > 3 || a < 1) {
			cout << "НЕКОРРЕКТНЫЙ ВВОД" << endl;
			break;
		}
		
		arrayArt.push_back(art); // добавляем расположение каждый раз 
	}

	
	cout << "\nСОХРАНЕННЫЕ РАСПОЛОЖЕНИЯ " << endl;

	for (int i = 0; i < arrayArt.size(); i++)
	{
		cout << "№ " << i + 1 << " : " << arrayArt[i] << endl;
		
	}

	arrayArt.clear(); // очищаем наш динамический массив

	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <map>
#include<Windows.h> // нужно чтобы работало SetConsoleCP(1251); SetConsoleOutputCP(1251);

using namespace std;




int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); // чтобы могли писать на русском
	SetConsoleOutputCP(1251); // это для того же

	map <string, string > mp;

	map <string, string> mp1;

	map <string, string >::iterator it; // или можно написать (auto it;)

	map <string, string > mpMerge;


	map <string, string >::iterator item = mp.find("");

	cout << "Условие 1 : Контейнер объектов класса в соответствии с вариантом задания" << endl;
	cout << "Условие 2 : Просмотр элементов контейнера" << endl;
	cout << "Условие 3 : Изменение контейнера, за счет удаления из него двух элементов и заменой на другие" << endl;
	cout << "Условие 4 : Используя подходящий алгоритм, нахождение в контейнере элемента, удовлетворяющего заданному условию " << endl;
	cout << "Условие 5 : Используя подходящий алгоритм, нахождение в контейнере элемента, удовлетворяющего заданному условию " << endl;
	cout << "Условие 6 : Создание третьего контейнера путем слияния первых двух" << endl;

	while (1) {
		int a = 0;

		cout << endl << "Введите условие : " << endl;
		cin >> a;

		

		// Условие № 1
		if (a == 1) {
			int k = 0;

				string s, s1;
				cout << "Введите строку " << endl;
				cin >> s;
				cin >> s1;

				mp = { {s, s1},
					  {"Student", "Студент"},
					  {"!","Hello world!"} };

			continue;
		}


		// Условие №2
		if (a == 2) {
			cout << "Вывод всего контейнера " << endl;
			for (it = mp.begin(); it != mp.end(); it++)
			{
				cout << it->first << " " << it->second << endl;
			}
			continue;
		}

		// Условие №3
		if (a == 3) {
			cout << "Условие №3" << endl;
			int count = 0;

			while (count < 2) {
				string value;

				cout << "Удаление введенного значения :" << endl;

				cin >> value;

				// Замена элементов в контейнере ( map )
				for (auto pos = mp.begin(); pos != mp.end();)
				{
					if (pos->second == value)
					{
						pos = mp.erase(pos); // C++11

						string str, str1;
						cout << "Введите ЗНАЧЕНИЕ " << endl;
						cin >> str;
						cin >> str1;
						mp.insert(pair <string, string>(str, str1));
					}
					else
					{
						++pos;
					}
				}
				count++;
			}

			for (it = mp.begin(); it != mp.end(); it++)
			{
				cout << it->first << " " << it->second << endl;
			}

			continue;
		}


		// Условие № 4
		if (a == 4) {
			cout << "\nУСЛОВИЕ № 4" << endl;

			cout << "Введите ключ который хотите найти" << endl;
			string s;
			cin >> s;

			item = mp.find(s);
			for (auto pos = mp.begin(); pos != mp.end(); pos++) {
				if (item == pos) {
					cout << "Ключ существует : " << item->first << endl;
				}
				else {
					cout << "Ключ НЕ существует" << endl;
				}
			}

			
			continue;
		}

		// Условие № 5
		if (a == 5) {
			cout << "\nУСЛОВИЕ № 5" << endl;
			 
			for (auto pos = mp.begin(); pos != mp.end(); pos++) {
				if (item == pos) {
					mp1.insert(pair<string, string>(item->first, item->second));
				}

			}

			for (it = mp1.begin(); it != mp1.end(); it++)
			{
				cout << it->first << " " << it->second << endl;
			}

			continue;
		}


		// Условие № 6
		if (a == 6) {

			/* Обратите внимание, что если ключ существует в обеих картах, значение в указанной карте
			не перезапишет значение в исходной (новой) карте */

			mpMerge = mp;

			mpMerge.insert(mp1.begin(), mp1.end());

			cout << "\nУСЛОВИЕ № 6" << endl;

			for (it = mpMerge.begin(); it != mpMerge.end(); it++)
			{
				cout << it->first << " " << it->second << endl;
			}
		}

		else break;

	}
	

	return 0;
}

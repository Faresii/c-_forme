#include <iostream>
#include <string>
#include <map>
#include<Windows.h> // нужно чтобы работало SetConsoleCP(1251); SetConsoleOutputCP(1251);

using namespace std;


class MyMap
{
public:
	MyMap();
	~MyMap();

private:

};


int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); // чтобы могли писать на русском
	SetConsoleOutputCP(1251); // это для того же





	cout << "Условие 1 : Контейнер объектов класса в соответствии с вариантом задания" << endl;
	cout << "Условие 2 : Просмотр элементов контейнера" << endl;
	cout << "Условие 3 : Изменение контейнера, за счет удаления из него двух элементов и заменой на другие" << endl;
	cout << "Условие 4 : Используя подходящий алгоритм, нахождение в контейнере элемента, удовлетворяющего заданному условию " << endl;
	cout << "Условие 5 : Используя подходящий алгоритм, нахождение в контейнере элемента, удовлетворяющего заданному условию " << endl;
	cout << "Условие 6 : Создание третьего контейнера путем слияния первых двух" << endl;

	// Условие № 1
	map <string, string > mp = { {"Hi", "Привет"},
								{"Student", "Студент"},
									{"!","Hello world!"} };

	map <string, string > mp1;

	map <string, string >::iterator it; // или можно написать (auto it;)

	// Условие №2
	cout << "Вывод всего контейнера " << endl;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	// Условие №3
	
	int count = 0;

	while (count < 2) {
		string value = "Привет";

		// Замена элементов в контейнере ( map )
		for (auto pos = mp.begin(); pos != mp.end();)
		{
			if (pos->second == value)
			{
				pos = mp.erase(pos); // C++11
				mp.insert(pair <string, string>("1", "2"));
			}
			else
			{
				++pos;
			}
		}
		count++;
	}

	cout << "\nУСЛОВИЕ № 3" << endl;

	for (it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	


	// Условие № 4
	cout << "\nУСЛОВИЕ № 4" << endl;

	auto item = mp.find("Student");
	int i = 0;


	for (auto pos = mp.begin(); pos != mp.end(); pos++) {
		if (item == pos) {
			cout << "Ключ существует : " << item->second << endl;
		}
		else {
			cout << "Ключ НЕ существует" << endl;
		}
	}


	// Условие № 5
	cout << "\nУСЛОВИЕ № 5" << endl;

	mp1.insert(item, mp.end());

	for ( it = mp1.begin(); it != mp1.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}



	// Условие № 6

	map <string, string > mpMerge;

	/* Обратите внимание, что если ключ существует в обеих картах, значение в указанной карте
	не перезапишет значение в исходной (новой) карте */
	mpMerge = mp;
	mpMerge.insert(mp1.begin(), mp1.end());

	cout << "\nУСЛОВИЕ № 6" << endl;

	for (it = mpMerge.begin(); it != mpMerge.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	

	return 0;
}

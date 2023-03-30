#include <iostream>
#include <string>
#ifndef STRING_CLASS_H
#define STRING_CLASS_H
using namespace std;

class Str_pm
{
	private:
		int n = 0; 															//размерность массива
		char *s = "";									//массив со значением вектора
		//void addLength(Vector &vector);										//увеличение длинны массива
	public:
		Str_pm();
		Str_pm(const char *str);													//конструктор без параметров, по умолчанию значения {1,1,1}
		Str_pm(const Str_pm&);										
		void Set_str_pm(const char *str);																								//получение размера массива
		void operator --();
		void operator ++();					//переопределение оператора ++
		~Str_pm();	//деструктор
        void Print(); //вывод строки на экран
};


#endif

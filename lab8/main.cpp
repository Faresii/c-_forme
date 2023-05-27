#include <boost/lambda/lambda.hpp> // подключение lambda-выражений
#include <boost/algorithm/string.hpp>   
#include <iostream>
#include <iterator> // итераторы из stl
#include <algorithm> // алгоритмы из stl
#include <string>
#include <vector>
#include <Windows.h> // нужно чтобы работало SetConsoleCP(1251); SetConsoleOutputCP(1251);
#include <cstring>



using namespace boost::lambda; // подключение пространства имен boost::lambda
using namespace std;

bool isSpace(char c) {
    return c == ' ';
}

// Функция для удаления всех лишних пробелов из строки
// (обратите внимание, что строка передается по ссылке)
void removeSpace(string& s)
{
    // true, если найден пробельный символ, и false, если
    // найден любой непробельный символ
    bool space = false;

    // `k` указывает на следующую свободную позицию
    int k = 0;

    // перебираем символы строки
    for (int i = 0; i < s.length(); i++)
    {
        // обработка начальных пробелов в строке
        while (k == 0 && i < s.length() && isSpace(s[i])) {
            i++;
        }

        // если текущий символ пробел
        if (isSpace(s[i]))
        {
            // если флаг ранее был ложным, т.е. первое вхождение
            // пробел после слова
            if (!space)
            {
                // копируем текущий символ (пробел) в следующий свободный индекс
                // и устанавливаем флаг
                s[k++] = s[i];
                space = true;
            }
        }
        // если текущий символ является знаком препинания
        else if (ispunct(s[i]))
        {
            // если последним назначенным символом был пробел, перезаписать его
            // с текущим символом
            if (k > 0 && isSpace(s[k - 1])) {
                s[k - 1] = s[i];
            }
            else {
                // копируем текущий символ в следующий свободный индекс
                s[k++] = s[i];
            }
            space = false;
        }
        else {
            // копируем текущий символ в следующий свободный индекс
            s[k++] = s[i];
            space = false;
        }
    }

    // обрабатывать конечные пробелы в строке
    s.erase(s.begin() + k, s.end());
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // чтобы могли писать на русском
    SetConsoleOutputCP(1251); // это для того же

    int count = 0;

    vector <string> student_result;
    string result;

    string str;

    vector <string> student;
    int size = student.size();

    cout << "1) сохранение и вывод на консоль фамилии студента" << endl;
    cout << "2) сохранение и вывод на консоль имени студента" << endl;
    cout << "3) сохранение и вывод на консоль отчества студента" << endl;
    cout << "4) удаление из строки лишних пробелов (оставить один между словами) " << endl;
    cout << "5) сохранение и вывод на консоль строки в верхнем регистре" << endl;
    cout << "6) сохранение и вывод на консоль строки в нижнем регистре" << endl;
    cout << "7) поиск имени в строке" << endl;
    cout << "8) замена фамилии в строке" << endl;
    cout << "9) проверить строку на верхний регистр" << endl;
    cout << "10) проверить строку на нижний регистр" << endl << endl;

    cout << "ЕЩЁ ДОБАВИЛ УСЛОВИЯ" << endl << "11) Просмотр всех студентов" << endl << "12) Ввод нового студента" << endl << endl;


    while (1) {
        
        int a = 0;

        if (count == 0) {
            cout << "Введите ФИО студента" << endl;

            //Ввод строки с пробелами
            getline(cin, str);

            count = 1;
            removeSpace(str);

                    split(student, str, boost::algorithm::is_any_of(" "));

                    size = student.size();

        // Для первых условий 
        while (size > 3) {
            student.pop_back();
            size--;

        }

        string result1;
        // Соединение строки и засовываение в один массив

        for (int i = 0; i < size; i++)
        {
            result1 += student[i];
            result1 += " ";
        }

        student_result.push_back(result1);
        result = result1;
        }



        cout << endl << "ВВЕДИТЕ УСЛОВИЕ " << endl;
        cin >> a;

        /*ignore(n,'\n') число пропускаемых символов и символ разделения т.е. проскает n символов,
        если ранее не будет найден '\n', далее если '\n' введен раньше n то будет удален из буфера
        и ignore() завершит работу.*/

        cin.ignore();

        // Условие 12
        if (a == 12) {
            cout << "Введите ФИО студента" << endl;

            //Ввод строки с пробелами

            getline(cin, str);

            removeSpace(str);

            student.clear();

        split(student, str, boost::algorithm::is_any_of(" "));

        size = student.size();

        // Для первых условий 
        while (size > 3) {
            student.pop_back();
            size--;

        }

        string result1;
        // Соединение строки и засовываение в один массив

        for (int i = 0; i < size; i++)
        {
            result1 += student[i];
            result1 += " ";
        }

        student_result.push_back(result1);
        result = result1;

        continue;
    }
            
        size = student.size();

        //Условие 1

        if (a == 1) {
            for (int i = 0; i < size; i++)
            {
                if (i == 0) cout << "Фамилия : " << student[i] << endl;

            }
            continue;
        }


        //Условие 2
        if (a == 2) {
            for (int i = 0; i < size; i++)
            {
                if (i == 1) cout << "Имя : " << student[i] << endl;

            }
            continue;
        }


        //Условие 3
        if (a == 3) {
            for (int i = 0; i < size; i++)
            {
                if (i == 2) cout << "Отчество : " << student[i] << endl;

            }
            continue;
        }


        //Условие 4
        if (a == 4) {
            removeSpace(str);

            cout << "Удаление из строки лишних пробелов (если они имеются) : " << str << endl;

            continue;
        }

        //Условие 5
        if (a == 5) {
            boost::algorithm::to_upper(str);
            boost::algorithm::to_upper(result);
            cout << "Запись строки в верхнем регистре " << str << endl;
            for (int i = 0; i < size; i++)   boost::algorithm::to_upper(student[i]);
            

            student_result.pop_back();
            student_result.push_back(result);

            continue;
        }

        //Условие 6
        if (a == 6) {
            boost::algorithm::to_lower(str);
            boost::algorithm::to_lower(result);
            cout << "Запись строки в нижнем регистре " << str << endl;
            for (int i = 0; i < size; i++)   boost::algorithm::to_lower(student[i]);
            
            student_result.pop_back();
            student_result.push_back(result);



            continue;
        }

        //Условие 7
        if (a == 7) {

            for (int i = 0; i < size; i++)
            {
                if (i == 1) cout << "Нашли имя : " << student[1] << endl;
            }
            continue;
        }

        //Условие 8
        if (a == 8) {
            for (int i = 0; i < size; i++)
            {
                if (i == 0) {
                    cout << "Введите Фамилию, на которую хотите заменить текущую" << endl;
                    string str3;
                    cin >> str3;

                    student[0] = str3;
                }
            }
            continue;
        }

        //Условие 9
        if (a == 9) {
            cout << "Проверка подстрок на регистр" << endl;
            for (int i = 0; i < size; i++)
            {
                cout
                    << "Подстрока " << student[i]
                    << (all(student[i], boost::algorithm::is_upper()) ? "" : " не")
                    << " записана в верхнем регистре." << endl ;

            }
            cout << endl
                << "Строка " << str
                << (boost::algorithm::all(str, boost::algorithm::is_upper()) ? "" : " не")
                << " записана в верхнем регистре." << endl;

            continue;
        }
        

        //Условие 10
        if (a == 10) {
            cout << "Проверка подстрок на регистр" << endl;
            for (int i = 0; i < size; i++)
            {
                cout
                    << "Подстрока " << student[i]
                    << (all(student[i], boost::algorithm::is_lower()) ? "" : " не")
                    << " записана в нижнем регистре." << endl;

            }

            cout << endl 
                << "Строка " << str
                << (all(str, boost::algorithm::is_lower()) ? "" : " не")
                << " записана в нижнем регистре." << endl;

            continue;
        }

        // Условие 11
        if (a == 11) {
            for (int i = 0; i < student_result.size(); i++)
            {
                cout << "Студент " << i + 1 << " : " << student_result[i] << endl;
            }
        }

        else break;

    }

    //typedef istream_iterator<int> in; // входной итератор
    //for_each(in(cin), in(), cout << (_1 * 3) << "\n"); /* (с начала входного потока, пока во входном потоке что - то есть,
    //что применить)*/
    //// для завершения работы нажмите сочетание клавиш Ctrl + Z и Enter
    return 0;
}

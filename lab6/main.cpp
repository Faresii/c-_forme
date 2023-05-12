#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string familia;
    string surname;
    string name;
    string patronymic;
    int date;
    string mark;

    Student(){}
    Student(string s, string n,string p, int d, string m) {
        familia = "Фамилия : ";
        surname = s;
        name = n;
        patronymic = p;
        date = d;
        mark = m;
    }


    void Print(){
        cout << familia << surname << " Имя : " << name << " Отчество : " << patronymic << " Месяц рождения ученика : " << date << " Список отметок : " << mark  << endl;
    }
    
    void Set(){
        cout << "Введите Фамилию : " << endl;
        cin >> surname;

        cout << " Введите имя : " << endl;
        cin >> name;

        cout << "Введите Отчество : " << endl;
        cin >> patronymic;
        while(1){
        cout << "Введите месяц рождения : " << endl;
        cin >> date;
        if (date > 0 && date < 13) break;
        else continue;
        }

        cout << "Список отметок : " << endl;
        cin >> mark;
    }

};

struct Node
{
    Student* data;
    Node* next;

    Node() : data(nullptr), next(nullptr){}
    Node(Student* data) : data(data), next(nullptr){}
};


class LinkedList
{
private:
    Node* head;
    int size = 0;
    

public:
    
   LinkedList() : head(NULL), size(0) {
   }

    ~LinkedList() {
    Node* current = head;
    while (current != NULL) {
    Node* next = current->next;
    delete current->data;
    delete current;
    current = next;
        }
    }

        void AddEnd(Student* s){           // условиe №2
        Node* newNode = new Node(s);
        if (head == nullptr) {
            head = newNode;
            size++;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
                size++;
            }
            current->next = newNode;
        }
        }
    void AddFirst(Student* s){          // условие №3
        Node* newNode = new Node(s);
        newNode->next = head;
        head = newNode;
        size++;
    }



void PrintAll() {                   // условие №4
Node* current = head;
int i = 0;

while (current != NULL && i < size) {
current->data->Print();
current = current->next;
i++;
}
}


void deleteFirstElement (int date){ // условие № 5
         if (head != nullptr && head->data->date == date) {
            Node* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
        else {
            Node* current = head;
            while (current != nullptr && current->next != nullptr) {
                if (current->next->data->date == date) {
                    Node* temp = current->next;
                    current->next = temp->next;
                    delete temp->data;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }
            }

void deleteAllWithValue(int date) { // условие №6
        while (head != nullptr && head->data->date == date) {
            Node* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
        if (head != nullptr) {
            Node* current = head;
            while (current->next != nullptr) {
                if (current->next->data->date == date) {
                    Node* temp = current->next;
                    current->next = temp->next;
                    delete temp->data;
                    delete temp;
                }
                else {
                    current = current->next;
                }
            }
        }
    }


    void deleteAll() { // Метод, удаляющий все узлы списка
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = nullptr;
    }

int _size(){
    return size;
}

};

int main(){

    setlocale(LC_ALL, "rus");

    LinkedList list;

//     Student* s1 = new Student("a", "b","c", 20, "e");

//     Student* s5 = new Student("a", "b","c", 20, "eeegd");
//    s1->Set();

//     Student* s2 = new Student("algmdslgdsma", "b","c", 12, "gip");

//     Student* s3 = new Student("a", "b","c", 10, "pipp");

//     Student* s4 = new Student("a", "b","cdgdgs", 10, "liljg");

//     list.AddFirst(s1);

//     list.AddFirst(s2);

//     list.AddFirst(s4);

//     list.AddEnd(s3);

//     list.AddEnd(s5);

//     list.PrintAll();

//     cout << "НУЖНЫЙ ЭЛЕМЕНТ" << endl;

//     list.deleteAllWithValue(10);

//     list.deleteFirstElement(20);

//     cout << endl;

//     list.PrintAll();

//    list.deleteAll();
    
while(1){

    cout << "\nВВЫБЕРИТЕ УСЛОВИЕ ОТ 1 ДО 7" << endl;
    int a = 0;
    cin >> a;


    if(a == 1){
    cout << "Конструктор и деструктор" << endl;
    if(list._size() == 0)  cout << "Конструктор по умочанию " << endl;
    list.PrintAll();

    cout << "Вызван деструктор" << endl;
    list.~LinkedList();

    }

    if(a == 2){
        cout << "Добавление нового узла в конец списка " << endl;
        Student* s1 = new Student("a", "b","c", 20, "eeegd");
        s1->Set();
        list.AddEnd(s1);
    }
    if(a == 3){
        cout << "Добавление нового узла в начало списка" << endl;
        Student* s1 = new Student();
        s1->Set();
        list.AddFirst(s1);
    }
    if(a == 4){
        cout << "ВЫВОДИМ ВЕСЬ СПИСОК" << endl;
        list.PrintAll();
    }
    if(a == 5){
        int date = 0;
        cout << " Введите месяц рождения который хотите удалить " << endl;
        cin >> date;

        list.deleteFirstElement(date);
    }
    if(a ==6){
        cout << " Удаление всех найденных узлов с заданным значением " << endl;
        int date = 0;
        cout << " Введите месяц рождения который хотите удалить " << endl;
        cin >> date;

        list.deleteFirstElement(date);
        
    }
    if(a == 7){
        cout << "удаление всех узлов списка" << endl;
        list.deleteAll();
        
    }

    if(a < 0 && a > 8) break;

}
    
    return 0;
}

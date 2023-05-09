#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string surname;
    string name;
    string patronymic;
    string date;
    string mark;

public:
    Student(){}
    Student(string s, string n,string p, string d, string m) {
        surname = s;
        name = n;
        patronymic = p;
        date = d;
        mark = m;
    }

        ~Student(){
    }

    void Print(){
        cout << "Фамилия : " << surname << " Имя : " << name << " Отчество : " << patronymic << " Дата рождения : " << date << " Список отметок : " << mark  << endl;
    }
    
    void Set(){
        cout << " " << endl;
        cin >> surname;
        cout << " " << endl;
        cin >> name;
        cout << " " << endl;
        cin >> patronymic;
        cout << " " << endl;
        cin >> date;
        cout << " " << endl;
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

public:
    
   LinkedList() : head(NULL) {}

    ~LinkedList() {
    // Node* current = head;
    // while (current != NULL) {
    // Node* next = current->next;
    // delete current->data;
    // delete current;
    // current = next;
    //     }
    }

        void AddEnd(Student* s){           // условиe №2
        
        Node* current = head;

        while(current->next != nullptr){
        current = current->next;
        }

        current->next= new Node(s);
        }
    void AddFirst(Student* s){          // условие №3
        Node* newNode = new Node(s);
        newNode->next = head;
        head = newNode;
    }


void PrintAll() {                   // условие №4
Node* current = head;
while (current != NULL) {
current->data->Print();
current = current->next;
}
}

void deleteAll() {
Node* current = head;
// while (current != NULL) {
// Node* next = current->next;
// delete current->data;
// delete current;
// current = next;
// }
}

};

int main(){

    setlocale(LC_ALL, "rus");

    LinkedList list;

    Student* s1 = new Student("a", "b","c", "d", "e");
   // s1->Set();

    Student* s2 = new Student("a", "b","c", "f", "gip");

    Student* s3 = new Student("a", "b","c", "f", "pipp");

    list.AddFirst(s1);

    list.AddFirst(s2);

    list.AddEnd(s3);

    list.PrintAll();

    list.deleteAll();
    
    cout << "Hello world !" << endl;
    
    return 0;
}

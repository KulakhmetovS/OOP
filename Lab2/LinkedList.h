#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Student.h"

using namespace std;

struct Node
{
    //Поля листа списка
    string surname = "Нет данных"; //Фамилия
    string name = "Нет данных";    //Имя
    string patronymic = "Нет данных";  //Отчество
    string date = "Нет данных";    //Дата рождения
    string address = "Нет данных"; //Адрес
    string phone_number = "Нет данных";    //Номер телефона
    string faculty = "Нет данных"; //Факультет
    int course = 0;  //Курс
    Node *next; //Указатель на следующий лист

    Node(Student& student, Node *pointer)  //Конструктор для записи данных
    {
        surname = student.getSurname();
        name = student.getName();
        patronymic = student.getPatrinymic();
        date = student.getDateOfBirth();
        address = student.getAddress();
        phone_number = student.getPhoneNumber();
        faculty = student.getFaculty();
        course = student.getCourse();

        next = pointer;
    }
};

class LinkedList
{
    private:
        Node *head; //Указатель на голову списка
        int elementCount;   //Счётчик элементов

    public:
        LinkedList()    //Конструктор
        {
            head = nullptr; //Голова указывает на NULL
            elementCount = 0;   //Обнуление счётчика элементов
        }

        ~LinkedList()   //Деструктор, очищающий список
        {
            while(!empty())
            {
                popFront();
            }
        }

        bool empty() { return elementCount == 0; }  //Проверка на пустоту списка
        int size() {return elementCount;}   //Получение числа элементов списка
        void pushFront(Student& student);    //Добавление элемента в начало списка
        void popFront(); //Извлечение с начала
        void print();    //Вывод списка студентов
        Node *Next(Node *n) { return n->next; } //Получение указателя следующего элемента

        //Оператор "+" перегружен для добавления элемента в список
        void operator + (Student& other){ pushFront(other); }

        //Оператор "-" перегружен для удаления элемента из списка
        void operator - (Student& other)
        {
            Node *tmp = head;   //Копиование указателя на голову в указатель текущего элемента
            Node *prev = nullptr;   //Создание указателя на предыдущий элемент

            //Если не конец списка и поля не совпали с искомыми
            while(tmp != nullptr && tmp->name != other.getName() && tmp->surname != other.getSurname())
            {
                prev = tmp; //Предыдущий указатель получает адрес текущего элемента
                tmp = tmp->next;    //Текущий элемент получает указатель следующего
            }

            if(tmp == nullptr)  //Если адрес текущего элемента равен NULL
            {
                cout << "Студент отсутствует в списке" << endl;
                return;
            }

            if(prev == nullptr) //Если указатель на предыдущий элемент так и сотался NULL
            {
                head = tmp->next;   //Указатель головы смещается на следующий элемент
                elementCount--;
                delete tmp;
            }
            else    //В ним случае, если элемент посередине или в конце
            {
                //Указатель на предыдущий и текущий элементы указывает на слудующие элементы
                prev->next = tmp->next;
                elementCount--;
                delete tmp;
            }
        }
};


#endif // LINKEDLIST_H

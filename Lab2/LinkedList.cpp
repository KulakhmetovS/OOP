#include "LinkedList.h"

void LinkedList::pushFront(Student& student)    //Добавление элемента в начало списка
{
    head = new Node(student, head);   //Указатель на новый элемент списка
    elementCount++;
}

void LinkedList::popFront() //Извлечение с начала
{
    Node *nextHead = head->next;    //Переназначение указателя головы на следующий элемент
    delete head;
    head = nextHead;    //Обратное переназначение указателя головы на новый
    elementCount--;
}

void LinkedList::print()    //Вывод списка студентов
{
    Node *n = head; //Копирование указателя на голову

    while(n != nullptr) //Вывод списка студентов
    {
        cout << n -> surname << " " << n -> name << " " <<  n -> course << " " << n -> faculty << endl;
        n = Next(n);    //Использование метода Next()
    }
}

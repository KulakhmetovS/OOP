#ifndef OBSERVER_H
#define OBSERVER_H
#include "Student.h"

class Student;

class Observer
{
public:
    void GetInfo(Student& other);    //Получение информации из объекта базового класса
};

#endif // OBSERVER_H

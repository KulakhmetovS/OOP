#ifndef STUDENT_H
#define STUDENT_H
#include "Observer.h"
#include <iostream>

using namespace std;

class Observer;

class Student   //Главный класс
{
public:
    friend Observer;

private:    //Поля класса
    //int mark, date;
    string surname = "Нет данных"; //Фамилия
    string name = "Нет данных";    //Имя
    string patronymic = "Нет данных";  //Отчество
    string date = "Нет данных";    //Дата рождения
    string address = "Нет данных"; //Адрес
    string phone_number = "Нет данных";    //Номер телефона
    string faculty = "Нет данных"; //Факультет
    int course = 0;  //Курс

public: //Прототипы методов
    void setName(string surname, string name, string patronymic);   //Запись фамилии, имени и отчества
    void setContacts(string address, string phone_number, string faculty);  //Запись адреса, номера и факультета
    void setDateOfBirth(string date);   //Запись даты рождения
    void setCourse(int course); //Запись курса

    string getSurname() {return surname;};  //Получение фамилии
    string getName() {return name;};    //Получение имени
    string getPatrinymic() {return patronymic;};    //Получение отчества
    string getDateOfBirth() {return date;}; //Получение даты рождения
    string getAddress() {return address;};  //Получение адреса
    string getPhoneNumber() {return phone_number;}; //Получение номера телефона
    string getFaculty() {return faculty;};  //Получение факультета
    int getCourse() {return course;};   //Получение курса
    int getYear();

    //Перегрузка оператора "="
    const Student& operator = (const Student& other)
    {
        this->surname = other.surname;
        this->name = other.name;
        this->patronymic = other.patronymic;
        this->date = other.date;
        this->address = other.address;
        this->phone_number = other.phone_number;
        this->faculty = other.faculty;
        this->course = other.course;

        return *this;   //Ссылка на результат копирования (текущий объект)
    }

    //Перегрузка оператора "=="
    bool operator == (const Student& other)
    {
        bool eql = (this->surname == other.surname) &&
        (this->name == other.name) && (this->patronymic == other.patronymic) &&
        (this->date == other.date) && (this->address == other.address) &&
        (this->phone_number == other.phone_number) && (this->faculty == other.faculty) &&
        (this->course == other.course);

        return eql;
    }

    //Перегрузка оператора "!="
    bool operator != (const Student& other)
    {
        bool eql = (this->surname == other.surname) &&
        (this->name == other.name) && (this->patronymic == other.patronymic) &&
        (this->date == other.date) && (this->address == other.address) &&
        (this->phone_number == other.phone_number) && (this->faculty == other.faculty) &&
        (this->course == other.course);

        return !eql;
    }
};

#endif // STUDENT_H

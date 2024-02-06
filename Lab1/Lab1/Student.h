#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student   //Главный класс
{
/*Так как не было понятно для чего можно использовать конструкторы и деструкторы в данной задаче,
    принято решение просто закомментировать их с последующим объяснением принципов их работы преподавателю

public:
    Student(const Student& other)
    {
        cout << "Вызов конструктора копирования" << this << endl;
        this->mark = other.mark;
        this->date = other.date;
    }
    Student() {cout << "Вызов конструктора " << this << endl;} //Конструктор поумолчанию
    Student(int mark, int date) //Конструктор с параметрами
    {
        cout << "Вызов конструктора с парамеирами " << this << endl;
        this->mark = mark;  //this указывает на поле объекта
        this->date = date;
    }
    ~Student() {cout << "Вызов деструктора " << this << endl;} //Деструктор
*/

private:    //Поля класса
    //int mark, date;
    string surname = "Нет денных"; //Фамилия
    string name = "Нет денных";    //Имя
    string patronymic = "Нет денных";  //Отчество
    string date = "Нет денных";    //Дата рождения
    string address = "Нет денных"; //Адрес
    string phone_number = "Нет денных";    //Номер телефона
    string faculty = "Нет денных"; //Факультет
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
};

#endif // STUDENT_H

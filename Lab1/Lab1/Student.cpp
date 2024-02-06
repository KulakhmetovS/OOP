#include "Student.h"
#include <iomanip>
#include <string>
//Реализация самих методов
void Student::setName(string surname, string name, string patronymic)
{
    //this указывает на поле объекта
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
}

void Student::setContacts(string address, string phone_number, string faculty)
{
    this->address = address;

    if(phone_number.size() == 10)   //Проверка на количество символов
    {
        this->phone_number = phone_number;

        for(int i = 0; i < 10; i++)
        {
            //Проверка на соответствие символа цифре
            if((phone_number[i] < 48) || (phone_number[i] > 57))
            {
                this->phone_number = "Некорректно введённые данные";
            }
        }
    }
    else this->phone_number = "Некорректно введённые данные";

    this->faculty = faculty;
}

void Student::setDateOfBirth(string date)
{
    if(date.size() == 10)   //Проверка на количество символов
    {
        this->date = date;

        for(int i = 0; i < 10; i++)
        {
            //Проверка на соотвествие символа цифре и на правильность формата
            if((date[i] < 46) || (date[i] > 57))
            {
                this->date = "Некорректно введённые данные";
            }
            if((date[2] != 46) || (date[5] !=46)) this->date = "Некорректно введённые данные";
        }
    }
    else this->date = "Некорректно введённые данные";
}

void Student::setCourse(int course)
{
    if((course > 0) && (course < 7))
        this->course = course;
}

int Student::getYear()
{
    string s_year;
    int year = 0;

    for(int i = 0; i < 4; i++)
        s_year[i] = date[i+6];
    //Обработка исключаний
    try
    {
        year = stoi(s_year);    //Если невозможно преобразовать данные в число
    }
    catch(const invalid_argument &e)
    {
        year = 0;
        return year;   //То возвращаем вместо года просто 0 чтобы программа не дампнулась
    }

    return year;    //Если проверка прошла успешно, то возвращается год в виде числа
}

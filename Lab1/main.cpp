#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <Student.h>

using namespace std;

void SetData(Student& student, int index);  //Получение данных от пользователя
//Вывод списка студентов по факультетам
void SortByFaculty(Student *stud_array, string faculty, int size);
//Вывод списков студентов по каждому факультету и курсу
void SortByEachFaculty(Student *stud_array, int size);
//Вывод списка студентов, родившихся после указанного года
void AfterCertainYear(Student *stud_array, int size, int Year);

int main()
{
    /*Переменные строки для работы с функцией getline()
    сама же функция является костылём чтобы читать строки с пробелами*/
    string s_size, s_choice, faculty, s_year;
    int size = 0, i, choice = 0, year = 0;

    cout << "Введите число студентов в списке: ";
    getline(cin, s_size);
    size = stoi(s_size);    //Преобразование строки в число
    Student *stud_array = new Student[size];    //Массив объектов класса Student

    //Заполнение каждого объекта массива данными
    for(i = 0; i < size; i++)
        SetData(stud_array[i], i);

    //Цикл для множественного выполнения операций над массивом объектов
    while(1)
    {
        cout << "Выберите действие ->\n";
        cout << "0 - Выйти из программы\n";
        cout << "1 - Список студентов указанного факультета\n";
        cout << "2 - Список студентов для каждого факультета и курса\n";
        cout << "3 - Список студентов, родившихся после заданного года\n";
        cout << "Номер действия: ";
        getline(cin, s_choice);
        choice = stoi(s_choice);

        if(choice == 0) break;
        else if(choice == 1)
        {
            cout << "Введите название факультета: ";
            getline(cin, faculty);

            SortByFaculty(stud_array, faculty, size);
        }
        else if(choice == 2) SortByEachFaculty(stud_array, size);
        else if(choice == 3)
        {
            cout << "Введите год: ";
            getline(cin, s_year);
            year = stoi(s_year);

            AfterCertainYear(stud_array, size, year);
        }
    }

    delete[] stud_array;
    return 0;
}


void SetData(Student& student, int index)
{
    string surname, name, patronymic, date, address, phone_number, faculty, s_course;
    int course;

    cout << ++index << " Студент" << endl;
    cout << "Введите фамилию: ";
    getline(cin, surname);
    cout << "Введите имя: ";
    getline(cin, name);
    cout << "Введите отчество: ";
    getline(cin, patronymic);

    student.setName(surname, name, patronymic); //Ввод фамилии, имени и отчества

    cout << "Введите дату рождения (дд.мм.гггг): ";
    getline(cin, date);

    student.setDateOfBirth(date);   //Ввод даты рождения

    cout << "Введите адрес: ";
    getline(cin, address);
    cout << "Введите номер телефона: 8";
    getline(cin, phone_number);
    cout << "Введите факультет: ";
    getline(cin, faculty);

    //Ввод контактной информаци: адрес, номер телефона, факультет
    student.setContacts(address, phone_number, faculty);

    cout << "Введите курс: ";
    getline(cin, s_course);
    course = stoi(s_course);

    student.setCourse(course);  //Ввод курса

    cout << endl;
}

void SortByFaculty(Student *stud_array, string faculty, int size)
{
    int count = 0;  //Счётчик для проверки студентов, соответствующих требованиям

    for(int i = 0; i < size; i++)
        if(stud_array[i].getFaculty() == faculty)   //Сравнение поля объекта и заданного факультета
        {
            //Вывод имени и фамилии соответствующего студента
            cout << stud_array[i].getSurname() << " " << stud_array[i].getName() << endl;
            count++;    //Увеличение счётчика, если студент соответствует факультету
        }

    if(count == 0)  //Вывод предупреждения, если соответствующих студентов не найдено
    {
    cout << "Студенты данного факультета отсутствуют в списке\n" << \
    "(Или неправильно введено название факультета!)"<< endl;
    }
}

void SortByEachFaculty(Student *stud_array, int size)
{
    //visited_courses - массив для пометки уже указанного курса
    int i, j, *visited_courses = new int[size], int_cmp;
    vector<string> list;    //Вектор, хранящий названия факультетов
    vector<int> Courses;    //Вектор, хранящий курсы студентов
    string *visited_str = new string[size], cmp;    //Массив для пометки уже указанного факультета

    //Запись названий факультетов в массив
    for(i = 0; i < size; i++)
        visited_str[i] = stud_array[i].getFaculty();

    //Составление списка факультетов при помощи вектора
    for(j = 0; j < size; j++)
    {
        if(visited_str[j] != "null")    //Если факультет ещё не помечен
        {
        cmp = visited_str[j];   //Сохранение названия факультета для дальнейшего сравнения
        list.push_back(cmp);    //Помещение названия факультета в вектор

        //Если факультет уже посещён, то заменить все аналогичные факультеты строкой "null"
        for(i = 0; i < size; i++)
            if(visited_str[i] == cmp) visited_str[i] = "null";
        }
    }

    for(i = 0; i < list.size(); i++)    //Киличество итераций цикла равно числу элементов вектора
    {
        cout << "Список студентов факультета " << list[i] << endl;

        //Вывод списков студентов по факультетам
        for(j = 0; j < size; j++)
            if(stud_array[j].getFaculty() == list[i])   //Если поле объекта соответствует текущему факультету
                cout << stud_array[j].getSurname() << " " << stud_array[j].getName() << endl;
    }
    cout << "\n";

    delete[] visited_str;   //Удаление использованного массива


    //Составление списка студентов по курсам аналогичено составлению списка по факультетам
    for(i = 0; i < size; i++)
        visited_courses[i] = stud_array[i].getCourse();

    for(j = 0; j < size; j++)
    {
        if(visited_courses[j] != 0)
        {
        int_cmp = visited_courses[j];
        Courses.push_back(int_cmp);

        for(i = 0; i < size; i++)
            if(visited_courses[i] == int_cmp) visited_courses[i] = 0;
        }
    }

    for(i = 0; i < Courses.size(); i++)
    {
        cout << "Список студентов " << Courses[i] << " курса"   << endl;

        for(j = 0; j < size; j++)
            if(stud_array[j].getCourse() == Courses[i])
                cout << stud_array[j].getSurname() << " " << stud_array[j].getName() << endl;
    }

    delete[] visited_courses;
}

void AfterCertainYear(Student *stud_array, int size, int Year)
{
    for(int i = 0; i < size; i++)
        if(stud_array[i].getYear() > Year)
            cout << stud_array[i].getSurname() << " " << stud_array[i].getName() << endl;
}

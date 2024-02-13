#include "Observer.h"

void Observer::GetInfo(Student& other)
{
    cout << other.surname << " " << other.name << " " << other.patronymic << " "\
    << other.date << " " << other.address << " 8" << other.phone_number << " "\
    << other.faculty << " " << other.course << endl;
}

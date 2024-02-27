#include "Vehicle.h"

void Vehicle::SetPrise(int price)
{
    if (price >= 0) this->price = price;
}

void Vehicle::SetSpeed(int speed)
{
    if (speed >= 0) this->speed = speed;
}

void Vehicle::SetYear(int year)
{
    if ((year > 1900) && (year < 2025)) year_of_issue = year;
}

void Vehicle::SetX(int x_coord)
{
    this->x_coord = x_coord;
}

void Vehicle::SetY(int y_coord)
{
    this->y_coord = y_coord;
}

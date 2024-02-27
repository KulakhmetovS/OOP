#include <iostream>
#include "Car.h"
#include "Plane.h"
#include "Ship.h"


using namespace std;

int main()
{
    int price, speed, year, x, y, number, high;
    string port;

    Car car;
    Plane plane;
    Ship ship;

    cout << "Заполните информацию ою объектах" << endl;

    cout << endl << "Самолёт" << endl;
    cout << "Введите цену (рубли): ";
    cin >> price;
    cout << "Введите скорость (км/ч): ";
    cin >> speed;
    cout << "Введите год выпуска: ";
    cin >> year;
    cout << "Введите координату х: ";
    cin >> x;
    cout << "Введите координату у: ";
    cin >> y;
    cout << "Введите высоту (метры): ";
    cin >> high;

    plane.SetPrise(price);
    plane.SetSpeed(speed);
    plane.SetYear(year);
    plane.SetX(x);
    plane.SetY(y);
    plane.SetHigh(high);


    cout << endl << "Машина" << endl;
    cout << "Введите цену (рубли): ";
    cin >> price;
    cout << "Введите скорость (км/ч): ";
    cin >> speed;
    cout << "Введите год выпуска: ";
    cin >> year;
    cout << "Введите координату х: ";
    cin >> x;
    cout << "Введите координату у: ";
    cin >> y;
    cout << "Введите число пассажиров: ";
    cin >> number;

    car.SetPrise(price);
    car.SetSpeed(speed);
    car.SetYear(year);
    car.SetX(x);
    car.SetY(y);
    car.SetNumber(number);


    cout << endl << "Корабль" << endl;
    cout << "Введите цену (рубли): ";
    cin >> price;
    cout << "Введите скорость (км/ч): ";
    cin >> speed;
    cout << "Введите год выпуска: ";
    cin >> year;
    cout << "Введите координату х: ";
    cin >> x;
    cout << "Введите координату у: ";
    cin >> y;
    cout << "Введите число пассажиров: ";
    cin >> number;
    cout << "Введите порт, к которому прикреплено судно: ";
    cin >> port;

    ship.SetPrise(price);
    ship.SetSpeed(speed);
    ship.SetYear(year);
    ship.SetX(x);
    ship.SetY(y);
    ship.SetNumber(number);
    ship.SetPort(port);

    cout << endl << "Самолёт" << endl;
    cout << plane.GetPrice() << " " << plane.GetSpeed() << " " << plane.GetYear() \
    << " " << plane.GetX() << " " << plane.GetY() << " " << plane.GetHigh();

    cout << endl << "Машина" << endl;
    cout << car.GetPrice() << " " << car.GetSpeed() << " " << car.GetYear() \
    << " " << car.GetX() << " " << car.GetY() << " " << car.GetNumbet();

    cout << endl << "Корабль" << endl;
    cout << ship.GetPrice() << " " << ship.GetSpeed() << " " << ship.GetYear() \
    << " " << ship.GetX() << " " << ship.GetY() << " " << ship.GetNumbet() << " " << ship.GetPort();

    return 0;
}

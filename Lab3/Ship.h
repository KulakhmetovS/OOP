#ifndef SHIP_H
#define SHIP_H
#include "Car.h"
#include <iostream>

using namespace std;

class Ship : public Car
{
    private:
        string port = "Порт не определён";

    public:
        void SetPort(string port);

        string GetPort() {return port;}
};

#endif // SHIP_H

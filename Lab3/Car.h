#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle  //Объявление и наследование от Vehicle
{
    private:
        int number = 0;

    public:
        void SetNumber(int number);

        int GetNumbet() {return number;}
};

#endif // CAR_H

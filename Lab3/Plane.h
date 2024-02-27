#ifndef PLANE_H
#define PLANE_H
#include "Vehicle.h"


class Plane : public Vehicle
{
    private:
        int high = 0;

    public:
        void SetHigh(int high);

        int GetHigh() {return high;}
};

#endif // PLANE_H

#ifndef VEHICLE_H
#define VEHICLE_H


class Vehicle
{
    protected:
        int price = 0;
        int speed = 0;
        int year_of_issue = 0;
        int x_coord = 0;
        int y_coord = 0;

    public:
        void SetPrise(int price);
        void SetSpeed(int speed);
        void SetYear(int year);
        void SetX(int x_coord);
        void SetY(int y_coord);

        int GetPrice() {return price;}
        int GetSpeed() {return speed;}
        int GetYear() {return year_of_issue;}
        int GetX() {return x_coord;}
        int GetY() {return y_coord;}
};

#endif // VEHICLE_H

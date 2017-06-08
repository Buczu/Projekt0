#include "stadion.h"
#include <iostream>
#include <iomanip>

stadium::stadium(std::string name, int x, int y)
    :boisko(name, x,y)
{
    addName(name);
    numOfSeats=0;
    trainPrice=10.0;
    revenue=0;
    trainPriceSet=false;
    isThereBoisko=false;
    stadiumBuilt=false;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
            timetable[i][j]='-';
    }
}

void stadium::setTrainPrice(double x)
{
    trainPrice=x;
    trainPriceSet=true;
}

std::ostream& operator<<(std::ostream& os, stadium& stadion)
{
    int tmpH;
    tmpH=8;
    os<<"Nazwa: "<< stadion.getName() << std::endl;
    os<<"Ilosc miejsc: "<<stadion.numOfSeats<<std::endl;
    os<<"Dochod: "<<stadion.revenue<<std::endl;
    os << " Timetable Mo Tu We Th Fr Sa Su"<<std::endl;
    for(int i=0; i<7; i++)
    {
        os<<std::setw(2) << tmpH <<":00-";
        tmpH+=2;
        os << tmpH <<":00 ";
        for(int j=0; j<7; j++)
        {
            os<< stadion.timetable[i][j] << "  ";
        }
        os << std::endl;
    }
    os << std::endl;

    return os;
}

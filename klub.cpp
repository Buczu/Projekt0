#include "klub.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>

club::club(std::string name1, std::string city,std::string name, int x, int y)
    :teren(name, x, y)
{
    homeCity=city;
    numOfFans=0;
    estYear=0;
    daysToTrain=0;
    trainP=0;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
            trainingTime[i][j]='-';
    }
}

std::ostream& operator<<(std::ostream& os, club& klub)
{
    int tmpH;
        tmpH=8;
        os<<"        Name         City Year Pl     Budget"<<std::endl;
        os<<std::setw(12)<<klub.getName()<<" "<<std::setw(12)<<klub.homeCity<<" "<<std::setw(4)<<klub.estYear<<" "<<std::setw(10)<<klub.budget;
        os<<std::endl;
        os << " Timetable Mo Tu We Th Fr Sa Su"<<std::endl;
        for(int i=0; i<7; i++)
        {
            os<<std::setw(2) << tmpH <<":00-";
            tmpH+=2;
            os << tmpH <<":00 ";
            for(int j=0; j<7; j++)
            {
                os<< klub.trainingTime[i][j] << "  ";
            }
            os << std::endl;
        }
    os << std::endl;
    return os;
}

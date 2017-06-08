#ifndef KLUB_H
#define KLUB_H

#include "teren.h"

class club:public teren
{
public:
    int trainP;
    double budget;
    std::string homeCity;
    int numOfFans; //ilosc kibicow
    int estYear; // rok zalozenia
    char trainingTime[7][7]; // rozklad treningu
    int daysToTrain; // ilosc treningow w tygodniu

    club(std::string="none", std::string="none",std::string="none", int=0, int=0);
    friend std::ostream& operator<<(std::ostream&, club &);
};
#endif

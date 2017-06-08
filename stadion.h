#ifndef STADION_H
#define STADION_H

#include "boisko.h"
class stadium: public boisko
{
public:
    double revenue;
    double trainPrice; //cena 1 2h treningu
    int numOfSeats; //ilosc siedzen
    bool trainPriceSet;
    bool isThereBoisko;
    bool stadiumBuilt;
    void setTrainPrice(double x);
    stadium(std::string="none", int=0, int=0);
    friend std::ostream& operator<<(std::ostream&, stadium &);
};
#endif

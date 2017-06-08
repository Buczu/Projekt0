#ifndef BOISKO_H
#define BOISKO_H

#include "teren.h"

class boisko: public teren
{
public:
    bool stadiumCovered, fieldInfoSet; //Is the field covered with covering
    char timetable[7][7];
    std::string pokrycie;
    boisko(std::string="none", int=0, int=0);
    friend std::ostream& operator<<(std::ostream&, boisko &);
};
#endif

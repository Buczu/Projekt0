#include<iostream>
#include "boisko.h"


boisko::boisko(std::string name, int x, int y)
    :teren(name, x, y)
{
    stadiumCovered=false;
    fieldInfoSet=false;
    addArea(0);
}

std::ostream& operator<<(std::ostream& os, boisko& field)
{
    os<<"Nazwa: "<< field.getName() << std::endl;
    os<<"Wymiary: " << field.dlugosc <<"x"<<field.szerokosc << std::endl;
    os<<"Pole: " << field.getArea() << std::endl;
    if(field.stadiumCovered) os<<"Pokrycie: " << field.pokrycie << std::endl;
    return os;
}

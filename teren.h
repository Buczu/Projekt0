#ifndef TEREN_H
#define TEREN_H


#include <string>

class teren
{
    std::string nazwa; //nazwa terenu
    int powierzchnia;
public:

    int dlugosc;
    int szerokosc;
    teren(std::string name, int x, int y);
    virtual std::string getName()
    {
        return nazwa;
    }
    virtual void addName(std::string x)
    {
        nazwa=x;
    }
    virtual void addArea(int x)
    {
        powierzchnia=x;
    }
    virtual int getArea()
    {
        return powierzchnia;
    }
};

#endif

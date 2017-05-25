#ifndef AMU_PARK_H
#define AMU_PARK_H

#include "Ent_Park.h"

class Amu_Park :public Ent_Park
{
protected:
    int workers;
    int attractions;

public:
    //CONSTRUCTOR AND DESCRUCTOR
    Amu_Park( int=50 ,int=5,int=1000, int=500, int=10, int=500,int=5);
    ~Amu_Park(){};

    //POLYMORPHIC METHODS INHERITATED FROM ENT_PARK
    virtual void accept_visitors();
    virtual void show_type(){std::cout<<"Amusement Park"<<std::endl;}
    virtual char show_attractions();
    virtual void show_attraction(char);
    virtual bool check_resources(char, int);
    virtual void buy_attraction(char, int);
    virtual void manage_menu();// show management options that can be used on chosen facility
    virtual void show_data();// show variables of chosen facility


    //MANAGING
    void buy_workers(int i){workers+=i;budget-=i*250;}

    //OPERATORS
    friend std::ostream& operator<<(std::ostream&,const Amu_Park &);//showing all variables

};












#endif // AMU_PARK_H


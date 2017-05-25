#ifndef ENT_PARK_H
#define ENT_PARK_H

#include <iostream>
#include <cstdlib>
#include <time.h>
class Ent_Park
{
protected:
    int area;
    int budget;
    int tic_cost;
    int slots;
    int popularity;


public:
    //CONSTRUCTOR AND DESCRUCTOR
    Ent_Park(int=1000, int=500, int=10, int=500,int=5);
    virtual ~Ent_Park(){}

    //GETTERS
    int get_pop(){return popularity;}
    int get_slots(){return slots;}
    int get_cost(){return tic_cost;}
    int get_budget(){return budget;}

    //MANAGING
    void buy_area(int i){area+=i;budget-=i*20;}
    void buy_slots(int i){slots+=i;budget-=i*150;}

    //POLYMORPHIC FUNCTIONS
    virtual void accept_visitors()=0;
    virtual void show_type()=0; // show type of the facility and their budget
    virtual char show_attractions()=0;
    virtual void show_attraction(char)=0;
    virtual bool check_resources(char, int)=0;
    virtual void buy_attraction(char, int)=0;
    virtual void manage_menu(); // show management options that can be used on chosen facility
    virtual void show_data();   // show variables of chosen facility

};



#endif // ENT_PARK_H

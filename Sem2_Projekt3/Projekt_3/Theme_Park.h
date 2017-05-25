#ifndef THEME_PARK_H
#define THEME_PARK_H
#include "Amu_Park.h"

class Theme_Park :public Amu_Park
{
private:
    std::string theme;
    bool mascot;
public:
    //CONSTRUCTOR AND DESCRUCTOR
    Theme_Park(std::string="none",bool=0,int=1000, int=500, int=10, int=500,int=5, int=50 ,int=5);
    ~Theme_Park(){}

    //GETTERS
    std::string get_theme(){return theme;}
    bool get_mascot(){return mascot;}

    //MANAGING
    void buy_mascot(){budget-=150000;mascot=1;popularity+=5;}

    //POLYMORPHIC METHODS INHERITATED FROM ENT_PARK
    virtual void accept_visitors();
    virtual void show_type(){std::cout<<"Thematic Park"<<std::endl;}
    virtual char show_attractions();
    virtual void show_attraction(char);
    virtual bool check_resources(char, int);
    virtual void buy_attraction(char, int);
    virtual void manage_menu();// show management options that can be used on chosen facility
    virtual void show_data();// show variables of chosen facility

    //OPERATORS
    friend std::ostream& operator<<(std::ostream&,const Theme_Park &);
};




#endif // THEME_PARK_H


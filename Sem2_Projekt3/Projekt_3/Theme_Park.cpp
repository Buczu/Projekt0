#include "Theme_Park.h"
#include "Managment.h"

//~~~~~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~
Theme_Park::Theme_Park(std::string thm,bool msc,int ar, int bgt, int tic, int sls, int pop, int work ,int atr)
:Amu_Park(work,atr,ar,bgt,tic,sls,pop)
{
    theme=thm;
    mascot=msc;
}

//~~~~~~~POLYMORPHIC METHODS INHERITATED FROM ENT_PARK~~~~
void Theme_Park::accept_visitors()
{
    int refused,earned,mascot_bonus=0;

    int visitors=rand()%101 +popularity*50;//100 default +50 for each popularity point

    clean();

    refused=visitors-slots;
    if(refused>0) visitors-=refused;

    earned=visitors*tic_cost;

    if(mascot==1)  mascot_bonus=rand()%101;//if user has mascot generate random number from 0 to 100

    if(mascot_bonus<50) mascot_bonus=0;//if generated number is less than 50 then user gets no bonus

    else if(mascot_bonus<99)//if generated number is between <50,99> user gets 10% bonus
    {
        mascot_bonus=earned/10;
        std::cout<<"Your mascot earned You 10% extra!"<<std::endl
        <<"extra earnings: "<<mascot_bonus<<std::endl;
    }

    else//if generated number is 100 user gets 50% bonus
    {
        mascot_bonus=earned/2;
        std::cout<<"SPECIAL: Your mascot earned You 50% extra!!!"<<std::endl
        <<"extra earnings: "<<mascot_bonus<<std::endl;
    }

    earned+=mascot_bonus;
    budget+=earned;

    sum_up_screen(refused, earned);
}

char Theme_Park::show_attractions()
{
    if(theme=="Medival")//MEDIVAL PARK HAS DIFFERENT ATTRACTIONS THAN FAMILIAL
    {

        std::cout<<"    |              COST              |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<" NR |   MONEY   |  WORKERS  |  AREA  | POPULARITY |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  1 |  17,500   |     30    |  750   |     1      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  2 |  38,000   |     40    | 2,225  |     2      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  3 |  47,000   |     33    | 1,800  |     2      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  4 |  70,000   |     75    | 3,500  |     4      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  5 | 120,750   |    200    | 8,000  |     8      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  6 | 180,250   |    150    | 5,000  |     8      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  7 | 200,000   |    180    | 6,000  |     10     |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  0 EXIT "<<std::endl;

        return '7';
    }

    else
    {
        std::cout<<"    |              COST              |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<" NR |   MONEY   |  WORKERS  |  AREA  | POPULARITY |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  1 |  17,500   |     30    |  750   |     1      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  2 |  40,000   |     45    | 2,500  |     2      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  3 |  50,000   |     35    | 2,000  |     2      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  4 |  75,000   |     80    | 4,000  |     4      |"<<std::endl
        <<"---------------------------------------------------"<<std::endl
        <<"  0 EXIT "<<std::endl;

        return '4';
    }
}

void Theme_Park::show_attraction(char nr)
{
    std::cout<<"    |              COST              |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<" NR |   MONEY   |  WORKERS  |  AREA  | POPULARITY |"<<std::endl
    <<"---------------------------------------------------"<<std::endl;

    if(theme=="Medival")
        switch(nr)//matching attraction to user's choice
        {
            case '1': {std::cout<<"  1 |  17,500   |     30    |  750   |     1      |"<<std::endl; break;}
            case '2': {std::cout<<"  2 |  38,000   |     40    | 2,225  |     2      |"<<std::endl; break;}
            case '3': {std::cout<<"  3 |  47,000   |     33    | 1,800  |     2      |"<<std::endl; break;}
            case '4': {std::cout<<"  4 |  70,000   |     75    | 3,500  |     4      |"<<std::endl; break;}
            case '5': {std::cout<<"  5 | 120,750   |    200    | 8,000  |     8      |"<<std::endl; break;}
            case '6': {std::cout<<"  6 | 180,250   |    150    | 5,000  |     8      |"<<std::endl; break;}
            case '7': {std::cout<<"  7 | 200,000   |    180    | 6,000  |     10     |"<<std::endl; break;}
        }

    else
    {
        switch(nr)
        {
            case '1': {std::cout<<"  1 |  17,500   |     30    |  750   |     1      |"<<std::endl; break;}
            case '2': {std::cout<<"  2 |  40,000   |     45    | 2,500  |     2      |"<<std::endl; break;}
            case '3': {std::cout<<"  3 |  50,000   |     35    | 2,000  |     2      |"<<std::endl; break;}
            case '4': {std::cout<<"  4 |  75,000   |     80    | 4,000  |     4      |"<<std::endl; break;}
        }
    }

}

bool Theme_Park::check_resources(char selected, int number)
{

    int money, wor, are;
    bool not_enough;
    if(theme=="Medival")
    {
        switch(selected)//matching costs to attraction bought by user
        {
            case '1':{ money=17500;  wor=30;  are=750;  break; }
            case '2':{ money=38000;  wor=40;  are=2225; break; }
            case '3':{ money=47000;  wor=33;  are=1800; break; }
            case '4':{ money=70000;  wor=75;  are=3500; break; }
            case '5':{ money=120750; wor=200; are=8000; break; }
            case '6':{ money=180250; wor=150; are=5000; break; }
            case '7':{ money=200000; wor=180; are=6000; break; }
        }
    }
    else
    {
        switch(selected)
        {
            case '1':{ money=17500; wor=30;  are=750;  break; }
            case '2':{ money=40000; wor=45;  are=2500; break; }
            case '3':{ money=50000; wor=35;  are=2000; break; }
            case '4':{ money=75000; wor=80;  are=4000; break; }
        }
    }

    if(budget< money*number) {std::cout<<"Not enough money" <<std::endl; not_enough=1;}
    if(workers< wor*number)  {std::cout<<"Not enough workers" <<std::endl; not_enough=1;}
    if(area< are*number)     {std::cout<<"Not enough area" <<std::endl; not_enough=1; }

    if(not_enough==1) return 0;
    else
    {
        std::cout<<"CURRENT:"<<std::endl<<"Budget: "<<budget<<std::endl<<"Workers: "<<workers<<std::endl
        <<"Area: "<<area<<std::endl<<std::endl;

        std::cout<<"AFTER PURCHASE:"<<std::endl<<"Budget: "<<budget-money*number<<std::endl<<"Workers: "<<workers-wor*number<<std::endl
        <<"Area: "<<area-are*number<<std::endl;

        return 1;
    }
}

void Theme_Park::buy_attraction(char selected, int number)
{
    int money, wor, are,pop;

    if(theme=="Medival")
    {
        switch(selected)//matching costs to user's choice
        {
            case '1':{ money=17500;  wor=30;  are=750;  pop=1;  break; }
            case '2':{ money=38000;  wor=40;  are=2225; pop=2;  break; }
            case '3':{ money=47000;  wor=33;  are=1800; pop=2;  break; }
            case '4':{ money=70000;  wor=75;  are=3500; pop=4;  break; }
            case '5':{ money=120750; wor=200; are=8000; pop=8;  break; }
            case '6':{ money=180250; wor=150; are=5000; pop=8;  break; }
            case '7':{ money=200000; wor=180; are=6000; pop=10; break; }
        }
    }
    else
    {
        switch(selected)
        {
            case '1':{ money=17500; wor=30;  are=750;  pop=1; break; }
            case '2':{ money=40000; wor=45;  are=2500; pop=2; break; }
            case '3':{ money=50000; wor=35;  are=2000; pop=2; break; }
            case '4':{ money=75000; wor=80;  are=4000; pop=4; break; }
        }
    }

    budget-=money*number;
    workers-=wor*number;
    area-=are*number;
    popularity+=pop*number;
    attractions+=number;
}

void Theme_Park::manage_menu()
{
    Amu_Park::manage_menu();
    if(mascot==0) std::cout<<"[5] Buy mascot"<<std::endl;
}

void Theme_Park::show_data()
{
    std::string has_mascot;
    has_mascot = mascot==1 ? "yes" : "no";

    std::cout<<"Theme: "<< theme<< std::endl
    <<"Mascot: "<<has_mascot<< std::endl;
    Amu_Park::show_data();
}

//~~~~~~~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~~~~~
std::ostream& operator<<(std::ostream& os,const Theme_Park &theme_p)
{

    os<<"Theme: "<< theme_p.theme<< std::endl
    <<"Mascot: "<< theme_p.mascot<< std::endl
    <<"Jobless Workers: "<<theme_p.workers<<std::endl
    <<"Number of Attractions: "<<theme_p.attractions<<std::endl
    <<"Area to use: "<<theme_p.area << std::endl
    <<"Budget: "<< theme_p.budget<< std::endl
    <<"Tic_cost: "<< theme_p.tic_cost<< std::endl
    <<"Slots: "<< theme_p.slots<< std::endl
    <<"Popularity: "<<theme_p.popularity<< std::endl;

    return os;
}

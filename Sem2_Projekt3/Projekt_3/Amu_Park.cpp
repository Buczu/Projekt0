#include "Amu_Park.h"
#include "Managment.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~ÆONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Amu_Park::Amu_Park(int work ,int atr,int ar, int bgt, int tic, int sls, int pop)
:Ent_Park(ar,bgt,tic,sls,pop)
{
    workers=work;
    attractions=atr;
}

//~~~~~~~~POLIMORFIC METHODS INHERITATED FROM ENT_PARK~~~~~~~~~~
void Amu_Park::accept_visitors()
{
    int refused,earned;
    int visitors=rand()%101 + popularity*50;//200 default+100*each popularity point

    clean();

    refused=visitors-slots;
    if(refused>0) visitors-=refused;

    earned=visitors*tic_cost;
    budget+=earned;

    sum_up_screen(refused,earned);//showing result(visitors refused,money earned)
}

char Amu_Park::show_attractions()
{
    std::cout<<"    |              COST              |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<" NR |   MONEY   |  WORKERS  |  AREA  | POPULARITY |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<"  1 |  15,000   |     30    |  750   |     1      |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<"  2 |  28,000   |     70    | 1,200  |     2      |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<"  3 |  80,500   |     80    | 3,000  |     4      |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<"  4 | 120,750   |    200    | 8,000  |     8      |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<"  5 | 180,250   |    150    | 5,000  |     8      |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<"  0 EXIT "<<std::endl;

    return '5';
}

void Amu_Park::show_attraction(char nr)
{
    std::cout<<"    |              COST              |"<<std::endl
    <<"---------------------------------------------------"<<std::endl
    <<" NR |   MONEY   |  WORKERS  |  AREA  | POPULARITY |"<<std::endl
    <<"---------------------------------------------------"<<std::endl;

    switch(nr)
    {
        case '1': {std::cout<<"  1 |  15,000   |     30    |  750   |     1      |"<<std::endl; break;}
        case '2': {std::cout<<"  2 |  28,000   |     70    | 1,200  |     2      |"<<std::endl; break;}
        case '3': {std::cout<<"  3 |  80,500   |     80    | 3,000  |     4      |"<<std::endl; break;}
        case '4': {std::cout<<"  4 | 180,250   |    150    | 5,000  |     8      |"<<std::endl; break;}
        case '5': {std::cout<<"  5 | 120,750   |    200    | 8,000  |     8      |"<<std::endl; break;}
    }
}

bool Amu_Park::check_resources(char selected, int number)
{
    int money, wor, are;
    bool not_enough;
    switch(selected)
    {
        case '1':{ money=15000;  wor=30;  are=750;  break; }
        case '2':{ money=28000;  wor=70;  are=1200; break; }
        case '3':{ money=80500;  wor=80;  are=3000; break; }
        case '4':{ money=180250; wor=150; are=5000; break; }
        case '5':{ money=120750; wor=200; are=8000; break; }
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

void Amu_Park::buy_attraction(char selected, int number)
{
    int money, wor, are,pop;
    switch(selected)
    {
        case '1':{ money=15000;  wor=30;  are=750;  pop=1; break; }
        case '2':{ money=28000;  wor=70;  are=1200; pop=2; break; }
        case '3':{ money=80500;  wor=80;  are=3000; pop=4; break; }
        case '4':{ money=180250; wor=150; are=5000; pop=8; break; }
        case '5':{ money=120750; wor=200; are=8000; pop=8; break; }
    }
    budget-=money*number;
    workers-=wor*number;
    area-=are*number;
    popularity+=pop*number;
    attractions+=number;
}

void Amu_Park::manage_menu()
{
    Ent_Park::manage_menu();
    std::cout<<"[4] Hire workers" <<std::endl;
}

void Amu_Park::show_data()
{
    std::cout<<"Jobless Workers: "<<workers<<std::endl
    <<"Number of Attractions: "<<attractions<<std::endl;
    Ent_Park::show_data();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~~~~~~~~~
std::ostream& operator<<(std::ostream& os,const Amu_Park & amu_p)
{
    os<<"Jobless Workers: "<<amu_p.workers<<std::endl
    <<"Number of Attractions: "<<amu_p.attractions<<std::endl
    <<"Area to use: "<<amu_p.area << std::endl
    <<"Budget: "<< amu_p.budget<< std::endl
    <<"Tic_cost: "<< amu_p.tic_cost<< std::endl
    <<"Slots: "<< amu_p.slots<< std::endl
    <<"Popularity: "<<amu_p.popularity<< std::endl;

    return os;
}

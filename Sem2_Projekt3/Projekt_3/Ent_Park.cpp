#include "Ent_Park.h"

//~~~~~~~~~~~~~~~~~~~~CONSTRUCTOR~~~~~~~~~~~~~~~~~~~~~~~~
Ent_Park::Ent_Park(int ar, int bgt, int tic, int sls, int pop)
{
    area=ar;
    budget=bgt;
    tic_cost=tic;
    slots=sls;
    popularity=pop;
}

//~~~~~~~~~~~~~~~~~~POLIMORFIC METHODS~~~~~~~~~~~~~~~~~~
void Ent_Park::manage_menu()
{
    std::cout<<std::endl<<"[1] Buy attractions" <<std::endl
    <<"[2] Increase Area" <<std::endl
    <<"[3] Build more slots" <<std::endl;
}

void Ent_Park::show_data()
{
    std::cout<<"Area to use: "<<area << std::endl
    <<"Tic_cost: "<< tic_cost<< std::endl
    <<"Slots: "<< slots<< std::endl
    <<"Popularity: "<<popularity<< std::endl
    <<"Budget: "<< budget<< std::endl;
}

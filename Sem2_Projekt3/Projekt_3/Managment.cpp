#include "Managment.h"

//~~~~~~~~~~~~~~~~~~~~~~OTHERS~~~~~~~~~~~~~~~~~~
void clean()// clearing screen compiling both on Linux and Windows
{
    #ifdef _DEBUG
    std::cout<<"Debug mode Screen cleaning deactivated"<<std::endl;
    #elif __linux__
    system("clear");
    #elif _WIN32
    system("cls");
    #else
    #error "OS not supported!"
    #endif
}

void sum_up_screen(int refused, int earned)
{
        std::cout<<"Sum up of the day:"<<std::endl<<std::endl;
        std::cout<<"Money earned: "<<earned<<std::endl;
        std::cout<<"Visitors refused due to no slots: "<<refused<<std::endl<<std::endl;
}

//~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~
char start_up()
{
    char decision;
    do
    {
        clean();
        std::cout << "What do You want to do? "<< std::endl<<std::endl;
        std::cout << "[1] Create Thematic Park "<< std::endl;
        std::cout << "[2] Create Amusement Park "<< std::endl;
        std::cout << "[3] Create Zoo "<< std::endl<<std::endl;
        std::cout << "[0] Exit"<< std::endl;
        std::cin >> decision;

    }while(decision<'0'|| decision>'3' );

    return decision;
}

facility switching(state st,facility current)
{
    char decision='0';
    switch(st)
    {
        case zoo: case amu:case theme: //user has only 1 facility, he can't switch into another
        {
            while(decision!='1')
            {
                clean();
                std::cout <<"You only got one manor!"<<std::endl;
                std::cout <<"[1] Ok"<<std::endl;
                std::cin>>decision;
            }
            return current;
        }

        case zoo_amu:   {return current==z ? a :  z; }//user has 2 facilities,
        case zoo_theme: {return current==z ?  t :  z;}//program switches
        case amu_theme: {return current==t ?  a :  t;}//from current to another

        case zoo_amu_theme://user has 3 facilities, program switches:
        {                  //zoo->amusement_park;  amusement_park->thematic_park;  thematic_park->zoo
            return current==z ? a : (current==a ? t : z);
        }
    }
    return a;
}

bool choose_theme()
{
    char decision='0';

    while(decision<'1' || decision >'2')
    {
        clean();
        std::cout<<"Choose theme: "<<std::endl;
        std::cout<<"[1] Medival  (Hard start, easier to develop)" <<std::endl;
        std::cout<<"[2] Familial (Easy start, harder to develop)" <<std::endl;

        std::cin >> decision;
    }
    switch(decision)
    {
        case '1': return 0;

        case '2': return 1;

    }
    return 0;
}

char create_new(state &st)
{
    char decision='0';
    switch(st)
    {
        case zoo_amu_theme://User has 3 facilities, he can't create new
        {
            while(decision!='1')
            {
                clean();
                std::cout <<"You already got three manors!"<<std::endl;
                std::cout <<"[1] Ok"<<std::endl;
                std::cin>>decision;
            }
            return '0';
        }

        case zoo_amu://User has zoo and amusement park, he can only create thematic park
        {
            while(true)
            {
                clean();
                std::cout <<"[1]Create Thematic Park"<<std::endl<<std::endl;
                std::cout <<"[0] Back to menu"<<std::endl;
                std::cin>>decision;
                if(decision=='1') {st=zoo_amu_theme;return '1';}
                if(decision=='0') return '0';
            }
        }

        case zoo_theme://User has zoo and thematic park, he can only create amusement park
        {
            while(true)
            {
                clean();
                std::cout <<"[1]Create amusement Park"<<std::endl<<std::endl;
                std::cout <<"[0] Back to menu"<<std::endl;
                std::cin>>decision;
                if(decision=='1') {st=zoo_amu_theme;return '2';}
                if(decision=='0') return '0';
            }
        }

        case amu_theme://User has amusement and thematic park, he can only create zoo
        {
            while(true)
            {
                clean();
                std::cout <<"[1] Create Zoo"<<std::endl<<std::endl;
                std::cout <<"[0] Back to menu"<<std::endl;
                std::cin>>decision;
                if(decision=='1') {st=zoo_amu_theme;return '3';}
                if(decision=='0') return '0';
            }
        }

        case zoo://User has zoo he can create Thematic or Amusement Park
        {
            while(true)
            {
                clean();
                std::cout <<"[1] Create Thematic Park"<<std::endl;
                std::cout <<"[2] Create Amusement Park"<<std::endl<<std::endl;
                std::cout <<"[0] Back to menu"<<std::endl;
                std::cin>>decision;
                if(decision=='1') {st=zoo_theme;return '1';}
                if(decision=='2') {st=zoo_amu;return '2';}
                if(decision=='0') return '0';
            }
        }

        case amu://User has Amusement Park he can create Thematic Park or Zoo
        {

            while(true)
            {
                clean();
                std::cout <<"[1] Create Thematic Park"<<std::endl;
                std::cout <<"[2] Create Zoo"<<std::endl<<std::endl;
                std::cout <<"[0] Back to menu"<<std::endl;
                std::cin>>decision;
                if(decision=='1') {st=amu_theme;return '1';}
                if(decision=='2') {st=zoo_amu;return '3';}
                if(decision=='0') return '0';
            }
        }

        case theme://User has Thematic Park he can create Amusement Park or Zoo
        {

            while(true)
            {
                clean();
                std::cout <<"[1] Create Amusement Park"<<std::endl;
                std::cout <<"[2] Create Zoo"<<std::endl<<std::endl;
                std::cout <<"[0] Back to menu"<<std::endl;
                std::cin>>decision;
                if(decision=='1') {st=amu_theme;return '2';}
                if(decision=='2') {st=zoo_theme;return '3';}
                if(decision=='0') return '0';
            }
        }
    }
    return '0';
}

void manage(Ent_Park *on_use,facility current)
{
    char decision;
    //int budget=on_use->get_budget();
    while(true)
    {

        clean();
        on_use->show_type();//showing which facility is chosen
        std::cout<<std::endl<<"Data: "<<std::endl;
        on_use->show_data();//showing data of chosen facility
        on_use->manage_menu();//showing managment options of chosen facility
        std::cout<<std::endl<<"[0] Back to menu"<<std::endl;

        std::cin>>decision;

        switch(decision)
        {
            case '1':
            {
                buying_attractions(on_use,current);
                break;
            }

            case '2':case '3':case '4':
            {
                buying_resources(on_use,decision);
                break;
            }

            case '5'://WORKING ONLY FOR THEMATIC PARK
            {
                if(current==t)
                {
                    Theme_Park *temp=dynamic_cast<Theme_Park*>(on_use);

                    if(temp->get_mascot()==0)  buying_mascot(temp);//starting buying_mascot method
                                                                   //only if park doesn't have a mascot
                }
                break;
            }

            case '0': return;
        }

    }
}

//~~~~~~~~~~~~~~~~~~~~~MANAGE~~~~~~~~~~~~~~~~~~~~~~
void buying_resources(Ent_Park* on_use, char decision)
{
    int bought=0;
    int cost=0;
    int budget=on_use->get_budget();
    std::string value="\0" ;

    switch(decision)//checking which resource user chose,and adjusting cost to it
    {
        case '2':{cost=20;value="area";break;}
        case '3':{cost=150;value="slots";break;}
        case '4':{cost=250;value="workers";break;}
    }

    do//asking user to input number of resources he wants to buy
    {
        clean();
        if(std::cin.fail() || bought<0) std::cout<<"You must enter positive number!"<<std::endl<<std::endl;

        std::cout<<value<<" cost: "<<cost<<std::endl
        <<"How many would You like to buy?: "<<std::endl;

        std::cin.clear();
        std::cin.ignore(100, '\n' );
        std::cin>>bought;
    }while(std::cin.fail() || bought<0);

    if(bought*cost<=budget)//CHECKING IF USER HAS ENOUGHT MONEY
    {
        while(true)
        {
            clean();
            std::cout<<"You want to buy "<<bought<<" "<<value<<std::endl
            <<"Current Budget: "<<budget<<std::endl
            <<"Cost: "<<bought*cost<<std::endl
            <<"Budget after: "<<budget-bought*cost<<std::endl<<std::endl
            <<"Do You want to proceed?"<<std::endl
            <<"[1] Yes"<<std::endl<<"[2] No, I've changed my mind"<<std::endl;

            std::cin>>decision;
            if(decision=='1')
            {
                switch(cost)//checking which resource user is buying, and executing proper method
                {
                    case 20:    {on_use->buy_area(bought); break;}
                    case 150:   {on_use->buy_slots(bought); break;}
                    case 250:
                    {
                        Amu_Park *temp= dynamic_cast<Amu_Park*>(on_use);

                        temp->buy_workers(bought);

                        break;
                    }
                }
                return;
            }

            if(decision=='2') return;
        }
    }

    //WHEN USER HAS NOT ENOUGHT MONEY "IF" ABOVE WILL NOT EXECUTE!
    while(true)
    {
        clean();
        std::cout<<"Your budget is too low!"<<std::endl
        <<"[1] Ok"<<std::endl;

        std::cin>>decision;
        if(decision=='1') return;
    }
}

void buying_mascot(Theme_Park* theme_p)
{
    int budget=theme_p->get_budget();
    char decision;

    if(budget<150000)//CHECKING IF USER HAS ENOUGH MONEY FOR MASCOT
    {
        while(true)
        {

            clean();

            std::cout<<"Mascot is a special feature for You'r Thematic Park!"<<std::endl<<std::endl
            <<"Mascot cost: 150 000"<<std::endl<<"Mascot attributes: "<<std::endl
            <<"+20 to You'r Park popularity!"<<std::endl<<"50% chance for increased earnings!"<<std::endl;

            std::cout<<std::endl<<"Unfortunately You've got not enough money ;["<<std::endl
            <<"[1] Ok " <<std::endl;

            std::cin>> decision;
            if(decision=='1') return;
        }
    }


    //IF USER HAS ENOUGH BUDGET THE "IF" ABOVE WILL NOT EXECUTE
    while(true)
    {
        clean();

        std::cout<<"Mascot is a special feature for You'r Thematic Park!"<<std::endl<<std::endl
        <<"Mascot cost: 50 000"<<std::endl<<"Mascot attributes: "<<std::endl
        <<"+5 to You'r Park popularity!"<<std::endl<< "50% chance for increased earnings!"<<std::endl;

        std::cout << "Current Budget: " << budget << std::endl
        <<"Budget after: " << budget-50000 << std::endl << std::endl
        <<"Do You want to proceed?" << std::endl
        <<"[1] Yes" << std::endl << "[2] No, I've changed my mind" <<std::endl;

        std::cin>>decision;
        if(decision=='1')
        {
            theme_p->buy_mascot();
            return;
        }
        if(decision=='2') return;
    }
}

void buying_attractions(Ent_Park* on_use, facility current)
{
    char decision;
    char max_dec;

    while(true)
    {
        clean();

        on_use->show_type();
        std::cout<<std::endl;
        on_use->show_data();
        std::cout<<std::endl;
        max_dec= on_use->show_attractions();

        std::cout<<std::endl<<"Enter number of attraction You want to buy or \"0\" if You want to go back: "<<std::endl;
        std::cin >> decision;

        if(decision=='0') return;
        if(decision>'0' && decision <= max_dec)
        {
            buying_attraction(on_use,decision);

            return;
        }

    }
}

void buying_attraction(Ent_Park* on_use,char selected)
{
    int number=0;
    bool has_resources;
    char decision;

    do
    {
        clean();

        on_use->show_type();
        std::cout<<std::endl;
        on_use->show_data();
        std::cout<<std::endl;
        on_use->show_attraction(selected);

        if(std::cin.fail())  std::cout<<"You have to enter a positive number!"<<std::endl;

        std::cout<<std::endl<<"Enter how many of chosen attraction would You like to buy?"<<std::endl;

        std::cin.clear();
        std::cin.ignore(100, '\n' );
        std::cin >> number;

    }while(std::cin.fail() || number<=0);

    clean();
    has_resources= on_use-> check_resources(selected, number);

    if(has_resources==0)
    {
        std::cout<<"[1] Ok"<<std::endl;
        do{ std::cin>>decision;} while(decision!='1');

        return;
    }

    else
    {
        std::cout<<std::endl<<"Do You want to proceed?"<<std::endl
        <<"[1] Yes"<<std::endl<<"[2] No, I've changed my mind"<<std::endl;

        while(true)
        {

            std::cin>>decision;
            if(decision=='1'){ on_use->buy_attraction(selected, number); return; }
            if(decision=='2') return;
        }
    }


}

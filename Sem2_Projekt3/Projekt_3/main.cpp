#include "Managment.h"
using namespace std;


int main()
{
    srand(time(NULL));
    #ifdef TEST_H
    run_tests(); //activating all tests
    cin.ignore(100,'\n');
    #endif // TEST_H

    state manor;          //creating state and facility enum
    facility current;     //enum declarations -> Managment.h
    char decision='0';
    bool type;
    Theme_Park *theme_p=NULL;
    Amu_Park *amu_p=NULL;
    Ent_Park *on_use=NULL;//polymorphic pointer


    decision=start_up();//showing starting menu

    switch(decision)
    {
        case '1'://user chose thematic park
        {
            type=choose_theme();//choosing theme for thematic park(3 available)
            if(type==0) theme_p=new Theme_Park("Medival",0,1000,0,15,300,2,40,2);
            else        theme_p=new Theme_Park("Familial",0,1000,500,5,1000,8,60,7);
            manor=theme;    //setting owned facilities on thematic park
            current=t;      //setting currently used facility to thematic park
            on_use=theme_p; //setting polymorphic pointer on thematic park
            break;
        }
        case '2'://user chose amusement park
        {
            amu_p=new Amu_Park;
            manor=amu;      //setting owned facilities on amusement park
            current=a;      //setting currently used facility to amusement park
            on_use=amu_p;   //setting polymorphic pointer on amusement park
            break;
        }
        case '3'://user chose zoo
        {
            manor=zoo;
            break;
        }
        case '0': return 0;//user chose exit
    }

    while(true) //interface
    {
        clean();

        cout << "curently using: ";
        on_use->show_type();//showing facility we are currently using
        cout << "Budget: "<< on_use->get_budget()<<std::endl;
        cout <<endl<< "[1] Accept Visitors "<< endl;
        cout << "[2] Manage "<<endl<< endl;
        cout << "[3] Create new Park/Zoo"<< endl;
        cout << "[4] Switch into other Park/Zoo"<< endl<<endl;
        cout << "[0] Exit"<< endl;
        cin >> decision;
        switch(decision)
        {
            case '1':
            {
                on_use->accept_visitors();

                cout<<"[1] Ok"<<endl;
                do{ cin>>decision;} while(decision!='1');

                break;
            }

            case '2':
            {
                manage(on_use,current);
                break;
            }

            case '3':
            {
                decision=create_new(manor); //returning '1' if user chose thematic park,
                switch(decision)            //'2' Amusement Park, '3' Zoo
                {
                    case '1':
                    {
                        type=choose_theme();
                        if(type==0) theme_p=new Theme_Park("Medival",0,1000,0,15,300,2,40,2);
                        else        theme_p=new Theme_Park("Familial",0,1000,500,5,1000,8,60,7);
                    }
                    case '2':{amu_p= new Amu_Park;break;}
                    case '3': break;
                }

                break;
            }

            case '4':
            {
                 current=switching(manor,current);//returning which facility we are using after the switch
                 switch(current)//setting polymorphic pointer depending on the facility we are using
                 {
                    case a: { on_use=amu_p;break; }
                    case t: { on_use=theme_p;break; }
                    case z: break;
                 }
                 break;
            }

            case '0': return 0;
        }
    }
}





#include <iostream>
#include <cstdio>
#include <vector>
#include "funkcje.h"
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <cstdlib>
#endif // WIN32


void clean()// clearing screen compiling both on Linux and Windowsclean();
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

void choice(int &x)
{
    std::cout<< "[1] Zbuduj boisko\n[2] Zbuduj stadion\n[3] Zarzadzaj druzynami\n[4] Nastepny tydzien\n\n[0]Exit\nWybor: ";
    std::cin>>x;
    while(x<0||x>4)
    {
        clean();
        std::cout << "Wrong choice, please repeat your action!"<<std::endl;
        std::cout<< "[1] Zbuduj boisko\n[2] Zbuduj stadion\n[3] Zarzadzaj druzynami\n[4] Nastepny tydzien\n\n[0]Exit\nWybor: ";
        std::cin>>x;
    }
}

void buildField(boisko &field)
{
    if(!field.fieldInfoSet)
    {
        int x=-1,y=-1;
        std::string name;
        while(getchar()!='\n');
        std::cout<< "Nazwij boisko: ";
        getline(std::cin,name);
        while(x<90||x>120)
        {
            clean();
            std::cout<< "Podaj dlugosc [120>=x>=90]: ";
            std::cin>>x;
        }
        while(y<45||y>90)
        {
            clean();
            std::cout<< "Podaj szerkosc [90>=y>=45]: ";
            std::cin>>y;
        }
        field.fieldInfoSet=true;
        field.dlugosc=x;
        field.szerokosc=y;
        field.addName(name);
        field.addArea(x*y);
    }
    int x=0;
    while(x<1||x>3)
    {
        clean();
        std::cout<< "[1]Zmiana wymiarow\n[2]Pokrycie\n[3]Wyswietl info o boisku\n\nChoice: ";
        std::cin >> x;
    }
    switch(x)
    {
    case 1:
    {
        if(!field.stadiumCovered)
        {
            int x,y;
            while(x<90||x>120)
            {
                clean();
                std::cout<< "Podaj dlugosc [120>=x>=90]: ";
                std::cin>>x;
            }
            while(y<45||y>90)
            {
                clean();
                std::cout<< "Podaj szerkosc [90>=y>=45]: ";
                std::cin>>y;
            }
            field.dlugosc=x;
            field.szerokosc=y;
        }
        else
        {
            std::cout<<"Zmiana wymiarow spowoduje strate pokrycia!" ;
            int x,y;
            while(x<90||x>120)
            {
                clean();
                std::cout<< "Podaj dlugosc [120>=x>=90]: ";
                std::cin>>x;
            }
            while(y<45||y>90)
            {
                clean();
                std::cout<< "Podaj szerkosc [90>=y>=45]: ";
                std::cin>>y;
            }
            field.dlugosc=x;
            field.szerokosc=y;
        }
        break;
    }
    case 2:
    {
        int choice1;
        clean();
        if(field.fieldInfoSet&&!field.stadiumCovered)
        {
            std::cout << "[1]Trawa naturalna\n[2]Trawa sztuczna\n[3]Pokrycie gumowe\n\nChoice: ";
            std::cin>>choice1;
            while(choice1>3||choice1<1)
            {
                clean();
                std::cout<<"Niepoprawny wybor, prosze powtorzyc!"<<std::endl;
                std::cout << "[1]Trawa naturalna\n[2]Trawa sztuczna\n[3]Pokrycie gumowe\n\nChoice: ";
                std::cin>>choice1;
            }
            switch (choice1)
            {
            case 1:
            {
                field.pokrycie="Trawa naturalna";
                std::cout << "--------------\nStadion zostal pokryty trawa naturalna!";
                field.stadiumCovered=true;
                break;
            }
            case 2:
            {
                field.pokrycie="Trawa sztuczna";
                std::cout << "--------------\nStadion zostal pokryty trawa sztuczna!";
                field.stadiumCovered=true;
                break;
            }
            case 3:
            {
                field.pokrycie="Pokrycie gumowe";
                std::cout << "--------------\nStadion zostal pokryty guma!";
                field.stadiumCovered=true;
                break;
            }

            }
        }
        else
        {
            if(field.stadiumCovered)
            {
                std::cout << "Boisko jest pokryte!"<<std::endl;
            }
            else std::cout << "Prosze wybrac !"<<std::endl;
        }
        break;
    }
    case 3:
    {
        clean();
        std::cout<<field;
        std::cin.ignore(100,'\n');
        break;
    }
    }
}

void buildStadium(stadium &stadion)
{
    int x=0;
    while(x<1||x>3)
    {
        std::cout<< "[1]Ustawienie ceny 1 treningu\n[2]Dodanie krzesel\n[3]Wyswietl info o stadionie\n\nChoice: ";
        std::cin >> x;
    }
    switch(x)
    {
    case 1:
    {
        int x=0;
        while(x<=0)
        {
            clean();
            std::cout<<"Podaj cene jednego treningu 2-godzinowego: " << std::endl;
            std::cin >> x;
        }
        stadion.setTrainPrice(x);
        break;
    }
    case 2:
    {
        int x;
        clean();
        std::cout << "Cena - 3$/sztuka\n";
        std::cout << "Prosze podac ilosc krzesel do kupienia: ";
        std::cin>>x;
        if(stadion.revenue-x*3<0)
            std::cout << "Nie masz wystarczajaco pieniedzy!" << std::endl;
        else {stadion.numOfSeats+=x;stadion.revenue-=x*3;}
        break;
    }
    case 3:
    {
        clean();
        std::cout <<stadion;
        std::cin.ignore(100,'\n');
        break;
    }
    }
}

void manageTeams(std::vector<club> &kluby, int &iloscK, double cena,stadium st)
{
    int choice=0;
    club tmp;
    while(choice<1||choice>2)
    {
        clean();
        std::cout<<"[1]Dodaj klub\n[2]Wyswietl info o klubach\n\nChoice: "<<std::endl;
        std::cin>>choice;
    }
    switch(choice)
    {
    case 1:
    {
        std::string nazwa;
        std::cout<<"Podaj nazwe klubu: " << std::endl;
        std::cin>>nazwa;
        tmp.addName(nazwa);
        std::cout<<"Podaj miasto rodzinne klubu: " << std::endl;
        std::cin>>tmp.homeCity;
        std::cout<<"Podaj rok zalozenia klubu: " << std::endl;
        std::cin>>tmp.estYear;
        std::cout<<"Podaj budzet klubu: " << std::endl;
        std::cin>>tmp.budget;
        {
            int x; //how many days to train
            std::cout<<"Ile dni w tygodniu klub bedzie trenowal?(1-7)[0]Wyjsc" << std::endl;
            std::cin>>x;
            if(x!=0)
            {
                while(x<1||x>7||tmp.budget-(x*cena)<0)
                {
                    if(tmp.budget-(x*cena)<0)
                        std::cout<<"Klub nie ma wystarczajaco pieniedzy!" << std::endl;
                    else    std::cout<<"Wpisane bledne dane, prosze powtorzyc!"<<std::endl;
                    std::cout<<"Ile dni w tygodniu klub bedzie trenowal?(1-7)[0]Wyjsc" << std::endl;
                    std::cin>>x;
                    if(x==0)break;
                }
                tmp.daysToTrain=x;
            }
            else break;
        }
        {
            int x,y;
            for(int i=0; i<tmp.daysToTrain; i++)
            {
                clean();
                std::cout<<"["<<i+1<<"/"<<tmp.daysToTrain<<"]Wybierz w ktore dni klub bedzie trenowal!" << std::endl;
                std::cout<<"[1]Poniedzialek [2]Wtorek [3]Sroda [4]Czwartek [5]Piatek [6]Sobota [7]Niedziela \n\nWybor" << std::endl;
                std::cin >> x;
                while(x<1||x>7)
                {
                    clean();
                    std::cout<<"Wpisane bledne dane, prosze powtorzyc!"<<std::endl;
                    std::cout<<"["<<i+1<<"/"<<tmp.daysToTrain<<"]Wybierz w ktore dni klub bedzie trenowal!" << std::endl;
                    std::cout<<"[1]Poniedzialek [2]Wtorek [3]Sroda [4]Czwartek [5]Piatek [6]Sobota [7]Niedziela \n\nWybor" << std::endl;
                    std::cin >> x;
                }
                clean();
                std::cout<<"["<<i+1<<"/"<<tmp.daysToTrain<<"]Wybierz w ktorych godziach klub bedzie trenowal!" << std::endl;
                std::cout<<"[1]8-10 [2]10-12 [3]12-14 [4]14-16 [5]16-18 [6]18-20 [7]20-22 \n\nChoice" << std::endl;
                std::cin >> y;
                while(y<1||y>7)
                {
                    clean();
                    std::cout<<"Wpisane bledne dane, prosze powtorzyc!"<<std::endl;
                    std::cout<<"["<<i+1<<"/"<<tmp.daysToTrain<<"]Wybierz w ktorych godziach klub bedzie trenowal!" << std::endl;
                    std::cout<<"[1]8-10 [2]10-12 [3]12-14 [4]14-16 [5]16-18 [6]18-20 [7]20-22 \n\nChoice" << std::endl;
                    std::cin >> y;
                }
                if(st.timetable[y-1][x-1]=='-')
                {
                    tmp.trainingTime[y-1][x-1]='+';
                    st.timetable[y-1][x-1]='+';
                }
                else
                {
                    std::cout<<"Ten czas jest juz zajety! Prosze powtorzsyc!\n"<<std::endl;
                    i--;
                }
            }
        }
        kluby.push_back(tmp);
        iloscK++;
        break;
    }
    case 2:
    {
        clean();
        if(iloscK>0)
        {

            for(int i=0; i<iloscK; i++)
            {
                std::cout << kluby[i];
            }
        }
        else std::cout << "Nie ma dodanych klubow!" << std::endl;
        break;
    }
    }
}


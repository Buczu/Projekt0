#include <iostream>
#include <iomanip>
#include <vector>
#include "funkcje.h"

using namespace std;

int week;
int iloscKlubow;
double dochod;
int main()
{
    int mainChoice; // zmienna, zachowujaca wybor uzytkownika w menu
    //tworzenie objektow bez obiektu klasy abstrakcyjnej
    boisko field;
    stadium stadion;
    vector<club> kluby;
    while(1)
    {
        clean();
        if(stadion.stadiumBuilt)
            cout<<fixed<<setprecision(2) << "Budzet: " << stadion.revenue<<endl;
        cout <<fixed<<setprecision(2)<<"Week no. " << week << endl;
        cout << "--------------"<<endl;
        choice(mainChoice);
        switch(mainChoice)
        {
        case 1:
        {
            clean();
            cout << "--------------Budowa boiska--------------"<<endl;
            buildField(field);
            cin.ignore(100,'\n');
            cin.ignore(100,'\n');
            stadion.isThereBoisko=true;
            stadion.addName(field.getName());
            break;
        }
        case 2:
        {
            clean();
            if(stadion.isThereBoisko)
            {
                cout << "--------------Budowa stadionu--------------"<<endl;
                buildStadium(stadion);stadion.stadiumBuilt=true;
            }
            else
                cout << "Najpierw zbuduj boisko!"<<endl;
            cin.ignore(100,'\n');
            cin.ignore(100,'\n');

            break;
        }
        case 3:
        {
            clean();
            if(stadion.stadiumBuilt)
            {
                cout << "--------------Zarzadzanie druzynami--------------"<<endl;
                manageTeams(kluby,iloscKlubow,stadion.trainPrice,stadion);
            }
            else cout << "Najpierw zbuduj stadion!" << endl;
            cin.ignore(100,'\n');
            cin.ignore(100,'\n');
            break;
        }
        case 4:
        {
            for(int i=0;i<iloscKlubow;i++)
            {
                stadion.revenue+=(kluby[i].daysToTrain)*stadion.trainPrice;
                kluby[i].budget-=(kluby[i].daysToTrain)*stadion.trainPrice;
            }
            week++;
            break;
        }
        case 0:
        {
            clean();
            cout << "Stadium management simulator. (C)Marcin Jancurevic, 2017"<<endl;
            return 0;
        }
        }
    }
}

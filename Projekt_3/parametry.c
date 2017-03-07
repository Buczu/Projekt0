#include <stdio.h>
#include <stdlib.h>
#include "wirtualna_biblioteka.h"

void info()
{
    char decyzja;
    do
    {
        system("cls");
        puts("              Projekt laboratoryjny nr 3       ");
        puts("       Wirtualna biblioteka przemadrych madrosci");
        puts("                Tworca: Kamil Buczko           ");
        puts("--------------------------------------------------");
        puts("[1] Dzialanie programu oraz mozliwosci uzytkownika");
        puts("[2] Menu glowne");
        decyzja=getchar();
        while(getchar()!='\n');
        if(decyzja=='2')
        {
            system("cls");
            return;
        }
    }while(decyzja!='1');

    if(decyzja=='1')
    {
        do
        {
            system("cls");
            puts("------------------------------------------DZIALANIE PROGRAMU-----------------------------------------");
            puts("Program zarzadza dynamicznymi strukturami danych. Istnieje modulowy pojemnik podzielony na kategorie.");
            puts("Modulowy poniewaz mozna go rozszerzac o moduly z 3 nowych kategorii. W kazdej kategorii znajduja sie ");
            puts("wirtualne tabliczki madrosci ulozone w stosy. W kazdej tabliczce znajduje sie \"kategoria\", \"madrosc\"");
            puts("oraz zaleznie od preferencji uzytkownika \"dowolne dodatkowe pole\". W dowolnym momencie mozna w pelni ");
            puts("podgladac oraz modyfikowac struktury danych. Program obsluguje rowniez 3 parametry urchomienia: nazwa");
            puts("pliku z ktorego program wczyta oraz zapisze dane, \"info\" sluzace do wyswietlenia informacji na temat");
            puts("programu oraz \"rozmiar\" sluzace do dodania dodatkowej opcji w menu odpowiedzialnej za wyswietlenie");
            puts("rozmiaru biblioteki tzn. ilosci kategorii i ilosci madrosci w poszczegolnych kategoriach");
            puts("----------------------------------------MOZLIWOSCI UZYTKOWNIKA---------------------------------------");
            puts("Uzytkownik moze w dowolnym momencie w pelni podgladac oraz modyfikowac dane np. wyswietlac liste ");
            puts("kategorii, oraz znajdujace sie w nich madrosci, zmieniac nazwe kategorii, usuwac kategorie, usuwac ");
            puts("madrosc oraz edytowac tabliczke z madroscia.");
            puts("-----------------------------------------------------------------------------------------------------");
            puts("[1] Menu glowne");
            decyzja=getchar();
            while(getchar()!='\n');
        }while(decyzja!='1');
    }
    system("cls");
}
void rozmiar(stosik **pojemnik)
{
    char decyzja;
    int ile_stos,ile_madr;

    while(getchar()!='\n');

    if(pojemnik==NULL)
    {
        do
        {
            system("cls");
            puts("Biblioteka zawiera 0 kategorii");
            puts("------------------------------");
            puts("[1] Cofnij");
            decyzja=getchar();
            while(getchar()!='\n');
        }while(decyzja!='1');

        return;
    }

    for(ile_stos=0;pojemnik[ile_stos]!=NULL;ile_stos++); // po przejsciu petli i= ilosc stosow

    do
    {
        system("cls");
        printf("Biblioteka zawiera %d kategorie\n",ile_stos);
        puts("------------------------------");
        puts("[1] Pokaz liczbe madrosci");
        puts("[2] Cofnij");
        decyzja=getchar();
        while(getchar()!='\n');
        if(decyzja=='2') return;
    }while(decyzja!='1');

    do
    {
        system("cls");
        puts("--------------------------LICZBA MADROSSCI----------------------------");
        for(ile_stos=0;pojemnik[ile_stos]!=NULL;ile_stos++)
        {
            stosik *tmp=pojemnik[ile_stos];
            for(ile_madr=0;tmp!=NULL;ile_madr++) tmp=tmp->next;
            printf("Kategoria \"%s\" zawiera %d madrosci\n",pojemnik[ile_stos]->kategoria,ile_madr);
        }
        puts("----------------------------------------------------------------------");
        puts("[1] Cofnij do menu");
        decyzja=getchar();
        while(getchar()!='\n');
    }while(decyzja!='1');
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wirtualna_biblioteka.h"

int main(int argc,char *argv[])
{
    stosik **pojemnik=NULL;  //tablica wskaznikow na stosy
    int dodania=3;
    int rozmiar_true=0;
    char decyzja;
    char *nazwa_pliku=NULL;

    if(argc>1)
    {
        int i;
        for(i=1;i<argc;i++)
        {
            if(!strcmp(argv[i],"info")) info();
            else if (!strcmp(argv[i],"rozmiar")) rozmiar_true=1;
            else
            {
                if(nazwa_pliku==NULL)
                {
                    pojemnik=wczytaj(argv[i]);
                    nazwa_pliku=argv[i];
                }
            }
        }
    }
    while(1)
    {
        puts("Wirutalna biblioteka przemadrych madrosci");
        puts("-----------------------------------------");
        puts("[1] Pokaz Madrosci");
        printf("[2] Dodaj kategorie (pozostalo uzyc: %d)\n",dodania);
        puts("[3] Dodaj madrosc");
        puts("[4] Usun kategorie");
        puts("[5] Zmien nazwe kategorii");
        puts("-----------------------------------------");
        puts("[6] Zapisz i wyjdz");
        puts("[7] Wyjdz");
        if(rozmiar_true)
        {
            puts("-----------------------------------------");
            puts("[0] Pokaz rozmiar biblioteki");
        }
        decyzja=getchar();
        switch(decyzja)
        {
            case '1':
            {
                pojemnik=wyswietl(pojemnik,&dodania);
                break;
            }
            case '2':
            {
                pojemnik=dodaj_kategorie(pojemnik,&dodania);
                break;
            }
            case '3':
            {
                dodaj_tabliczke(pojemnik);
                break;
            }
            case '4':
            {
                pojemnik=usun_kat(pojemnik,&dodania);
                break;
            }
            case '5':
            {
                edytuj_kat(pojemnik);
                break;
            }
            case '6': zapisz(pojemnik,nazwa_pliku);
            case '7': return 0;
            case '0':
                if(rozmiar_true) rozmiar(pojemnik);
        }
        system("cls");
    }
}

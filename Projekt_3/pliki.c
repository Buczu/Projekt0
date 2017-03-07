#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wirtualna_biblioteka.h"

void zapisz(stosik **pojemnik,char *nazwa_pliku)
{
    int i,ile_stos,ile_madr;
    stosik *tmp=NULL;
    FILE *plik;

    if(nazwa_pliku==NULL)
    {
        system("cls");
        char nazwa[21]="\0";
        do
        {
            i=0;
            while(getchar()!='\n');
            puts("Podaj nazwe pliku:");
            scanf("%20[^\n]",nazwa);

            if(nazwa[0]==' ')
            {
                system("cls");
                puts("Nazwa pliku nie moze zaczynac sie od spacji!\n");
                nazwa[0]=0;
                i=1;
            }
            else if(nazwa[0]==0)
            {
                system("cls");
                puts("Nazwa pliku nie moze byc pusta!\n");
                i=1;
            }
        }while(i);

        nazwa_pliku=nazwa;
    }

    if(pojemnik==NULL)  // petla sprwadzajaca czy istnieje conajmniej jedna kategoria
    {
        plik=fopen(nazwa_pliku, "wb");
        fclose(plik);
        return;
    }
    for(ile_stos=0;pojemnik[ile_stos]!=NULL;ile_stos++);  // petla zliczajaca liczbe stosow
    plik=fopen(nazwa_pliku, "wb");

    fwrite(&ile_stos , sizeof(int), 1, plik);
    for(i=0;i<ile_stos;i++)
    {
        ile_madr=0;
        tmp=pojemnik[i];
        while(tmp!=NULL)      // petla zliczajace liczbe madrosci w stosie
        {
            ile_madr++;
            tmp=tmp->next;
        }
        fwrite(&ile_madr,sizeof(int),1,plik);
        tmp=pojemnik[i];

        int wielkosc=0;
        wielkosc=strlen(tmp->kategoria)+1;

        fwrite(&wielkosc,sizeof(int),1,plik);

        fwrite(tmp->kategoria,sizeof(char),wielkosc,plik);

        while(tmp!=NULL)            // petla zliczajaca ilosc madrosci w kategorii
        {
            wielkosc=strlen(tmp->madrosc)+1;
            fwrite(&wielkosc,sizeof(int),1,plik);
            fwrite(tmp->madrosc,sizeof(char),wielkosc,plik);

            if(tmp->dowolne==NULL)
            {
                wielkosc=5;
                fwrite(&wielkosc,sizeof(int),1,plik);
                fwrite("null",sizeof(char),5,plik);
            }
            else
            {
                wielkosc=strlen(tmp->dowolne)+1;
                fwrite(&wielkosc,sizeof(int),1,plik);
                fwrite(tmp->dowolne,sizeof(char),wielkosc,plik);
            }
            tmp=tmp->next;
        }
    }
    fclose(plik);
}

stosik** wczytaj(char *nazwa_pliku)
{
    FILE *plik;
    int ile_stos, ile_madr, wielkosc;
    stosik **pojemnik=NULL;
    char kategoria[81], madrosc[201], dowolne[201];
    plik=fopen(nazwa_pliku, "rb");

    if(plik==NULL) return NULL;  // sprawdzenie czy plik istnieje

    fread(&ile_stos,sizeof(int),1,plik);

    if (feof(plik)) // spawdzenie czy plik nie jest pusty
    {
        fclose(plik);
        return NULL;
    }

    pojemnik=(stosik**)malloc(sizeof(stosik*) * (ile_stos+1) );  // +1 bo ostatni wskaznik bedzie NULL'em
    int i;
    for(i=0;i<ile_stos;i++)
    {
        fread(&ile_madr,sizeof(int),1,plik);
        fread(&wielkosc,sizeof(int),1,plik);
        fread(kategoria,sizeof(char),wielkosc,plik);

        int j;
        stosik *dodaj[ile_madr];   // pomocnicza tablica sluzaca do polaczenie wczytanych madrosci w stos
        for(j=0;j<ile_madr;j++)
        {
            dodaj[j]=(stosik*)malloc(sizeof(stosik));

            dodaj[j]->kategoria=(char*)malloc(sizeof(char) * (strlen(kategoria)+1) );
            strcpy( dodaj[j]->kategoria,kategoria);

            fread(&wielkosc,sizeof(int),1,plik);
            fread(madrosc,sizeof(char),wielkosc,plik);
            dodaj[j]->madrosc=(char*)malloc(sizeof(char) * (strlen(madrosc)+1) );
            strcpy( dodaj[j]->madrosc,madrosc);

            fread(&wielkosc,sizeof(int),1,plik);
            fread(dowolne,sizeof(char),wielkosc,plik);
            if(!strcmp(dowolne,"null")) dodaj[j]->dowolne=NULL;
            else
            {
                dodaj[j]->dowolne=(char*)malloc(sizeof(char) * (strlen(dowolne)+1) );
                strcpy( dodaj[j]->dowolne,dowolne);
            }
        }
        for(j=0;j<(ile_madr-1);j++)  dodaj[j]->next=dodaj[j+1];   // -1 bo ostatnia  tabliczka na NULL
        dodaj[j]->next=NULL;
        pojemnik[i]=dodaj[0];
    }
    pojemnik[i]=NULL;
    fclose(plik);

    return pojemnik;
}

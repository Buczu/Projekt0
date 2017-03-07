#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wirtualna_biblioteka.h"


stosik** wyswietl(stosik **pojemnik,int *dodania)
{
    int wybor,i;
    char decyzja;

    if(pojemnik==NULL)
    {
        do
        {
            while(getchar()!='\n');
            system("cls");
            puts("Biblioteka jest pusta, wprowadz dane");
            puts("------------------------------------");
            puts("[1] Cofnij");
            decyzja=getchar();
        }while(decyzja!='1');
        return pojemnik;
    }

    do
    {
        while(getchar()!='\n');
        system("cls");
        puts("Wybierz kategorie: ");
        puts("------------------------------------------");
        for(i=0;pojemnik[i]!=NULL;i++)  printf("[%d] %s\n",i+1,pojemnik[i]->kategoria); // po przejsciu petli i= ilosc stosow
        puts("------------------------------------------");
        printf("[%d] Cofnij\n",i+1);
        scanf("%d",&wybor);
        if(wybor==i+1) return pojemnik;
    }while(wybor<=0 || wybor>i);

    system("cls");
    while(getchar()!='\n');

    stosik *tmp=pojemnik[wybor-1];
    while(tmp!=NULL)        // wyswietlanie madrosci
    {
        do
        {
            system("cls");
            puts("---------------------------------------------Kategoria-----------------------------------------------------");
            printf("%s\n",tmp->kategoria);
            puts("----------------------------------------------Madrosc------------------------------------------------------");
            printf("\"%s\"\n",tmp->madrosc);
            if(tmp->dowolne!=NULL)
            {
                puts("---------------------------------------------Dodatkowe-----------------------------------------------------");
                printf("%s\n",tmp->dowolne);
            }
            puts("-----------------------------------------------------------------------------------------------------------");
            puts("[1] Nastepna madrosc");
            puts("[2] Usun madrosc");
            puts("[3] Edytuj");
            puts("-----------------------------------------------------------------------------------------------------------");
            puts("[4] Cofnij do menu");
            decyzja=getchar();

            if(decyzja=='2')
            {
                pojemnik=usun_madr(tmp,&pojemnik[wybor-1],pojemnik,dodania);
                return pojemnik;
            }
            if(decyzja=='3') edytuj_madr(tmp);
            if(decyzja=='4') return pojemnik;

        }while(decyzja!='1');
        tmp=tmp->next;
    }
    while(getchar()!='\n');

    do
    {
        system("cls");
        puts("Biblioteka nie zawiera wiecej madrosci danej kategorii");
        puts("------------------------------------------------------");
        puts("[1] Cofnij do menu");
        decyzja=getchar();
        while(getchar()!='\n');
    }while(decyzja!='1');

    return pojemnik;
}
stosik** dodaj_kategorie(stosik **pojemnik,int *dodania)
{
    int ile_stos;
    char kategoria[81]="\0", madrosc[201]="\0", dowolne[201]="\0", decyzja;

    while(getchar()!='\n');

    if(*dodania==0)
    {
        do
        {
            system("cls");
            puts("Limit dodan zostal wykorzystany");
            puts("-------------------------------");
            puts("[1] Cofnij");
            decyzja=getchar();
            while(getchar()!='\n');
        }while(decyzja!='1');

        return pojemnik;
    }

    system("cls");
    do
    {
        puts("Podaj nowa kategorie:");
        scanf("%80[^\n]",kategoria);
    }while(wprowadzanie(kategoria));

    if(pojemnik==NULL)
    {
        pojemnik=(stosik**)malloc(sizeof(stosik*) * 2);
        ile_stos=0;
    }
    else
    {
        for(ile_stos=0;pojemnik[ile_stos]!=NULL;ile_stos++)    // petla zliczajaca liczbe stosow
            if(!strcmp(pojemnik[ile_stos]->kategoria , kategoria))    // sprwadzanie czy kategoria sie powtarza
                do
                {
                    system("cls");
                    puts("Podana kategoria znajduje sie juz w bibliotece");
                    puts("----------------------------------------------");
                    puts("[1] Cofnij");
                    decyzja=getchar();
                    while(getchar()!='\n');
                    if(decyzja=='1') return pojemnik;
                }while(decyzja!='1');

        pojemnik=(stosik**)realloc(pojemnik,sizeof(stosik*) * (ile_stos+2) );  // +2 bo 1 na nowy a 2 na NULL'a
    }

    pojemnik[ile_stos]=(stosik*)malloc(sizeof(stosik));

    pojemnik[ile_stos]->kategoria=(char*)malloc(sizeof(char) * (strlen(kategoria)+1) );
    strcpy(pojemnik[ile_stos]->kategoria,kategoria);

    system("cls");
    do
    {
        puts("Podaj madrosc:");
        scanf("%200[^\n]",madrosc);
    }while(wprowadzanie(madrosc));

    pojemnik[ile_stos]->madrosc=(char*)malloc(sizeof(char) * (strlen(madrosc)+1) );
    strcpy(pojemnik[ile_stos]->madrosc,madrosc);

    do
    {
        system("cls");
        puts("Chcesz dodac dodatkowe pole?");
        puts("[1] Tak");
        puts("[2] Nie");
        decyzja=getchar();
        while(getchar()!='\n');                 // petla czyszczaca bufor
    }while(decyzja!='1' && decyzja!='2');

    if(decyzja=='1')
    {
        system("cls");
        do
        {
            puts("podaj dodatkowe pole:");
            scanf("%200[^\n]",dowolne);
        }while(wprowadzanie(dowolne));

        pojemnik[ile_stos]->dowolne=(char*)malloc(sizeof(char) * (strlen(dowolne)+1));
        strcpy(pojemnik[ile_stos]->dowolne,dowolne);
    }
    else pojemnik[ile_stos]->dowolne=NULL;

    pojemnik[ile_stos]->next=NULL;
    pojemnik[ile_stos+1]=NULL;
    (*dodania)--;
    return pojemnik;
}
void dodaj_tabliczke(stosik **pojemnik)
{
    char madrosc[201]="\0", dowolne[201]="\0";
    int i, wybor;
    stosik *dodaj;

    while(getchar()!='\n');     // petla czyszczaca bufor


    if(pojemnik==NULL)
    {
        do
        {
            system("cls");
            puts("Biblioteka nie zawiera zadnej kategorii, dodaj nowa kategorie");
            puts("-------------------------------------------------------------");
            puts("[1] Cofnij ");
            scanf("%d",&wybor);
            while(getchar()!='\n');
        }while(wybor!=1);
        return;
    }
    do
    {
        system("cls");
        puts("Wybierz kategorie:");
        puts("------------------");
        for(i=0;pojemnik[i]!=NULL;i++)  printf("[%d] %s\n",i+1,pojemnik[i]->kategoria);
        puts("------------------");
        printf("[%d] Cofnij\n",i+1);
        scanf("%d",&wybor);
        while(getchar()!='\n');
        if(wybor==i+1) return;
    }while(wybor<=0 || wybor>i+1);

    dodaj=(stosik*)malloc(sizeof(stosik));

    dodaj->kategoria=(char*)malloc(sizeof(char) * (strlen(pojemnik[wybor-1] -> kategoria) +1) );
    strcpy(dodaj->kategoria,pojemnik[wybor-1] -> kategoria);

    system("cls");
    do
    {
        puts("podaj madrosc:");
        scanf("%200[^\n]",madrosc);
    }while(wprowadzanie(madrosc));

    dodaj->madrosc=(char*)malloc(sizeof(char) * (strlen(madrosc)+1));
    strcpy(dodaj->madrosc,madrosc);

    dodaj->next=pojemnik[wybor-1];
    pojemnik[wybor-1]=dodaj;

    do
    {
        system("cls");
        puts("Chcesz dodac dodatkowe pole?");
        puts("[1] Tak");
        puts("[2] Nie");
        scanf("%d",&wybor);
        while(getchar()!='\n');                 // petla czyszczaca bufor
    }while(wybor!=1 && wybor!=2);

    if(wybor==1)
    {
        system("cls");
        do
        {
            puts("podaj dodatkowe pole:");
            scanf("%200[^\n]",dowolne);
        }while(wprowadzanie(dowolne));

        dodaj->dowolne=(char*)malloc(sizeof(char) * (strlen(dowolne)+1));
        strcpy(dodaj->dowolne,dowolne);
    }
    else dodaj->dowolne=NULL;
}
void edytuj_kat(stosik **pojemnik)
{
    int i, wybor;
    char kategoria[81]="\0", decyzja;
    stosik *tmp;

    while(getchar()!='\n');

    if(pojemnik==NULL)
    {
        do
        {
            system("cls");
            puts("Biblioteka nie zawiera zadnej kategorii");
            puts("---------------------------------------");
            puts("[1] Cofnij");
            decyzja=getchar();
            while(getchar()!='\n');
        }while(decyzja!='1');
        return;
    }
    do
    {

        system("cls");
        puts("Nazwe ktorej kategorii chcesz zmienic?");
        puts("------------------------------------------");
        for(i=0;pojemnik[i]!=NULL;i++)  printf("[%d] %s\n",i+1,pojemnik[i]->kategoria); // po przejsciu petli i= ilosc stosow
        puts("------------------------------------------");
        printf("[%d] Cofnij\n",i+1);
        scanf("%d",&wybor);
        while(getchar()!='\n');
        if(wybor==i+1) return;
    }while(wybor<=0 || wybor>i);

    system("cls");
    do
    {
        puts("Podaj nowa nazwe wybranej kategorii:");
        scanf("%80[^\n]",kategoria);
    }while(wprowadzanie(kategoria));

    for(i=0;pojemnik[i]!=NULL;i++)  // petla zliczajaca liczbe stosow
        if(!strcmp(pojemnik[i]->kategoria , kategoria)) // sprawdzenie czy kategoria sie powtarza
            do
            {
                system("cls");
                puts("Podana kategoria znajduje sie juz w bibliotece");
                puts("----------------------------------------------");
                puts("[1] Cofnij");
                decyzja=getchar();
                while(getchar()!='\n');
                if(decyzja=='1') return ;
            }while(decyzja!='1');

    tmp=pojemnik[wybor-1];

    while(tmp!=NULL)
    {
        tmp->kategoria=(char*)realloc(tmp->kategoria, sizeof(char) * (strlen(kategoria)+1) );
        strcpy(tmp->kategoria,kategoria);
        tmp=tmp->next;
    }
}
void edytuj_madr(stosik *tmp)
{
    char zawartosc[201]="\0";
    int wybor,i=1;
    do
    {
        while(getchar()!='\n');
        system("cls");
        puts("---------------------------------------------Kategoria-----------------------------------------------------");
        printf("%s\n",tmp->kategoria);
        puts("----------------------------------------------Madrosc------------------------------------------------------");
        printf("\"%s\"\n",tmp->madrosc);
        if(tmp->dowolne!=NULL)
        {
            puts("---------------------------------------------Dodatkowe-----------------------------------------------------");
            printf("%s\n",tmp->dowolne);
            puts("-----------------------------------------------------------------------------------------------------------");
            printf("[%d] Zmien dodatkowe pole\n",i++);
            printf("[%d] Usun dodatkowe pole\n",i++);
        }
        else
        {
            puts("-----------------------------------------------------------------------------------------------------------");
            printf("[%d] Dodaj dodatkowe pole\n",i++);
        }
        printf("[%d] Zmien zawartosc madrosci\n",i++);
        puts("-----------------------------------------------------------------------------------------------------------");
        printf("[%d] Cofnij\n",i);
    }while(scanf("%d",&wybor)!=1 || wybor<1 || wybor>i);

    if(tmp->dowolne==NULL)
    {
        if (wybor>1) wybor++;
        if (wybor==1) wybor=5;
    }

    system("cls");
    switch(wybor)
    {
        case 1:
        {
            while(getchar()!='\n');
            do
            {
                puts("Podaj nowa zawartosc:");
                scanf("%200[^\n]",zawartosc);
            }while(wprowadzanie(zawartosc));

            tmp->dowolne=(char*)realloc(tmp->dowolne, sizeof(char) * (strlen(zawartosc)+1) );
            strcpy(tmp->dowolne,zawartosc);
            break;
        }
        case 2:
        {
            while(getchar()!='\n');
            free(tmp->dowolne);
            tmp->dowolne=NULL;
            break;
        }
        case 3:
        {
            while(getchar()!='\n');
            do
            {
                puts("Podaj nowa zawartosc:");
                scanf("%200[^\n]",zawartosc);
            }while(wprowadzanie(zawartosc));

            tmp->madrosc=(char*)realloc(tmp->madrosc, sizeof(char) * (strlen(zawartosc)+1) );
            strcpy(tmp->madrosc,zawartosc);
            break;
        }
        case 4:
        {
            while(getchar()!='\n');
            return;
        }
        case 5:
        {
            while(getchar()!='\n');
            do
            {
                puts("Podaj zawartosc:");
                scanf("%200[^\n]",zawartosc);
            }while(wprowadzanie(zawartosc));
            tmp->dowolne=(char*)malloc( sizeof(char) * (strlen(zawartosc)+1) );
            strcpy(tmp->dowolne,zawartosc);
            break;
        }
    }
}
stosik** usun_kat(stosik **pojemnik, int *dodania)
{
    char decyzja;
    int i, wybor;

    if(pojemnik==NULL)
    {
        do
        {
            while(getchar()!='\n');
            system("cls");
            puts("Biblioteka nie zawiera zadnej kategorii");
            puts("---------------------------------------");
            puts("[1] Cofnij");
            decyzja=getchar();
        }while(decyzja!='1');
        return pojemnik;
    }

    do
    {
        while(getchar()!='\n');
        system("cls");
        puts("Wybierz kategorie ktora chcesz usunac:");
        puts("------------------------------------------");
        for(i=0;pojemnik[i]!=NULL;i++)  printf("[%d] %s\n",i+1,pojemnik[i]->kategoria); // po przejsciu petli i= ilosc stosow
        puts("------------------------------------------");
        printf("[%d] Cofnij\n",i+1);
        scanf("%d",&wybor);
        if(wybor==i+1) return pojemnik;
    }while(wybor<=0 || wybor>i);

    do
    {
        while(getchar()!='\n');
        system("cls");
        printf("Jestes pewien, ze chcesz usunac kategorie: \"%s\"?\n",pojemnik[wybor-1]->kategoria);
        puts("[1] Tak, jestem pewny");
        puts("[2] Nie, rozmyslilem sie");
        decyzja=getchar();
        if(decyzja=='2') return pojemnik;

    }while(decyzja!='1');

    stosik *tmp;
    stosik *pomoc=pojemnik[wybor-1];

    while(pomoc!=NULL)
    {
        tmp=pomoc;
        pomoc=pomoc->next;
        free(tmp->kategoria);
        free(tmp->madrosc);
        if(tmp->dowolne!=NULL) free(tmp->dowolne);
        free(tmp);
        tmp=NULL;
    }
    if(i==1) // przypadek gdy usuwamy jedyna kategorie w pojemniku
    {
        free(pojemnik);
        pojemnik=NULL;
    }
    else // przypadek gdy usuwamy kategorie ktora nie jest jedyna w pojemniku
    {
        int j;
        for(j=0;pojemnik[wybor-1+j]!=NULL;j++)
            pojemnik[wybor-1+j]=pojemnik[wybor+j];
        pojemnik=(stosik**)realloc(pojemnik, sizeof(stosik*) * i);//i=ilosc stosow ktore byly przed usunieciem, nie uzywam dekrementacji bo dodatkowe miejsce na NULL'a
    }

    do
    {
        while(getchar()!='\n');
        system("cls");
        puts("Usunieto pomyslnie");
        puts("------------------");
        puts("[1] Cofnij");
        decyzja=getchar();
    }while(decyzja!='1');

    (*dodania)++;
    return pojemnik;
}
stosik** usun_madr(stosik *usun,stosik **glowa,stosik **pojemnik, int *dodania)
{
    char decyzja;

    if(*glowa==usun)    // sprawdzenie czy usuwamy pierwszy element stosu
    {
        if((*glowa)->next==NULL) // sprawdzenie czy usuwamy ostatnia madrosc w danej kategorii
        {
            do
            {
                while(getchar()!='\n');
                system("cls");
                puts("Jest to ostatnia madrosc w kategorii, usuniecie jej spowoduje usuniecie calej kategorii, kontynuowac?\n");
                puts("[1] Tak, kontynuj");
                puts("[2] Nie, cofnij do menu");
                decyzja=getchar();
                if(decyzja=='2') return pojemnik;
            }while(decyzja!='1' && decyzja!='2');

            (*dodania)++;

            int ile_stos;
            for(ile_stos=0;pojemnik[ile_stos]!=NULL;ile_stos++); // pelta zliczajaca kategorie
            if(ile_stos==1)
            {
                free(pojemnik);
                pojemnik=NULL;
            }
            else
            {
                int i;
                for(i=0;pojemnik[i]!=*glowa;i++); // petla znajdujaca ktory element w tablicy wskaznikow nalezy usunac
                for(;pojemnik[i]!=NULL;i++)    pojemnik[i]=pojemnik[i+1]; // petla przepisujac wartosci szufladek z tablicy
                                                                          // do szufladek o 1 mniejszym indeksie zaczynajac od elementu ktory nalezy usunac
                pojemnik=(stosik**)realloc(pojemnik,sizeof(stosik*) * ile_stos ); // ile_stos bo dodatkowe miejsce na NULL'a
            }
        }
        else// przypadek w ktorym usuwamy pierwszy element stosu skladajacego sie z wiecej niz jednej madrosci
        {
            do
            {
                while(getchar()!='\n');
                system("cls");
                puts("Jestes pewny?");
                puts("[1] Tak, jestem pewny");
                puts("[2] Nie, rozmyslilem sie");
                decyzja=getchar();
                if(decyzja=='2') return pojemnik;

                }while(decyzja!='1');

            *glowa=(*glowa)->next;
        }
    }
    else// przypadek w ktorym usuwamy niepierwszy element stosu
    {
        do
        {
            while(getchar()!='\n');
            system("cls");
            puts("Jestes pewny?");
            puts("[1] Tak, jestem pewny");
            puts("[2] Nie, rozmyslilem sie");
            decyzja=getchar();
            if(decyzja=='2') return pojemnik;

        }while(decyzja!='1');

        stosik** tmp=glowa;

        while((*tmp)->next!=usun)
        {
            (*tmp)=(*tmp)->next;
        }
        (*tmp)->next=usun->next;
    }

    if(usun->dowolne!=NULL) free(usun->dowolne);
    free(usun->kategoria);
    free(usun->madrosc);
    free(usun);
    usun=NULL;
    do
    {
        while(getchar()!='\n');
        system("cls");
        puts("Usunieto pomyslnie");
        puts("------------------");
        puts("[1] Cofnij");
        decyzja=getchar();
    }while(decyzja!='1');
    return pojemnik;
}
int wprowadzanie(char* lancuch)
{
    while(getchar()!='\n');
    if(lancuch[0]==' ')
    {
        system("cls");
        puts("Tekst nie moze zaczynac sie od spacji!\n");
        lancuch[0]=0;
        return 1;
    }
    if(lancuch[0]==0)
    {
        system("cls");
        puts("Tekst nie moze byc pusty!\n");
        return 1;
    }
    return 0;
}

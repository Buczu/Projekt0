#ifndef WIRTUALNA_BIBLIOTEKA_H
#define WIRTUALNA_BIBLIOTEKA_H

typedef struct stos
{
    char *kategoria;
    char *madrosc;
    char *dowolne;
    struct stos *next;
}stosik;

void zapisz(stosik**,char*);// PLIKI
stosik** wczytaj(char*);
stosik** wyswietl(stosik**,int*);// ZARZADZANIE
stosik** dodaj_kategorie(stosik**, int*);
void edytuj_kat(stosik**);
void edytuj_madr(stosik*);
void dodaj_tabliczke(stosik**);
stosik** usun_kat(stosik**, int*);
stosik** usun_madr(stosik*, stosik**,stosik**,int*);
int wprowadzanie(char*);
void info();// PARAMETRY
void rozmiar(stosik**);

#endif // WIRTUALNA_BIBLIOTEKA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Adres {
    char ulica[15];
    char miasto[15];
    int numer;
};

struct Osoba {
    char *imie;
    char *nazwisko;
    int wiek;
    struct Adres dom;
    struct Adres *firma;
};

void wczytajOsobe(struct Osoba *oo){
    char b[20], b1[20];
    printf("Podaj imie, nazwisko oraz wiek osoby: \n");
    scanf("%s%s%d", b, b1, &oo->wiek);
    oo->imie = (char*) malloc((strlen(b)+1)*sizeof(char));
    oo->nazwisko = (char*) malloc((strlen(b1)+1)*sizeof(char));
    strcpy(oo->imie, b);
    strcpy(oo->nazwisko, b1);
    printf("Podaj ulice, miasto oraz numer dla adresu domowego: \n");
    scanf("%s%s%d", oo->dom.ulica, oo->dom.miasto, &oo->dom.numer);
    oo->firma = (struct Adres*)malloc(sizeof(struct Adres));
    printf("Podaj ulice, miasto oraz numer dla adresu firmowego: \n");
    scanf("%s%s%d", oo->firma->ulica, oo->firma->miasto, &oo->firma->numer);
}

int main() {
    struct Osoba Olek, *wskOlek;
    wskOlek = &Olek;

    wczytajOsobe(wskOlek);

    printf("%s %s\nadres domowy: %s %s %d\nadres firmowy: %s %s %d\n", Olek.imie, Olek.nazwisko, Olek.dom.miasto, Olek.dom.ulica, Olek.dom.numer, Olek.firma->miasto, Olek.firma->ulica, Olek.firma->numer);

    printf("%s %s\nadres domowy: %s %s %d\nadres firmowy: %s %s %d\n", wskOlek->imie, wskOlek->nazwisko, wskOlek->dom.miasto, wskOlek->dom.ulica, wskOlek->dom.numer, wskOlek->firma->miasto, wskOlek->firma->ulica, wskOlek->firma->numer);

    free(Olek.firma);
    free(Olek.nazwisko);
    free(Olek.imie);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// wyswietlamy srednia ocen dla ucznia o podanym przez uzytkownika imieniu
struct uczen {
    char imie[10];
    float mat;
    float fiz;
    float inf;
};
int main() {
    int i,k=0, n=3; //mozna wczytać n, tu dla ulatwienia przyjmujemy n=3
    struct uczen klasa[n]; //klasa zawiera n obiektow typu uczen
    char kto[10];
    float sr;
    for(i=0; i<n; i++) {
        printf("imie "); //kazdy uczen (o numerze= i) ma imie i 3 oceny
        scanf(" %9[^\n]s", klasa[i].imie);
        printf("ocena z mat. ");
        scanf("%f", &klasa[i].mat);
        printf("ocena z fiz. ");
        scanf("%f", &klasa[i].fiz);
        printf("ocena z inf. ");
        scanf("%f", &klasa[i].inf);
    }
    printf("Kogo szukamy? Imie: "); //kogo szukamy?
    scanf(" %9[^\n]s", kto);
    for(i=0; i<n; i++) { 
        //porownanie 2 tekstow, jesli sa rowne to strcmp zwraca 0
        if(strcmp(klasa[i].imie,kto) == 0) {
            k=1; //info, ze uczen znaleziony
            sr=(klasa[i].mat+klasa[i].fiz+klasa[i].inf)/3;
            printf("uczen: %s srednia ocen: %.1f",kto,sr);
        }
    }
    if(k == 0) //czyli uczen nie znaleziony
        printf(" Ucznia %s nie ma", kto);
    return 0;
}
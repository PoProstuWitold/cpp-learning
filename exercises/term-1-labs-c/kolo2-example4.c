#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Uczelnia {
    char miasto[20];
    char typ[20]; //typ uczelni:uniwersytet, akademia, politechnika
    int L_s; // liczba studentów
    int L_w; //liczba wydziałów
} uczelnia;
typedef struct Result {
    int ilosc;
    uczelnia * lista;
} result;
int ile_s(uczelnia *uczelnie, int ilosc);
result ucz_wydz(uczelnia *uczelnie, int n);
result ucz_m(uczelnia *uczelnie, int n, char *city);
int main() {
    int ilosc;
    printf("Podaj ilosc uczelni: ");
    scanf("%d", &ilosc);
    uczelnia *uczelnie=(uczelnia *)malloc(ilosc * sizeof(uczelnia));
    for(int i = 0; i < ilosc; i++) {
        printf("Podaj miasto %d: ", i+1);
        scanf(" %19[^\n]s", uczelnie[i].miasto);
        printf("Podaj typ %d: ", i+1);
        scanf(" %19[^\n]s", uczelnie[i].typ);
        printf("Podaj liczbe studentow %d: ", i+1);
        scanf("%d", &uczelnie[i].L_s);
        printf("Podaj liczbe wydzialow %d: ", i+1);
        scanf("%d", &uczelnie[i].L_w);
        printf("\n");
    }
    for(int j = 0; j < ilosc; j++) {
        printf("Uczelnia nr %d\n", j+1);
        printf("\tmiasto: %s\n", uczelnie[j].miasto);
        printf("\ttyp: %s\n", uczelnie[j].typ);
        printf("\tstudentow: %d\n", uczelnie[j].L_s);
        printf("\twydzialow: %d\n", uczelnie[j].L_w);
    }
    printf("\nIlosc wszystkich studentow: %d\n", ile_s(uczelnie, ilosc));
    result result1 = ucz_wydz(uczelnie, ilosc);
    if(result1.ilosc) {
        printf("\n\nUczelnie z wiecej niz 3 wydzialami:\n");
        for(int k = 0; k < result1.ilosc; k++) {
            printf("Uczelnia nr %d\n", k+1);
            printf("\tmiasto: %s\n", result1.lista[k].miasto);
            printf("\ttyp: %s\n", result1.lista[k].typ);
            printf("\tstudentow: %d\n", result1.lista[k].L_s);
            printf("\twydzialow: %d\n\n", result1.lista[k].L_w);
        }
    } else {
        printf("\nBrak uczelni z liczba wydzialow > 3\n");
    }
    char miasto[20];
    printf("Podaj miasto: ");
    scanf(" %19[^\n]s", miasto);
    result result2 = ucz_m(uczelnie, ilosc, miasto);
    if(result2.ilosc) {
        printf("\n\nUczelnie w miescie '%s':\n", miasto);
        for(int l = 0; l < result2.ilosc; l++) {
            printf("Uczelnia nr %d\n", l+1);
            printf("\tmiasto: %s\n", result2.lista[l].miasto);
            printf("\ttyp: %s\n", result2.lista[l].typ);
            printf("\tstudentow: %d\n", result2.lista[l].L_s);
            printf("\twydzialow: %d\n\n", result2.lista[l].L_w);
        }
    } else {
        printf("\nBrak uczelni w miescie '%s'\n", miasto);
    }
    return 0;
}
int ile_s(uczelnia *uczelnie, int ilosc) {
    int studenci = 0;
    for(int i = 0; i < ilosc; i++) {
        studenci += uczelnie[i].L_s;
    }
    return studenci;
}
result ucz_wydz(uczelnia *uczelnie, int ilosc) {
    result result;
    result.ilosc = 0;
    for(int i = 0; i < ilosc; i++) {
        if(uczelnie[i].L_w > 3) {
            result.ilosc++;
        }
    }
    result.lista = calloc(sizeof(uczelnia), result.ilosc);
    int pos = 0;
    for(int i = 0; i < ilosc; i++) {
        if(uczelnie[i].L_w > 3) {
            result.lista[pos++] = uczelnie[i];
        }
    }
    return result;
}
result ucz_m(uczelnia *uczelnie, int ilosc, char *miasto) {
    result result;
    result.ilosc = 0;
    for(int i = 0; i < ilosc; i++) {
        if(strcmp(uczelnie[i].miasto, miasto) == 0) {
            result.ilosc++;
        }
    }
    result.lista = malloc(sizeof(uczelnia) * result.ilosc);
    int pos = 0;
    for(int i = 0; i < ilosc; i++) {
        if(strcmp(uczelnie[i].miasto, miasto) == 0) {
            result.lista[pos++] = uczelnie[i];
        }
    }
    return result;
}
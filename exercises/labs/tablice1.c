#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "tablice 1"

void print_author_info(void);
struct size_sum licz_srednia(float* tab, int n);
struct size_sum licz_iloczyn(float* tab, int n);

struct size_sum {
    int size;
    float sum;
};


// 1. Proszę wczytać dane, obliczyć i wyświetlić:
// • Średnią arytmetyczną liczb mniejszych od T[N-1].
// • Iloczyn liczb z przedziału <T[0],T[1]>


int main() { 
    print_author_info();

    int n, i;
    
    printf("Podaj długość tablicy: ");
    scanf("%d", &n);
    printf("Długość: %d\n", n);

    float tab1[n];

    for (i=0; i<n; i++) {
        printf("Podaj element tablicy:"); 
        scanf("%f", &tab1[i]);
    }
    struct size_sum srednia = licz_srednia(tab1, n);
    struct size_sum iloczyn = licz_iloczyn(tab1, n);
    

    printf("ŚREDNIA\n");
    printf("\tSuma: %f\n", srednia.sum);
    printf("\tRozmiar: %d\n", srednia.size);
    if(srednia.size) {
        printf("\tŚrednia liczb mniejszych od T[N-1]: %f\n", srednia.sum/srednia.size);
    } else {
        printf("\tBrak liczb mniejszych od T[N-1], zatem brak średniej\n");
    }


    printf("ILOCZYN\n");
    printf("\tSuma: %f\n", iloczyn.sum);
    printf("\tRozmiar: %d\n", iloczyn.size);

    if(iloczyn.size) {
        printf("\tIloczyn liczb z przedziału <T[0],T[1]>: %f\n", iloczyn.sum);
    } else {
        printf("\tBrak liczb z przedziału <T[0],T[1]>, zatem brak średniej\n");
    }

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}

struct size_sum licz_srednia(float tab[], int n) {
    struct size_sum basic = { 0, 0.0 };
    int i;

    for (i=0; i<n; i++) {
        if(tab[i] < tab[n-1]) {
            basic.size++;
            basic.sum += tab[i];
        }
    }

    return basic;
}

struct size_sum licz_iloczyn(float tab[], int n) {
    struct size_sum iloczyn = { 0, 1.0 };
    int i;

    for (i=0; i<n; i++) {
        if(tab[i] >= tab[0] && tab[i] <= tab[1]) {
            iloczyn.size++;
            iloczyn.sum *= tab[i];
        }
    }

    return iloczyn;
}
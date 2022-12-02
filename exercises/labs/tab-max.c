#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char choose_option(float tab[], int dlugosc, float liczba);
float maks(float tab[], int dlugosc);
int wm(float tab[], int dlugosc, float liczba);
float* new_tab(float* tab, int n);


int main() {
    int option, n, i;
    float liczba;

    printf("Podaj 'n' elementów: ");
    scanf("%d", &n);
    
    printf("Podaj parametr: ");
    scanf("%f", &liczba);

    float tab[n];

    for (i=0; i<n; i++) {
        printf("Podaj element tablicy:"); 
        scanf("%f", &tab[i]);
    }

    option = choose_option(tab, n, liczba);

    return 0;
}

char choose_option(float tab[], int dlugosc, float liczba) {
    int opt;
    float *X;

    printf("Podaj opcje: ");
    scanf("%d", &opt);
    while(opt != 999) {
        switch (opt) {
            case 1:
                printf("Opcja 1: Maks \n");
                printf("Maksymalna wartosc: %f \n", maks(tab, dlugosc));
                opt = -1;
                break;
            case 2:
                printf("Opcja 2: wm \n");
                printf("Ile liczb wiekszych od parametru: %d \n", wm(tab, dlugosc, liczba));
                opt = -1;
                break;
            case 3:
                printf("Opcja 3: new_tab \n");
                X = new_tab(tab, dlugosc);
                for(int i = 0; i < dlugosc; i++) {
                    printf("%f \t", X[i]);
                }
                printf("\n");
                opt = -1;
                break;

            case 0:
                printf("Wychodzę \n");
                return opt;
            
            default:
                printf("\nPodaj opcje 1-3 lub 0, żeby wyjść: ");
                scanf("%d", &opt);
                break;
        }
    }
}

float maks(float tab[], int dlugosc) {
    float max = 0;
    for(int i = 0; i < dlugosc; i++) {
        if(tab[i] > max) {
            max = tab[i];
        }
    }

    return max;
}

int wm(float tab[], int dlugosc, float liczba) {
    int ilosc = 0;
    for(int i = 0; i < dlugosc; i++) {
        if(tab[i] > liczba) {
            ilosc++;
        }
    }

    return ilosc;
}

float* new_tab(float* tab, int n) {
    float* nt = malloc(sizeof(float) * n);

    for (int i=0; i<n; i++) {
        if(tab[i] < 100) {
            nt[i] = tab[i];
        } else {
            nt[i] = tab[i] * 0.9;
        }
    }

    return nt;
}
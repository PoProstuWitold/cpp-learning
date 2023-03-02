#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float* licz_bezwgledna(float tab1[], int n);
float* licz_odwrotna(float tab1[], int n);

// 2. Utworzyć i wyświetlić 2 nowe tablice: 
// • X składa się z wartości bezwzględnych elementów T, 
// • Y składa się z elementów T zapisanych w odwrotnej kolejności. 

int main() {
    int n, i;
    printf("Podaj długość tablicy: ");
    scanf("%d", &n);
    printf("Długość: %d\n", n);
    float T[n], *X, *Y;
    for (i=0; i<n; i++) {
        printf("Podaj element tablicy:"); 
        scanf("%f", &T[i]);
    }
    X = licz_bezwgledna(T, n);
    Y = licz_odwrotna(T, n);
    printf("Tablica podstawowa\n \t");
    for(i=0; i<n; i++) {
        printf("%f\t", T[i]);
    }
    printf("Tablica bezwględna\n \t");
    for(i=0; i<n; i++) {
        printf("%f\t", X[i]);
    }
    printf("Tablica odwrotna\n \t");
    for(i=0; i<n; i++) {
        printf("%f\t", Y[i]);
    }
    return 0;
}

float* licz_bezwgledna(float tab1[], int n) {
    int i;
    float* tab2 = malloc(sizeof(float) * n);
    for (i=0; i<n; i++) {
        tab2[i] = fabs(tab1[i]);
    }
    return tab2;
}

float* licz_odwrotna(float tab1[], int n) {
    int i;
    float* tab2 = malloc(sizeof(float) * n);
    for (i=0; i<n; i++) {
        tab2[i] = tab1[n-i-1];
    }
    return tab2;
}
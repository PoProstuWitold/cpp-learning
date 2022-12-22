#include <stdio.h>
#include <stdlib.h>
// DRUGIE KOLOKWIUM 23-24 stycznia
// 1. Dane: tablica liczbowa 2-wymiarowa.
// Proszę wyznaczyć wartość max, liczbę wystąpień tej wartości oraz utworzyć tablicę 2-wymiarową (2 
// wiersze lub 2 kolumny) zawierającą indeksy elem. maksymalnych.

int main(void) {
    int rows = 4;
    int cols = 4;

    int tablica[rows][cols];
    int max_value, max_count;
    int max_index_tab[2][rows * cols];

    int i, j, k;

    // Wczytaj tablicę 2-wymiarową
    printf("Wczytywanie tablicy dwuwymiarowej o wymiarach [%d][%d] \n", rows, cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Podaj element [%d][%d]: ", i, j);
            scanf("%d", &tablica[i][j]);
        }
    }


    // Znajdź maksymalną wartość oraz liczbę jej wystąpień
    max_value = tablica[0][0];
    max_count = 1;
    max_index_tab[0][0] = 0;
    max_index_tab[1][0] = 0;
    k = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (tablica[i][j] > max_value) {
                max_value = tablica[i][j];
                max_count = 1;
                max_index_tab[0][0] = i;
                max_index_tab[1][0] = j;
                k = 1;
            } else if (tablica[i][j] == max_value) {
                max_count++;
                max_index_tab[0][k] = i;
                max_index_tab[1][k] = j;
                k++;
            }
        }
    }

    // Wyświetl wynik
    printf("Maksymalna wartość: %d\n", max_value);
    printf("Liczba wystąpień: %d\n", max_count);
    printf("Indeksy elementów maksymalnych:\n");
    
    for (i = 0; i < k; i++) {
        printf("[%d][%d]\n", max_index_tab[0][i], max_index_tab[1][i]);
    }

    return 0;
}
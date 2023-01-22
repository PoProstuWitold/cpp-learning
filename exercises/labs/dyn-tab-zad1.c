// DRUGIE KOLOKWIUM 23-24 stycznia
// 1. Dane: tablica liczbowa 2-wymiarowa.
// Proszę wyznaczyć wartość max, liczbę wystąpień tej wartości oraz utworzyć tablicę 2-wymiarową (2 
// wiersze lub 2 kolumny) zawierającą indeksy elem. maksymalnych.#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 2

int** find_max(float array[ROWS][COLS], int* max, int* count);
void print_results(int max, int count, int** indices);

int main(void) {

    float T[ROWS][COLS];
    int max_index_tab[2][ROWS * COLS];
    
    int i, j, k;

    // Wczytaj tablicę 2-wymiarową
    printf("Wczytywanie tablicy dwuwymiarowej o wymiarach [%d][%d] \n", ROWS, COLS);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Podaj element [%d][%d]: ", i, j);
            scanf("%f", &T[i][j]);
        }
    }

    // Tablica
    printf("\nTABLICA\n"); 
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%.2f\t",T[i][j]);
            printf("\n\n"); 
    } 

    // Maksymalna wartość i ilość jej wystąpień
    int max = T[0][0];
    int count = 0;
    int** indices;

    indices = find_max(T, &max, &count);

    // Wypisujemy wyniki
    print_results(max, count, indices);

    return 0;
}

int** find_max(float array[ROWS][COLS], int* max, int* count) {
    // Alokujemy pamięć dla tablicy indeksów
    int** indices = (int**) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        indices[i] = (int*) malloc(sizeof(int) * COLS);
    }

    // Szukamy maksymalnej wartości i liczymy jej wystąpienia
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] > *max) {
                *max = array[i][j];
                *count = 1;
            } else if (array[i][j] == *max) {
                (*count)++;
            }
        }
    }

    // Zapisujemy indeksy elementów maksymalnych do tablicy
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == *max) {
                indices[i][j] = 1;
            } else {
                indices[i][j] = 0;
            }
        }
    }

    return indices;
}

void print_results(int max, int count, int** indices) {
    // Wypisujemy wyniki
    printf("Maksymalna wartość: %d\n", max);
    printf("Liczba wystąpień: %d\n", count);
    printf("Indeksy elementów maksymalnych:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(indices[i][j] == 1) {
                printf("(%d)\t", indices[i][j]);
            }
            if(indices[i][j] != 1) {
                printf("%d\t", indices[i][j]);
            }
        }
        printf("\n\n");
    }
    
}
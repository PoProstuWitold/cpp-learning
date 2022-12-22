// 2. Dane: tablica liczbowa 1-wymiarowa.
// Proszę utworzyć tablicę 2-wymiarową (2 wiersze lub 2 kolumny) 
// zawierającą pojedyncze wystąpienia 
// liczb z danej tablicy oraz ile razy dana liczba wystąpiła.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maksymalny rozmiar tablicy

// Funkcja tworząca tablicę wyjściową z podanej tablicy wejściowej
void create_output_array(int input[], int size, int output[][2]) {
    int i, j;  // Zmienne pętli

    // Inicjalizuj tablicę wyjściową
    for (i = 0; i < size; i++) {
        output[i][0] = input[i];
        output[i][1] = 1;
    }

    // Sprawdź, ile razy każda liczba wystąpiła
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i != j && input[i] == input[j]) {
                output[i][1]++;
            }
        }
    }
}

int main() {
    int input[MAX_SIZE];  // Tablica wejściowa
    int output[MAX_SIZE][2];  // Tablica wyjściowa (2 kolumny: liczba i ilość wystąpień)
    int size;  // Aktualny rozmiar tablicy wejściowej
    int i;  // Zmienna pętli

    // Wczytaj rozmiar tablicy wejściowej
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &size);

    // Wczytaj elementy tablicy wejściowej
    printf("Podaj elementy tablicy (po spacji): ");
    for (i = 0; i < size; i++) {
        scanf("%d", &input[i]);
    }

    // Stwórz tablicę wyjściową
    create_output_array(input, size, output);

    // Wypisz tablicę wyjściową
    printf("Tablica wyjściowa:\n");
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", output[i][0], output[i][1]);
    }

    return 0;
}

// Jeżeli znamy rozmiar tablicy możemy ją zadeklarować statycznie, wstawić jako nie-wskaźnikowy parametr funkcji.
// 1.
// Baza danych: liczba pracowników (nazwiska, płace). Organizacja danych dowolna.
// Funkcjonalności systemu informatycznego:
// - wprowadzenie danych (main)
// - raport1 (funkcja) zwraca sumę płac i średnią płac, wyświetlanie wyników w main
// - raport2 (funkcja) wyświetla nazwiska i płace pracowników, którzy zarabiają więcej niż wartość podana w parametrach.
// Proszę napisać ten system informatyczny.

#include <stdio.h>
#include <stdlib.h>

typedef struct Pracownik {
    char lastname[50];
    float salary;
} pracownik;

typedef struct Raport {
    float sum;
    float avg;
} raport;

raport raport1(pracownik pracownicy[], int size) {
    raport result;

    result.sum = 0;
    result.avg = 0;

    for(int i = 0; i < size; i++) {
        result.sum += pracownicy[i].salary;
    }

    result.avg = result.sum / size;

    return result;
}

void raport2(pracownik pracownicy[], int size, float threshold) {
    printf("Nazwiska i płace pracowników zarabiających powyżej %f:\n", threshold);
    for(int i = 0; i < size; i++) {
        if(pracownicy[i].salary > threshold) {
            printf("%s: %f\n", pracownicy[i].lastname, pracownicy[i].salary);
        }
    }
}

int main() {
    int size;

    printf("Ile pracowników chcesz wprowadzić? ");
    scanf("%d", &size);

    pracownik pracownicy[size];

    for(int i = 0; i < size; i++) {
        // printf("Podaj nazwisko i płacę pracownika nr %d (oddzielone spacją): ", i+1);
        // scanf("%s %f", &pracownicy[i].lastname, &pracownicy[i].salary);

        printf("Podaj nazwisko pracownika nr %d: ", i+1);
        scanf("%s", &pracownicy[i].lastname);

        printf("Podaj płacę pracownika nr %d: ", i+1);
        scanf("%f", &pracownicy[i].salary);
    }

    raport rap = raport1(pracownicy, size);

    printf("Suma płac: %f\n", rap.sum);
    printf("Średnia płaca: %f\n", rap.avg);

    float threshold;

    printf("Podaj prog płacowy: ");

    scanf("%f", &threshold);
    raport2(pracownicy, size, threshold);

    return 0;
}
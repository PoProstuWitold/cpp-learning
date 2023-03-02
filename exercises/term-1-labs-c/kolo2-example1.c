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
raport raport1(pracownik *pracownicy, int size) {
    raport result;
    result.sum = 0;
    result.avg = 0;
    for(int i = 0; i < size; i++) {
        result.sum += pracownicy[i].salary;
    }
    result.avg = result.sum / size;
    return result;
}
void raport2(pracownik *pracownicy, int size, float threshold) {
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
    // pracownik *pracownicy = (pracownik *)malloc(size * sizeof(pracownik));
    pracownik *pracownicy = calloc(size, sizeof(pracownik));
    for(int i = 0; i < size; i++) {
        // printf("Podaj nazwisko i płacę pracownika nr %d (oddzielone spacją): ", i+1);
        // scanf("%s %f", &pracownicy[i].lastname, &pracownicy[i].salary);
        printf("Podaj nazwisko pracownika nr %d: ", i+1);
        scanf(" %49[^\n]s", pracownicy[i].lastname);
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
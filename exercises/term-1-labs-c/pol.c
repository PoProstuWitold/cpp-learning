#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struktura pole tekstowe, liczbowe float
// funkcja oblicza ile razy jest pole tekstowe = nazwa i liczy ile ta nazwa się powtarza

typedef struct S1 {
    char tekst[20];
    float liczba;
} s1;

int ile_razy(s1 *tablica, int n, const char *tekst);

int main() {
    int n;
    printf("Podaj n: ");
    scanf("%d", &n);
    s1 *tablica = (s1*)malloc(n * sizeof(s1));

    for(int i = 0; i < n; i++) {
        printf("Podaj teskts %d: ", i+1);
        scanf(" %19[^\n]s", tablica[i].tekst);
        printf("Podaj liczbe %d: ", i+1);
        scanf("%f", &tablica[i].liczba);
    }

    char tekst[20];

    printf("Podaj szukane slowo: ");
    scanf(" %19[^\n]s", &tekst);
    if(ile_razy(tablica, n, tekst))
        printf("Slowo '%s' wystepuje %d razy", tekst, ile_razy(tablica, n, tekst));
    else
        printf("Slowo nie wystepuje");

    return 0;
}

int ile_razy(s1 *tablica, int n, const char *tekst) {
    int ilosc = 0;
    for (int i = 0; i < n; ++i) {
        if (!strcmp(tekst, tablica[i].tekst)) {
            ++ilosc;
        }
            
    }
    return ilosc;
}
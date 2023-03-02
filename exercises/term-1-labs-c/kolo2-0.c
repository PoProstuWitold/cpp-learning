// 1.
// Baza danych: liczba pracowników (nazwiska, płace). Organizacja danych dowolna.
// Funkcjonalności systemu informatycznego:
// - wprowadzenie danych (main)
// - raport1 (funkcja) zwraca sumę płac i średnią płac, wyświetlanie wyników w main
// - raport2 (funkcja) wyświetla nazwiska i płace pracowników, którzy zarabiają więcej niż wartość podana w parametrach.
// Proszę napisać ten system informatyczny.

// Biblioteki
#include <stdio.h>
#include <stdlib.h>

// "Typ string"
typedef char * str;

// Struktury z użyciem "typu string"
// dzięki takiemu zapisowi możemy w kodzie odwoływać się do struktury
// pisząc "nazwa_struktury" zamiast "struct nazwa_struktury"
typedef struct pracownik {
    str nazwisko;
    float placa;
} pracownik;

typedef struct pracownicy {
    pracownik * tablica;
    int ilosc;
} pracownicy;

typedef struct s1 {
    float suma;
    float srednia;
} s1;

// Raport zwracający strukturę "s1":
// np. wynik: { suma: "100", srednia: "25" }
s1 raport1(pracownicy pracownicy) {
    s1 wynik;
    wynik.suma = 0;
    wynik.srednia = 0;

    for (int i = 0; i < pracownicy.ilosc; i++) {
        wynik.suma += pracownicy.tablica[i].placa;
    }

    if (pracownicy.ilosc > 0) {
        wynik.srednia = wynik.suma / pracownicy.ilosc;
    }

    return wynik;
}

// drukowanie każdego pracownika i jego płacy
void raport2(pracownicy pracownicy, float wartosc) {
    printf("\nLista pracownikow zarabiajacyh wiecej niz '%f'\n", wartosc);
    for (int i = 0; i < pracownicy.ilosc; i++) {
        if (pracownicy.tablica[i].placa > wartosc) {
            printf("nazwisko: %s, placa: %f\n", pracownicy.tablica[i].nazwisko, pracownicy.tablica[i].placa);
        }
    }
}

// void wprowadz_pracownikow(pracownicy pracownicy) {
//     for (int i = 0; i < pracownicy.ilosc; i++) {
//         printf("\nPodaj nazwisko pracownika %i: ", i + 1);
//         scanf("\n%m[^\n]", &pracownicy.tablica[i].nazwisko);
//         printf("Podaj place pracownika %i: ", i + 1);
//         scanf("%f", &pracownicy.tablica[i].placa);
//     }
// }

int main() {
    float wartosc;
    pracownicy pracownicy;
    s1 rap1;

    printf("Podaj ilosc pracownikow: ");
    scanf("%i", &pracownicy.ilosc);

    pracownicy.tablica = calloc(pracownicy.ilosc, sizeof(pracownik));

    // wprowadz_pracownikow(pracownicy);
    for (int i = 0; i < pracownicy.ilosc; i++) {
        printf("\nPodaj nazwisko pracownika %i: ", i + 1);
        scanf("\n%m[^\n]", &pracownicy.tablica[i].nazwisko);
        printf("Podaj place pracownika %i: ", i + 1);
        scanf("%f", &pracownicy.tablica[i].placa);
    }

    rap1 = raport1(pracownicy);

    printf("\nSuma plac: %f, Srednia plac: %f \n", rap1.suma, rap1.srednia);
    printf("\nPodaj szukana wartosc: ");
    scanf("%f", &wartosc);
    
    raport2(pracownicy, wartosc);

    return 0;
}
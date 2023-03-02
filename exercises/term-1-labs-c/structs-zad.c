#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct HURT {
    char * nazwa;
    int ilosc;
    double cena;
};
void wypelnij(struct HURT *ts, int n);
int maksymalna_cena(const struct HURT *ts, int n);
double srednia_wartosc(const struct HURT *ts, int n);
int ilosc_o_nazwie(const struct HURT *ts, int n, const char *s);
int main() {
    int n, max_ind;
    char * nazwa;
    struct HURT *tablica_struktur;
    printf("Podaj n: ");
    scanf("%d", &n);
    while (n < 0) {
        printf("n nie moze byc '<0': ");
        scanf("%d", &n);
    }
    tablica_struktur = (struct HURT *)malloc(n * sizeof(struct HURT));
    wypelnij(tablica_struktur, n);
    max_ind = maksymalna_cena(tablica_struktur, n);
    printf("\nTowar \"%s\" o najwiekszej cenie: %.2lf, ilosc: %d\n", tablica_struktur[max_ind].nazwa, tablica_struktur[max_ind].cena, tablica_struktur[max_ind].ilosc);
    printf("Srednia wartosc wszystkich towarow: %.2lf\n", srednia_wartosc(tablica_struktur, n));
    printf("\nPodaj nazwe towaru do wyszukania: ");
    scanf("\n%m[^\n]", &nazwa);
    printf("\nIlosc towaru o nazwie \"%s\": %d\n", nazwa, ilosc_o_nazwie(tablica_struktur, n, nazwa));
    return 0;
}
void wypelnij(struct HURT *ts, int n) {
    for (int i = 0; i < n; ++i) {
        printf("\nPodaj nazwe towaru: ");
        scanf("\n%m[^\n]", &ts[i].nazwa);
        printf("Podaj ilosc towaru: ");
        scanf("%d", &ts[i].ilosc);
        printf("Podaj cene towaru: ");
        scanf("%lf", &ts[i].cena);
    }
}
int maksymalna_cena(const struct HURT *ts, int n) {
    int ind = 0;
    for (int i = 1; i < n; ++i)
        if (ts[i].cena > ts[ind].cena)
            ind = i;
    return ind;
}
double srednia_wartosc(const struct HURT *ts, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; ++i)
        suma += ts[i].cena;
    return suma/n;
}
int ilosc_o_nazwie(const struct HURT *ts, int n, const char *s) {
    int ilosc = 0;
    for (int i = 0; i < n; ++i)
        if (!strcmp(s, ts[i].nazwa))
            ++ilosc;
    return ilosc;
}
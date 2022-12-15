// Tablice znaków-teksty.
// biblioteka: <string.h>
// Funkcje obsługujące znaki i tablice znaków
// • wczytywanie i wyświetlanie znaku
// stdin-klawiatura, stdout-ekran
// scanf(”%c”, &znak); znak=getchar(); znak=getc(stdin);
// printf(”%c”, znak); putc(znak,stdout); 
// • sprawdzenie, czy znak jest cyfrą isdigit(znak);
// • sprawdzenie, czy znak jest literą isalpha(znak);
// • zamiana na dużą literę toupper(znak);
// • zamiana na małą literę tolower(znak);
// • wczytywanie i wyświetlanie tekstu 
// scanf(”%s”, tekst); gets(tekst) ; 
// fgets(tekst, liczba_znaków, stdin); 
// printf(”%s”, znak); puts(tekst);
// • wyznaczenie długości tekstu dlugosc=strlen(tekst)
// • kopiowanie tekst2->tekst1 strcpy(tekst1, tekst2);
// • łączenie tekst1+tekst2 ->tekst1 strcat(tekst1, tekst2);
// • porównanie tekst1 z tekst2 strcmp(tekst1 , tekst2); 
// uwaga: jeśli teksty są takie same, to wynik funkcji 0
// • zamiana tekstu na liczbę typu int atoi(tekst);
// • zamiana tekstu na liczbę typu float atof(tekst);
// • zamiana liczby całkowitej x na tekst T sprintf(T,"%d",x);
// uwaga: funkcja sprintf jest „przestarzała”, ale b. prosta …

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Zadanie 1: wyszukiwanie znaku w tekście
int main(int argc, char *argv[]) { 
    char napis[20]; //tekst max 20 znakow
    char z; // 1 znak
    int i, n, k=0;

    printf(" wpisz tekst ");
    gets(napis); // pobieranie tekstu z klawiatury do wciśnięcia ENTER

    printf("wpisz szukany znak ");
    scanf("%c", &z); //pobranie 1 znaku zakończonego ENTER
    n=strlen(napis); //n=liczba znakow w tekscie

    for (i=0; i<n; i++)
        if (napis[i]==z) k++; // napis[i]= znak nr i 
        if (k!=0)
            printf(" w tekscie %s znak %c wystepuje %d raz(y)\n", napis, z, k);
        else 
            printf(" w tekscie %s znak %c nie wystepuje\n", napis, z);

    return 0;
}

// Zadanie 2: połączenie kilku tekstów w jeden tekst
int main(int argc, char *argv[]) { 
    char miasto[20], ulica[20], nr_domu[10], adres[50]; 

    printf(" miasto: ");
    gets(miasto); 

    printf(" ulica: ");
    gets(ulica);

    printf(" nr domu: ");
    gets(nr_domu); 

    strcpy(adres, miasto); //wpisanie miasta do adres
    strcat(adres, "\n"); //dopisanie znaku nowego wiersza na koncu adresu(miasta)
    strcat(adres, ulica); //dopisanie ulicy na koncu adresu (w nowym wierszu)
    strcat(adres, " "); //dopisanie spacji na koncu adresu(ulicy)
    strcat(adres, nr_domu); //dopisanie nr na koncu adresu(po spacji)

    printf("adres:\n");
    printf(adres); 

    // lub puts(adres); lub printf("%s", adres);
    printf("\n");

    return 0;
}
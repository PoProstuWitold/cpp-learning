// Tablice znaków

// Proszę napisać programy realizujące następujące zadania:

// 1. Wczytać imię i nazwisko, wyświetlić dużymi literami inicjały. 

// 2. Wczytać ciąg znaków. Wyświetlić ilość liter i ilość cyfr.

// 3. Wczytać tablicę n wierszy zawierającą w każdym wierszu liczbę całkowitą zapisaną
// jako tekst. Utworzyć z tych danych tablicę typu int, obliczyć sumę tych liczb,
// wyświetlić sumę.

// 4. Wczytać tablicę n wierszy zawierającą w każdym wierszu dane: nr grupy spacja
// nazwisko spacja imię. Dopuszczalny nr: 1 lub 2. Utworzyć oddzielne tablice dla
// każdej grupy, w których wiersz zawiera tylko nazwisko spacja imię. Wyświetlić
// wyniki.


// 1.
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {

//     char imie[20], nazwisko[20];

//     printf("podaj imie: ");
//     gets(imie); // pobieranie tekstu z klawiatury do wciśnięcia ENTER

//     printf("podaj nazwisko: ");
//     gets(nazwisko); // pobieranie tekstu z klawiatury do wciśnięcia ENTER

//     for(int i = 0; imie[i]; i++){
//         imie[i] = tolower(imie[i]);
//     }

//     for(int i = 0; nazwisko[i]; i++){
//         nazwisko[i] = tolower(nazwisko[i]);
//     }

//     imie[0] = toupper(imie[0]);
//     nazwisko[0] = toupper(nazwisko[0]);

//     printf("%s %s \n", imie, nazwisko);

//     return 0;
// }


// 2.
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main()
// {
//     char str[100];
//     int litery, naturalne, specjalne, i;
//     litery = naturalne = specjalne = i = 0;


//     printf("Ilosc liter, cyfr i znakow specjalnych \n");
//     printf("Podaj dowolny ciag znakow: ");
//     gets(str);


//     while(str[i]!='\0') {
//         if(isalpha(str[i])) {
//             litery++;
//         }
//         else if(isdigit(str[i])) {
//             naturalne++;
//         }
//         else {
//             specjalne++;
//         }

//         i++;
//     }

//     printf("podany ciag znakow: %s\n", str);
//     printf("ilosc liter: %d\n", litery);
//     printf("ilosc cyfr: %d\n", naturalne);
//     printf("ilosc znakow specjalnych: %d\n\n", specjalne);

//     return 0;
// }


// 3.
// 3. Wczytać tablicę n wierszy zawierającą w każdym wierszu liczbę całkowitą zapisaną
// jako tekst. Utworzyć z tych danych tablicę typu int, obliczyć sumę tych liczb,
// wyświetlić sumę.
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main() { 
//     int i, w, k, size = 0;
//     float sum;

//     printf("dlugosc slow ");
//     scanf("%d",&w);

//     printf("ilosc slow ");
//     scanf("%d",&k);

//     char strings[w][k];
//     int ints[k];

//     printf("\nwymiary tablicy: [dlugosc][ilosc] slow [%d][%d] \n", w, k);

//     for(i=0;i<k;i++) {
//         printf("Podaj %d. slowo: ", i+1);
//         scanf("%s[^\n]",strings[i]);
//     }

//     printf("\ntablica stringów\n"); 
//     for(i=0;i<k;i++) {
//         puts(strings[i]);
//     }


//     for(i=0;i<k;i++) {
//         ints[i] = atoi(strings[i]);
//         sum += ints[i];
//         size++;
//     }

    
//     printf("\ntablica intów\n"); 
//     for(i=0;i<k;i++) {
//         printf("%d\n", ints[i]);
//     }
//     printf("suma intów: %f", sum/size);

//     return 0;
// }


// 4. Wczytać tablicę n wierszy zawierającą w każdym wierszu dane: nr grupy spacja
// nazwisko spacja imię. Dopuszczalny nr: 1 lub 2. Utworzyć oddzielne tablice dla
// każdej grupy, w których wiersz zawiera tylko nazwisko spacja imię. Wyświetlić
// wyniki.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() { 
    int i, w, k;

    // printf("dlugosc slow ");
    // scanf("%d",&w);

    // printf("ilosc slow ");
    // scanf("%d",&k);
    w = 0;
    k = 3;

    char strings[w][k];
    int ints[k];

    printf("\nwymiary tablicy: [dlugosc][ilosc] slow [%d][%d] \n", w, k);

    for(i=0;i<k;i++) {
        printf("Podaj %d. slowo: ", i+1);
        scanf("%100[0-9a-zA-Z ]", strings[i]);
    }

    printf("\ntablica stringów\n"); 
    for(i=0;i<k;i++) {
        puts(strings[i]);
    }

    return 0;
}
// Wskaźnik to zmienna przechowująca adres zmiennej
// 1) Czym różni się zmienna statyczna od zmiennej wskaźnikowej?
// Odpowiedź:
// Zmienna statyczna to zmienna, która jest inicjalizowana tylko raz, na początku programu, 
// i jej wartość pozostaje stała przez cały czas trwania programu. 
// Zmienna wskaźnikowa to zmienna, która zawiera adres pamięci innej zmiennej lub obiektu.

// 2) Do czego służy operator *?
// Odpowiedź:
// Operator * służy do dereferencji wskaźnika, WYŁUSKANIA WARTOŚCI 
// czyli odwołania się do wartości przechowywanej 
// w pamięci pod adresem wskazywanym przez wskaźnik.

// 3) Do czego służy operator &?
// Odpowiedź:
// Operator & służy do uzyskania adresu pamięci zmiennej lub obiektu WYŁUSKANIA ADRESU

// 4) Jak zdefiniować wskaźnik na tablicę jednowymiarową, a jak na dwuwymiarową?
// Odpowiedź:
// Aby zdefiniować wskaźnik na tablicę jednowymiarową w C++, należy napisać:
// typ_danych *nazwa_wskaznika;
// typ_danych nazwa_tablicy[rozmiar];
// nazwa_wskaznika = nazwa_tablicy;
// Natomiast aby zdefiniować wskaźnik na tablicę dwuwymiarową, należy napisać:
// typ_danych (*nazwa_wskaznika)[rozmiar2];
// typ_danych nazwa_tablicy[rozmiar1][rozmiar2];
// nazwa_wskaznika = nazwa_tablicy;

// 5) W jaki sposób przekazać zmienną statyczną do funkcji tak, aby po wyjściu z funkcji 
// wyniki dokonanych modyfikacji zostały zachowane?
// Odpowiedź:
// Aby przekazać zmienną statyczną do funkcji tak, 
// aby po wyjściu z funkcji wyniki dokonanych modyfikacji 
// zostały zachowane, należy przekazać ją przez referencję:
// void funkcja(int &zmienna_statyczna) {
//     // modyfikacja zmiennej statycznej
// }
// int main() {
//     static int zmienna = 0;
//     funkcja(zmienna);
//     // zmienna zostanie zmodyfikowana
//     return 0;
// }

// 6) Jak jest zbudowana funkcja?
// Odpowiedź:
// Funkcja to blok kodu, który wykonuje określone zadanie. 
// Funkcja może przyjmować argumenty, zwracać wartość i wywoływać inne funkcje.

// 7) Jak wygenerować liczby naturalne pseudolosowe z danego przedziału?
// Odpowiedź:
// Aby wygenerować liczby naturalne pseudolosowe z danego przedziału w C++, 
// można użyć funkcji rand() z biblioteki <cstdlib>:
// #include <cstdlib>
// int main() {
//     int liczba = rand() % (przedzial_gorny - przedzial_dolny + 1) + przedzial_dolny;
//     return 0;
// }

// 8) W jaki sposób znaleźć element maksymalny w tablicy?
// Odpowiedź:
// Aby znaleźć element maksymalny w tablicy w C++, można napisać pętlę for, 
// która porównuje każdy element z poprzednio znalezionym maksimum:
// int maksimum = tablica[0];
// for(int i=1; i<rozmiar_tablicy; i++) {
//     if(tablica[i] > maksimum) {
//         maksimum = tablica[i];
//     }
// }

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int num1, num2;
    int *ptr1, *ptr2, sum;

    // Pobierz dwie liczby od użytkownika
    cout << "Podaj dwie liczby całkowite: ";
    // cin >> num1 >> num2;
    num1 = 5;
    num2 = 8;

    // Ustaw wskaźniki na adresy zmiennych num1 i num2
    ptr1 = &num1;
    ptr2 = &num2;

    // Oblicz sumę liczb przy użyciu wskaźników
    sum = *ptr1 + *ptr2;

    // Wyświetl sumę liczb
    cout << "Suma tych liczb to: " << sum << endl;

    srand(time(0));  // Initialize random number generator.    

    // Random float from 2.2 to 4.4
    cout <<"Random float number generated between 2.2 and 4.4:" << endl;
    cout << 2.2 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(4.4-2.2))) << endl; 

    int n = 5;
    int x = 10;
    int y = 1;
    //Generacja liczb całkowitych z zakresu od 0 do n-1:
    int liczba1=rand()%n;
    //Generacja liczb całkowitych z zakresu od a do b:
    int liczba2=rand()%(x-y+1)+y;

    int a;
    a = 4;
    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    cout << "*&a: " << *&a << endl;
    int *b = new int;
    *b = 6;
    cout << "*b: " << *b << endl;
    cout << "b: " << b << endl;
    cout << "&b: " << &b << endl;
    cout << "*&b: " << *&b << endl;
    cout << "&*b: " << &*b << endl;
    delete b;

    int *d;
    int *e;
    d = b;
    cout << "b,d: " << b << "," << d << endl;
    cout << "*b,*d: " << *b << "," << *d << endl;
    e = &a;
    cout << "e,&a: " << e << "," << &a << endl;
    cout << "*e,a: " << *e << "," << a << endl;
        

    return 0;
}
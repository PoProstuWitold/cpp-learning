// LABORATORIUM 1. PROSTE ALGORYTMY REALIZUJĄCE: MIN, MAX, ŚREDNIA

// Pytania kontrolne:
// 1) Czym różni się zmienna statyczna od zmiennej wskaźnikowej?
// 2) Do czego służy operator *?
// 3) Do czego służy operator &?
// 4) Jak zdefiniować wskaźnik na tablicę jednowymiarową, a jak na dwuwymiarową?
// 5) W jaki sposób przekazać zmienną statyczną do funkcji tak, aby po wyjściu z funkcji 
// wyniki dokonanych modyfikacji zostały zachowane?
// 6) Jak jest zbudowana funkcja?
// 7) Jak wygenerować liczby naturalne pseudolosowe z danego przedziału?
// 8) W jaki sposób znaleźć element maksymalny w tablicy?

// odpowiedzi
// 1)
// Zmienna statyczna jest inicjalizowana tylko raz, podczas pierwszego wywołania funkcji 
// lub w momencie uruchomienia programu i przechowywana jest w pamięci programu przez cały czas jego działania. 

// Zmienna wskaźnikowa wskazuje na konkretny obszar pamięci programu i przechowuje adres tego obszaru, 
// co pozwala na manipulowanie wartością przechowywaną pod tym adresem.


// 2)
// Operator * służy do odwoływania się do wartości przechowywanej pod adresem wskazywanym przez zmienną wskaźnikową. 
// Na przykład, *ptr oznacza wartość przechowywaną pod adresem wskazywanym przez ptr.


// 3)
// Operator & służy do pobierania adresu zmiennej. Na przykład, &x zwraca adres zmiennej x.


// 4)
// Aby zdefiniować wskaźnik na tablicę jednowymiarową w C++, należy użyć następującej 
// składni: typ_danych *nazwa_tablicy. Na przykład, int *tablica.

// Aby zdefiniować wskaźnik na tablicę dwuwymiarową w C++, należy użyć następującej 
// składni: typ_danych (*nazwa_tablicy)[liczba_kolumn]. Na przykład, int (*tablica)[4].


// 5)
// Aby przekazać zmienną statyczną do funkcji tak, aby wyniki dokonanych modyfikacji zostały zachowane, 
// należy przekazać ją jako argument referencyjny. Na przykład, void funkcja(int &x) {}.


// 6)
// Funkcja składa się z nazwy, typu zwracanego, listy argumentów i ciała. Na przykład, int dodaj(int x, int y) { return x + y; }.


// 7)
// Aby wygenerować liczby naturalne pseudolosowe z danego przedziału, można użyć funkcji rand(), 
// która zwraca liczbę pseudolosową z zakresu od 0 do RAND_MAX. Aby ograniczyć zakres liczb, 
// można użyć operacji modulo i dodawania. Na przykład, aby wygenerować liczby pseudolosowe 
// z zakresu od 1 do 10, można użyć następującej formuły: (rand() % 10) + 1.


// 8)
// Aby znaleźć element maksymalny w tablicy, można przejść przez wszystkie jej elementy 
// i porównać każdy element z dotychczas znalezionym maksimum. Na przykład, można użyć następującego kodu:
int znajdz_max(int tablica[], int rozmiar) {
    int max = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (tablica[i] > max) {
            max = tablica[i];
        }
    }
    return max;
}
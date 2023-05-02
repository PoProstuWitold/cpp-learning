// LABORATORIUM 3. ALGORYTM SORTOWANIA QUICKSORT

// Pytania kontrolne:
// 1) W jaki sposób działa algorytm sortowania QuickSort?
// 2) Jaka jest złożoność czasowa algorytmu sortowania QuickSort?
// 3) W jaki sposób stworzyć strukturę?
// 4) W jaki sposób odwoływać się do elementów struktury? 
// 5) W jaki sposób odczytać dane z pliku?


#include <string>
using namespace std;

// 1)
// Algorytm sortowania QuickSort polega na dzieleniu tablicy na mniejsze podtablice, sortowaniu ich rekurencyjnie 
// i łączeniu ich w całość. W algorytmie QuickSort wybierany jest element nazywany "pivot", 
// po czym tablica zostaje podzielona na dwie części: pierwsza zawierająca elementy mniejsze od pivota, 
// druga zawierająca elementy większe od pivota. Następnie proces sortowania powtarza się rekurencyjnie 
// dla obu części tablicy aż do momentu, gdy wszystkie podtablice zostaną posortowane. Ostatecznie, 
// elementy zostają poskładane w całość w posortowanej kolejności.


// 2)
// Złożoność czasowa algorytmu QuickSort zależy od wyboru pivota i sposobu jego implementacji. 
// W najgorszym przypadku, gdy pivot jest wybierany jako element skrajny (najmniejszy lub największy) 
// i tablica jest już posortowana, złożoność czasowa wynosi O(n^2). Jednakże w przypadku, 
// gdy pivot jest wybierany średnio (np. jako mediana trzech losowych elementów), 
// złożoność czasowa wynosi O(n*log(n)).

// 3)
// Struktura w języku C++ definiowana jest za pomocą słowa kluczowego "struct". 
// Przykładowa definicja struktury może wyglądać tak:
struct Osoba {
    string imie;
    string nazwisko;
    int wiek;
};

// 4)
// Do odwoływania się do elementów struktury używa się operatora kropki ".". 
// Na przykład, aby odczytać imię osoby zdefiniowanej w powyższej strukturze, 
// można użyć wyrażenia "osoba.imie", gdzie "osoba" jest zmienną typu Osoba.
int example() {
    Osoba osoba1 = {
        .imie = "Witold",
        .nazwisko = "Zawada",
        .wiek = 19
    };

    cout << "Imie: " << osoba1.imie << endl;
    cout << "Nazwisko: " << osoba1.nazwisko << endl;
    cout << "Wiek: " << osoba1.wiek << endl;

    return 0;
}

// 5)
// Odczytywanie danych z pliku w języku C++ może odbyć się na kilka sposobów. 
// Jednym z nich jest użycie strumieni plików. 
// Przykładowy kod odczytujący dane z pliku tekstowego może wyglądać tak:
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string linia;
    ifstream plik("nazwa_pliku.txt");

    if (plik.is_open()) {
        while (getline(plik, linia)) {
            cout << linia << endl;
        }
        plik.close();
    }
    else {
        cout << "Nie udało się otworzyć pliku." << endl;
    }

    return 0;
}





#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// tablica 1D
void przydzielPamiec1D(int *&tab, int n);
void wypelnijTablice1D(int *tab, int n, int a, int b);
void usunTablice1D(int *&tab);
void wyswietl1D(int *tab, int n);

// tablica 2D
void przydzielPamiec2D(int **&tab, int w, int k);
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);
void usunTablice2D(int **&tab, int w);
void wyswietl2D(int **tab, int w, int k);

// utils
int getChoice();

// zadania
int zadanie_1_2();
int zadanie_1_3();
int zadanie_1_4();
int zadanie_1_5();


int main() {
    int n = 5; // rozmiar tablicy jednowymiarowej
    int w = 4; // liczba wierszy tablicy dwuwymiarowej
    int k = 5; // liczba kolumn tablicy dwuwymiarowej
    int a = 1; // dolna granica przedziału liczb generowanych do tablicy
    int b = 10; // górna granica przedziału liczb generowanych do tablicy

    bool arraysEnabled = false;
    if(arraysEnabled) {
        // przykład użycia funkcji
        int *tab1D;
        przydzielPamiec1D(tab1D, n);
        wypelnijTablice1D(tab1D, n, a, b);
        wyswietl1D(tab1D, n);
        usunTablice1D(tab1D);
        cout << endl;

        int **tab2D;
        przydzielPamiec2D(tab2D, w, k);
        wypelnijTablice2D(tab2D, w, k, a, b);
        wyswietl2D(tab2D, w, k);
        usunTablice2D(tab2D, w);
        cout << endl;
    }

    int wybor = getChoice();

    cout << "Twoj wybor to: " << wybor << ". ";

    switch (wybor) {
            case 1:
                zadanie_1_2();
                break;
            case 2:
                zadanie_1_3();
                break;
            case 3:
                zadanie_1_4();
                break;
            case 4:
                zadanie_1_5();
                break;
            case 5:
                // Wyjście z programu
                cout << "Koniec programu.\n";
                break;
            default:
                // Nieprawidłowy wybór
                cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
                break;
        }

    
    return 0;
}

int zadanie_1_2() {
    cout << "Zadanie 1.2: minimalny element" << endl;
    return 0;
}

int zadanie_1_3() {
    cout << "Zadanie 1.3: zliczanie elementów w tablicy" << endl;
    return 0;
}

int zadanie_1_4() {
    cout << "Zadanie 1.4: maksymalny element" << endl;
    return 0;
}

int zadanie_1_5() {
    cout << "Zadanie 1.5: średnia" << endl;
    return 0;
}

int getChoice() {
    int wybor;

    do {
        // Wyświetl menu
        cout << "Menu:\n"
             << "1) Zadanie 1.2\n"
             << "2) Zadanie 1.3\n"
             << "3) Zadanie 1.4\n"
             << "4) Zadanie 1.5\n"
             << "5) Wyjście z programu\n"
             << "Wybierz opcję: ";
        
        // Pobierz wybór użytkownika
        cin >> wybor;
    } while (false);

    return wybor;
}

// funkcja przydzielająca pamięć dla tablicy jednowymiarowej o rozmiarze n
void przydzielPamiec1D(int *&tab, int n) {
    cout << "[1D] Przydzielanie pamięci..." << endl;
    tab = new int[n];
}

// funkcja przydzielająca pamięć dla tablicy dwuwymiarowej o wymiarach w x k
void przydzielPamiec2D(int **&tab, int w, int k) {
    cout << "[2D] Przydzielanie pamięci..." << endl;
    tab = new int *[w];
    for (int i = 0; i < w; i++) {
        tab[i] = new int[k];
    }
}

// funkcja wypełniająca tablicę jednowymiarową tab wygenerowanymi liczbami z zakresu <a, b>
void wypelnijTablice1D(int *tab, int n, int a, int b) {
    cout << "[1D] Wypełnianie..." << endl;
    srand(time(nullptr)); // ustawienie ziarna generatora liczb pseudolosowych
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % (b - a + 1) + a;
    }
}

// funkcja wypełniająca tablicę dwuwymiarową tab wygenerowanymi liczbami z zakresu <a, b>
void wypelnijTablice2D(int **tab, int w, int k, int a, int b) {
    cout << "[2D] Wypełnianie..." << endl;
    srand(time(nullptr)); // ustawienie ziarna generatora liczb pseudolosowych
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

// funkcja zwalniająca pamięć zaalokowaną dla tablicy jednowymiarowej tab
void usunTablice1D(int *&tab) {
    cout << "[1D] Usuwanie..." << endl;
    delete[] tab;
    tab = nullptr;
}

// funkcja zwalniająca pamięć zaalokowaną dla tablicy dwuwymiarowej tab
void usunTablice2D(int **&tab, int w) {
    cout << "[2D] Usuwanie..." << endl;
    for (int i = 0; i < w; i++) {
        delete[] tab[i];
    }
    delete[] tab;
    tab = nullptr;
    cout << endl << endl;
}

// funkcja wyświetlająca zawartość tablicy jednowymiarowej tab
void wyswietl1D(int *tab, int n) {
    cout << "[1D] Wyświetlanie..." << endl;
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

// funkcja wyświetlająca zawartość tablicy dwuwymiarowej tab
void wyswietl2D(int **tab, int w, int k) {
    cout << "[2D] Wyświetlanie..." << endl;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Student {
    string imie;
    string nazwisko;
    int punkty;
} typedef student;

// Zadania
void zadanie_7_1();
void zadanie_7_2();
void zadanie_7_3();

int main() {
    unsigned short Zadanie;
    bool wyjsc = false;

    while (!wyjsc) {
        cout << "Podaj zadanie ktore chcesz zobaczyc\n"
                  << "0 - Wyjscie\n"
                  << "1 - Zadanie 7.1\n"
                  << "2 - Zadanie 7.2\n"
                  << "3 - Zadanie 7.3\n"
                  << ">>>>> ";
        cin >> Zadanie;

        switch (Zadanie) {
        case 1:
            zadanie_7_1();
            break;
        case 2:
            zadanie_7_2();
            break;
        case 3:
            zadanie_7_3();
            break;
        case 0:
            wyjsc = true;
            break;
        default:
            break;
        }
    }
    cout << endl;

    return 0;
}

// student
void wczytajStudentow(student *&tab, int *n) {
    string sciezka, linia, pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    // student* tab;
    // sciezka="studenci.csv";
    plik.open("studenci.csv");
    plik >> liczbaStudentow;
    // alokowanie pamięci w tab o dlugosci liczbaStudentow
    // elementem tablicy jest struktura student(imie, nazwisko, punkty)
    for (int i = 0; i < 2; i++)
        plik >> sredniki;

    tab = new student[liczbaStudentow];

    for (int i = 0; i < liczbaStudentow; i++) {
        plik >> linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty = atoi(pomoc.c_str());
    }
    plik.close();
    *n = liczbaStudentow;
}

void wyswietlStudentow(student *tab, int n) {
    cout << "W pliku " << n
         << " studentow" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " P: " << tab[i].punkty << "\t"
             << tab[i].imie << " "
             << tab[i].nazwisko << endl;
    }
}

// 1
void zadanie_7_1() {
    student *tab;
    int rozmiar_tablicy;
    wczytajStudentow(tab, &rozmiar_tablicy);
    wyswietlStudentow(tab, rozmiar_tablicy);
}
// 2

void wyszLiniowe(student *tab, int n, int wartosc, int *index) {
    int e = -1;
    for (int i = 0; i < n; i++) {
        if (tab[i].punkty == wartosc) {
            index[e + 1] = i;
            e++;
        }
    }
    index[n] = e;
}

void zadanie_7_2() {
    student *tab;
    int rozmiar_tablicy;
    wczytajStudentow(tab, &rozmiar_tablicy);
    wyswietlStudentow(tab, rozmiar_tablicy);
    int n, *index = new int[rozmiar_tablicy + 1];
    ;
    cout << "Podaj wartosc do wyszukiwania: ";
    cin >> n;
    wyszLiniowe(tab, rozmiar_tablicy, n, index);
    if (index[rozmiar_tablicy] != -1) {
        for (int j = 0; j <= index[rozmiar_tablicy]; j++) {
            cout << "I:" << index[j] << " "
                 << tab[index[j]].punkty << " "
                 << tab[index[j]].imie << " "
                 << tab[index[j]].nazwisko << " "
                 << endl;
        }
    } else {
        cout << "Nie ma takiej wartosci w tablice!" << endl;
    }
}
// 3

void zapisWynika(student *tab, int *index, int n) {
    ofstream zapis;
    zapis.open("wyniki.csv");
    zapis << index[n] + 1 << ";;" << endl;
    for (int i = 0; i <= index[n]; i++) {
        zapis << tab[index[i]].imie << ";" << tab[i].nazwisko << ";";
        zapis << tab[index[i]].punkty << endl;
    }

    zapis.close();
}

void sortowanieQuickSort(student *tab, int lewy, int prawy, int tryb) {
    int srodek = (lewy + prawy) / 2;

    student piwot = tab[srodek];

    tab[srodek] = tab[prawy];

    int granica = lewy;

    for (int i = lewy; i < prawy; i++) {
        if (tryb == 1) {
            if (tab[i].punkty < piwot.punkty) {
                swap(tab[granica], tab[i]);
                granica++;
            }
        } else {
            if (tab[i].punkty > piwot.punkty) {
                swap(tab[granica], tab[i]);
                granica++;
            }
        }
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;

    if (lewy < granica - 1)
        sortowanieQuickSort(tab, lewy, granica - 1, tryb);
    if (prawy > granica + 1)
        sortowanieQuickSort(tab, granica + 1, prawy, tryb);
}

void wyszBisekcujne(student *tab, int n, int wartosc, int *index) {

    int l = 0,
        p = n - 1,
        sr;
    index[n] = -1;
    while (l <= p) {
        sr = (p + l) / 2;
        if (tab[sr].punkty == wartosc) {
            int e = index[n] + 1;
            index[e] = sr;
            index[n] = e;
            p--;
        }
        if (wartosc < tab[sr].punkty)
            p = sr - 1;
        else
            l = sr + 1;
    }
}

void zadanie_7_3() {
    student *tab;
    int rozmiar_tablicy;
    wczytajStudentow(tab, &rozmiar_tablicy);
    sortowanieQuickSort(tab, 0, rozmiar_tablicy - 1, 1);
    wyswietlStudentow(tab, rozmiar_tablicy);

    int wartosc,
        *index = new int[rozmiar_tablicy + 1];

    cout << "Podaj wartosc do wyszukiwania: ";
    cin >> wartosc;

    // for (int i=0; i<rozmiar_tablicy-1; i++)
    wyszBisekcujne(tab, rozmiar_tablicy, wartosc, index);
    // for (int j=0; j<=index[rozmiar_tablicy]; j++)
    //     cout << index[j] << endl;
    if (index[rozmiar_tablicy] != -1) {
        for (int j = 0; j <= index[rozmiar_tablicy]; j++) {
            cout << "I:" << index[j] << " "
                 << tab[index[j]].punkty << " "
                 << tab[index[j]].imie << " "
                 << tab[index[j]].nazwisko << " "
                 << endl;
        }
        zapisWynika(tab, index, rozmiar_tablicy);
    } else {
        cout << "Nie ma takiej wartosci w tablice!" << endl;
    }
}

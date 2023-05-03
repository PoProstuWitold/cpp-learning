#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Student{
    string imie;
    string nazwisko;
    int punkty;
} typedef student;

struct ZA_4_3{
    int i;
    int k;
} typedef za_4_3;

//student
void wyswietlStudentow(student  *tab, int n);
void wczytajStudentow (student *&tab, int*n);
//Zadania
void zadanie_4_1();
void zadanie_4_2();
void zadanie_4_3();
//4.2
int  podziel2czesci(student *tab, int n, int granica);
void wyswietlStudentow_wer_dwa(student* tab, int n, int index);

int main() {
    unsigned short Zadanie;
    bool wyjsc = false;

    while(!wyjsc){
        cout << "Podaj zadanie ktore chcesz zobaczyc\n"
                   << "0 - Wyjscie\n"
                   << "1 - Zadanie 4.1 (Wczytanie danych)\n"
                   << "2 - Zadanie 4.2 (Podział zbioru na dwie części)\n"
                   << "3 - Zadanie 4.3 (Podział zbioru na trzy części)\n"
                   << ">>>>> ";
        cin >> Zadanie;

        switch (Zadanie){
            case 1:
                zadanie_4_1();
                break;
            case 2:
                zadanie_4_2();
                break;
            case 3:
                zadanie_4_3();
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

//student
void wczytajStudentow(student *&tab, int *n){
    string sciezka,linia,pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    //student* tab;
    //sciezka="studenci.csv";
    plik.open("studenci.csv");
    plik >> liczbaStudentow;
    //alokowanie pamięci w tab o dlugosci liczbaStudentow
    //elementem tablicy jest struktura student(imie, nazwisko, punkty)
    for(int i = 0; i < 2; i++) plik >> sredniki;

    tab = new student[liczbaStudentow];

    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
        }
    plik.close();
    *n = liczbaStudentow;
}

void wyswietlStudentow(student* tab, int n){
    cout << "W pliku " << n
         << " studentow" << endl;
    for (int i = 0; i < n; i++){
        cout << "P: " << tab[i].punkty << "\t"
             << tab[i].imie     << " "
             << tab[i].nazwisko << endl;
    }
}

///4.2
int podziel2czesci(student *tab, int n, int granica){
    int i = 0, j = n-1;
    while (i < j){
        if (tab[i].punkty <= granica && i<j) i++;
        else if (tab[j].punkty >  granica && i<j) j--;
        else if (i < j){
            swap(tab[i], tab[j]);
            i++; j--;
        }
    }
    if (tab[i].punkty <= granica) return i+1;
    else return i;
}

void wyswietlStudentow_wer_dwa(student* tab, int n, int index){
    cout << "W pliku " << n
         << " studentow\n\n";

    cout << "Studenci, ktorzy otrzymali <=" << 10
         << " punktow:\n";
    for (int i = 0; i < index; i++){
        cout << "P: " << tab[i].punkty  << " Index: " << i << "\t"
             << tab[i].imie     << " "
             << tab[i].nazwisko << endl;
    }
    cout << "Studenci, ktorzy otrzymali >" << 10
         << " punktow:\n";

    for (int i = index; i < n; i++){
        cout << "P: " << tab[i].punkty  << " Index: " << i << "\t"
             << tab[i].imie     << " "
             << tab[i].nazwisko << endl;
    }
}

//4.3
za_4_3 podziel3czesci(student *tab, int n){
    za_4_3 return_4_3;

    int i = -1, j = 0, k = n;

    while (j < k){
        if (tab[j].punkty % 3 <= 0){
            i ++;
            swap(tab[i], tab[j]);
            j ++;
        }
        else{
            if (tab[j].punkty % 3 > 1){
                k--;
                swap(tab[k], tab[j]);
            }
            else{
                j++;
            }
        }
    }
    return_4_3.i = i;
    return_4_3.k = k;
    return return_4_3;
}

void wyswietlStudentow_wer_trzy(student* tab, int n, int n1, int n2){
    cout << "W pliku " << n
         << " studentow\n\n";


    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3:\n";
    for (int i = 0; i <= n1; i++){
        cout << "P: " << tab[i].punkty  << " Index: " << i << "\t"
             << tab[i].imie     << " "
             << tab[i].nazwisko << endl;
    }
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1:\n";
    for (int i = n1+1; i < n2; i++){
         cout << "P: " << tab[i].punkty  << " Index: " << i << "\t"
              << tab[i].imie     << " "
              << tab[i].nazwisko << endl;
    }
    cout << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2:\n";
    for (int i = n2; i < n; i++){
         cout << "P: " << tab[i].punkty  << " Index: " << i << "\t"
              << tab[i].imie     << " "
              << tab[i].nazwisko << endl;
    }

}

//Zadania

void zadanie_4_1(){
    student *tab;
    int rozmiar_tablicy;
    wczytajStudentow(tab, &rozmiar_tablicy);
    wyswietlStudentow(tab, rozmiar_tablicy);
}


void zadanie_4_2(){
    student *tab;
    int rozmiar_tablicy;
    wczytajStudentow(tab, &rozmiar_tablicy);

    int granica = 10;
    int index = podziel2czesci(tab, rozmiar_tablicy, granica);
    wyswietlStudentow_wer_dwa(tab, rozmiar_tablicy, index);
}

void zadanie_4_3(){
    student *tab;
    int rozmiar_tablicy;
    wczytajStudentow(tab, &rozmiar_tablicy);

    za_4_3 n1_n2;

    n1_n2 = podziel3czesci(tab, rozmiar_tablicy);
    int n1 = n1_n2.i, n2 = n1_n2.k;
    wyswietlStudentow_wer_trzy(tab, rozmiar_tablicy, n1, n2);
}
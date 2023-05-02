#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;


struct Student{
    string imie;
    string nazwisko;
    int punkty;
} typedef student;

void sortowanieQuickSort(student* tab, int l, int p, int tryb);
void wczytajStudentow(student *&tab, int *n);
void usunTabliceStudentow(student *&tab);
void wyswietlStudentow(student* tab, int n);


int main(){
    int n, tryb;
    student *tab;


    wczytajStudentow(tab, &n);
    wyswietlStudentow(tab, n);

    cout << "tryb (rosnaco/malejaco)" << endl
    << "1: rosnaco" << endl
    << "0: malejaco"<< endl
    << ">> ";
    cin >> tryb;

    if (tryb != 1 && tryb != 0) tryb = 1;

    sortowanieQuickSort(tab, 0, n-1, tryb);
    wyswietlStudentow(tab, n);
    usunTabliceStudentow(tab);

}


void sortowanieQuickSort(student* tab, int lewy, int prawy, int tryb){
    int srodek = (lewy + prawy)/2;

    student piwot  = tab[srodek];

    tab[srodek] = tab[prawy];

    int granica = lewy;

    for (int i = lewy; i < prawy; i++){
        if (tryb == 1){
            if (tab[i].punkty < piwot.punkty){
                swap(tab[granica], tab[i]);
                granica ++ ;
            }
        }
        else{
            if (tab[i].punkty > piwot.punkty){
                swap(tab[granica], tab[i]);
                granica ++ ;
            }
        }
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;

    if (lewy  < granica-1) sortowanieQuickSort(tab, lewy, granica-1, tryb);
    if (prawy > granica+1) sortowanieQuickSort(tab, granica+1, prawy, tryb);
}

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
void usunTabliceStudentow(student *&tab){
    delete [] tab;
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

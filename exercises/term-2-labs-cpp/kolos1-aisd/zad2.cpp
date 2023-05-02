#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

// BubleSort
void sortowanieBabelkowe(int* tab, int n, int tryb);
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol);

// SelectionSort
void sortowaniePrzezWybor(int* tab, int n, int tryb);

// InsertSort
void sortowaniePrzezWstawianie(int* tab, int n, int tryb);


void przydzielPamiec1D(int *&tab, int n);
void przydzielPamiec2D(int **&tab, int w, int k);
void wypelnijTablice1D(int *tab, int n, int a, int b);
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);
void usunTablice1D(int *&tab);
void usunTablice2D(int **&tab, int w);
void wyswietl1D(int* tab, int n);
void wyswietl2D(int** tab, int w, int k);
void swap_(int *a, int *b);
int returnRand(int n);
int returnRandWP(int n, int a, int b);


void zad2_2();
void zad2_3();
void zad2_4();
void zad2_5();

int main() {
    srand(time(NULL));
    char Zadanka[15];

    while(1){
        cout << "Podaj zadanie ktore chcesz zobaczyc" << endl
             << "2.2 BubbleSort (1D)" << endl
             << "2.3 SelectionSort" << endl
             << "2.4 InsertSort" << endl
             << "2.5 BubbleSort (2D)" << endl
             << "q Wyjscie" << endl
               << endl << ">>>>> ";
        cin >> Zadanka;
        if (strcmp(Zadanka,"2.2") == 0){
            // BubleSort 1D
            zad2_2();
            cout << endl;
        }
        else if (strcmp(Zadanka,"2.3") == 0){
            // SelectionSort
            zad2_3();
            cout << endl;
        }
        else if (strcmp(Zadanka,"2.4") == 0){
            // InsertSort
            zad2_4();
            cout << endl;
        }

        else if (strcmp(Zadanka,"2.5") == 0){
            // BubleSort 2D
            zad2_5();
            cout << endl;
        }
        else if (strcmp(Zadanka,"q") == 0){
            break;
        }
    }
    cout << endl;

    return 0;
}

void sortowanieBabelkowe(int* tab, int n, int tryb) {
    int stan;
    for (int i = n-1; 0 < i ; i --){
        stan = 1;
        for (int j = 0; j < i; j ++){
            if (tryb == 1){
                if (tab[j] > tab[j+1]){
                    swap(tab[j], tab[j+1]);
                    stan = 0;
                }
            }
            else{
                if (tab[j] < tab[j+1]){
                    swap(tab[j], tab[j+1]);
                    stan = 0;
                }
            }
        }
        if (stan == 1) break;
    }
}

void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol) {
    int stan;
    for (int i =  w-1; 0<i; i--){
        stan = 1;
        for (int j = 0; j < i; j++){
            if (tryb == 1){
                if (tab[j][nrKol] > tab[j+1][nrKol]){
                    swap(tab[j], tab[j+1]);
                    stan = 0;
                }
            }
            else{
                if (tab[j][nrKol] < tab[j+1][nrKol]){
                    swap(tab[j], tab[j+1]);
                    stan = 0;
                }
            }
        }
        if (stan == 1) break;
    }
}

void sortowaniePrzezWybor(int* tab, int n, int tryb){
    int ind;
    for (int i = n-1; 0<i; i --){
        ind = 0;
        for (int j = 1; j <= i; j ++){
            if (tryb == 1){
                if (tab[j] > tab[ind]) ind = j;
            }
            else{
                if (tab[j] < tab[ind]) ind = j;
            }
        }
        swap_(&tab[i], &tab[ind]);
    }
}

void sortowaniePrzezWstawianie(int* tab, int n, int tryb){
    int temp, j;
    for (int i = n-2; 0 <= i; i--){
        j = i; temp = tab[j];
        if (tryb == 1){
            while (temp > tab[j+1] && j<n-1){
                tab[j] = tab[j+1];
                j += 1;
            }
        }
        else{
            while (temp < tab[j+1] && j<n-1){
                tab[j] = tab[j+1];
                j += 1;
            }
        }
        tab[j] = temp;
    }
}

void zad2_2(){
    int N;
    int a, b;
    int tryb;
    cout << "Podaj rozmiar tablicy: ";
    cin >> N;
    cout << "Podaj przedzial <a,b>" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "Podaj tryb (1=rosnaco, 0=malejaco): ";
    cin  >>  tryb;

    int *Tab;
    Tab = new int[N];

    wypelnijTablice1D(Tab, N, a, b);
    wyswietl1D(Tab, N);
    sortowanieBabelkowe(Tab, N, tryb);
    cout << endl;
    wyswietl1D(Tab, N);

    usunTablice1D(Tab);
}

void zad2_3(){
    int N;
    int a, b;
    int tryb;
    cout << "Podaj rozmiar tablicy: ";
    cin >> N;
    cout << "Podaj przedzial <a,b>" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "Podaj tryb (1=rosnaco, 0=malejaco): ";
    cin  >>  tryb;

    int *Tab;
    Tab = new int[N];

    wypelnijTablice1D(Tab, N, a, b);
    wyswietl1D(Tab, N);
    sortowaniePrzezWybor(Tab, N, tryb);
    cout << endl;
    wyswietl1D(Tab, N);
    usunTablice1D(Tab);
}

void zad2_4(){
    int N;
    int a, b;
    int tryb;
    cout << "Podaj rozmiar tablicy: ";
    cin >> N;
    cout << "Podaj przedzial <a,b>" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "Podaj tryb (1=rosnaco, 0=malejaco): ";
    cin  >>  tryb;

    int *Tab;
    Tab = new int[N];

    wypelnijTablice1D(Tab, N, a, b);
    wyswietl1D(Tab, N);
    sortowaniePrzezWstawianie(Tab, N, tryb);
    cout << endl;
    wyswietl1D(Tab, N);
    usunTablice1D(Tab);
}

void zad2_5(){
    int w, k;
    cout << "Podaj rozmiar: ";
    cin >> w;
    cout << "Podaj ile kolumn: ";
    cin >> k;
    int a,b;
    int tryb, nrKol;
    cout << "Podaj przedzial <a,b>" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "Podaj tryb (1=rosnaco, 0=malejaco): ";
    cin  >>  tryb;

    int **Tab=new int*[w];
    for(int i=0;i<w;i++){
        Tab[i]=new int[k];
    }
    wypelnijTablice2D(Tab, w, k, a, b);
    cout << "Do sortowania" << endl;
    wyswietl2D(Tab, w, k);

    cout << endl << "Podaj numer kolumny: ";
    cin  >>  nrKol;

    if (nrKol > k-1){
        nrKol = k-1;
    }


    sortowanieBabelkowe2D(Tab, w, k, tryb, nrKol);
    cout << endl;
    cout << "Po sortowaniu" << endl;
    wyswietl2D(Tab, w, k);
    usunTablice2D(Tab, w);
}

int  returnRand(int n){
    return rand()%n;
}

int  returnRandWP(int a, int b){
    return rand()%(b-a+1)+a;
}

void przydzielPamiec1D(int *&tab, int n){
    for (int i = 0; i<n; i++){
        tab[i] = returnRand(n);
    }
}

void przydzielPamiec2D(int **&tab, int w, int k){
    for (int i = 0; i<w; i++){
        for (int j = 0; j < k; j ++){
            tab[i][j] = returnRand(w*k);
        }
    }
}

void wypelnijTablice1D(int *tab, int n, int a, int b){
    for (int i = 0; i<n; i++){
        tab[i] = returnRandWP(a, b);
    }
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    for (int i = 0; i<w; i++){
        for (int j = 0; j < k; j ++){
            tab[i][j] = returnRandWP(a, b);
        }
    }
}

void usunTablice1D(int *&tab){
    delete [] tab;
}

void usunTablice2D(int **&tab, int w){
    for (int i = 0; i<w; i++){
        delete [] tab[i];
    }
    delete [] tab;
}

void wyswietl1D(int* tab, int n){
    cout << "Tab: ";
    for (int i = 0; i<n; i++){
        cout << tab[i];
        if (i+1 < n){
            cout <<", ";
        }
    }
}

void wyswietl2D(int** tab, int w, int k){
    //cout << "Tab: ";
    for (int i = 0; i < w; i++){
        cout << "[";
        for (int j = 0; j < k; j++){
            cout << tab[i][j];
            if (j+1 < k){
                cout <<", ";
            }
        }
        cout << "]";
        if (i+1 < w){
            cout <<endl;
        }
    }
}


void swap_(int *a, int *b){
    int  c = *a;
    *a = *b;
    *b = c;
}
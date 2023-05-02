#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

void przydzielPamiec1D(int *&tab, int n);
void przydzielPamiec2D(int **&tab, int w, int k);
void wypelnijTablice1D(int *tab, int n, int a, int b);
void wypelnijTablice2D(int **tab, int w, int k, int a, int b);
void usunTablice1D(int *&tab);
void usunTablice2D(int **&tab, int w);
void wyswietl1D(int* tab, int n);
void wyswietl2D(int** tab, int w, int k);

int returnRand(int n);
int returnRandWP(int n, int a, int b);
//1.2
int Min(int *&tab, int N);
bool pierwsza(int a);
//1.4
int Max(int **&tab, int w, int k);
int Sum(int **&tab, int w, int k);

void zad1_2();
void zad1_3();
void zad1_4();
void zad1_5();

int main() {
    srand(time(NULL));
    char Zadanka[15];
   
    while(1){
        cout << "Podaj zadanie ktore chcesz zobaczyc(1.2,1.3...), lub q dla wyjscia"
               << endl << ">>>>> ";
        cin >> Zadanka;
        if (strcmp(Zadanka,"1.2") == 0){
            zad1_2();
            break;
        }
        else if (strcmp(Zadanka,"1.3") == 0){
            zad1_3();
            break;
        }

        else if (strcmp(Zadanka,"1.4") == 0){
            zad1_4();
            break;
        }
        /*
        else if (strcmp(Zadanka,"1.5") == 0){
            zad1_5();
            break;
        }
        */
        else if (strcmp(Zadanka,"q") == 0){
            break;
        }
    }
    cout << endl;
    return 1;

    return 0;
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
        tab[i] = returnRandWP(n, a, b);
    }
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    for (int i = 0; i<w; i++){
        for (int j = 0; j < k; j ++){
            tab[i][j] = returnRandWP(w*k, a, b);
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
        std:: cout << tab[i];
        if (i+1 < n){
            std:: cout <<", ";
        }
    }
}

void wyswietl2D(int** tab, int w, int k){
    cout << "Tab: ";
    for (int i = 0; i < w; i++){
        std:: cout << "[";
        for (int j = 0; j < k; j++){
            std:: cout << tab[i][j];
            if (j+1 < k){
                std:: cout <<", ";
            }
        }
        std:: cout << "]";
        if (i+1 < w){
            std:: cout <<", ";
        }
    }
}

int  returnRand(int n){
    return rand()%n;
}

int  returnRandWP(int n, int a, int b){
    return rand()%(b-a+1)+a;
}
//1.2
int Min(int *&tab, int N){
    int M = tab[0];

    for (int i = 0; i < N; i++){
        if (M > tab[i]){
            M = tab[i];
        }
    }
    return M;
}
bool pierwsza(int a){
    if (a<2) return false;
    for (int i = 2; i*i <= a; i ++){
        if (a%i == 0){
            return false;
        }
    }
    return true;
}
//1.4
int Max(int **&tab, int w, int k){
    int M = tab[0][0];

    for (int i = 0; i < w; i++){
        for (int j = 0; j < k; j ++){
            if (tab[i][j] > M){
                M = tab[i][j];
            }
        }
    }
    return M;
}

int Sum(int **&tab, int w, int k){
    int Suma = 0;

    for (int i = 0; i < w; i++){
        for (int j = 0; j < k; j ++){
            Suma += tab[i][j];
        }
    }
    return Suma;
}

void zad1_2(){
    int N;
    int a, b;
    std:: cout << "Podaj rozmiar tablicy: ";
    std:: cin >> N;
    std:: cout << "Podaj przedzial <a,b>" << endl;
    std:: cout << "a: "; std:: cin >> a;
    std:: cout << "b: "; std:: cin >> b;
    int *Tab, Minimalny;
    Tab = new int[N];
    wypelnijTablice1D(Tab, N, a, b);
    Minimalny = Min(Tab, N);
    wyswietl1D(Tab, N);
    std:: cout << endl << "Minimalny element jest " << Minimalny;
    if (pierwsza(Minimalny)){
        std:: cout << " i to jest liczba piersza";
    }
    else{
        std:: cout << " i to nie jest liczba piersza";
    }
    usunTablice1D(Tab);
}

void zad1_3(){
    int N;
    int a = 0, b = 9;

    std:: cout << "Podaj rozmiar tablicy: ";
    std:: cin >> N;

    int *Tab=new int[N];
    int CP = returnRandWP(N, a, b), lenCP = 0;
    wypelnijTablice1D(Tab, N, a, b);
    for (int i = 0; i<N; i++){
        if (CP == Tab[i]){
            lenCP ++;
        }
    }
    wyswietl1D(Tab, N);

    cout << endl << "Element " << CP << " wystepuje w tablice "
         << lenCP << endl;
    usunTablice1D(Tab);
}

void zad1_4(){
    int w, k;
    cout << "Podaj rozmiar: ";
    cin >> w;
    cout << "Podaj ile kolumn: ";
    cin >> k;
    int a,b;
    cout << "Podaj przedzial <a,b>" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;

    int **Tab=new int*[w];
    for(int i=0;i<w;i++){
       Tab[i]=new int[k];
    }
    wypelnijTablice2D(Tab, w, k, a, b);

    int Maksymalny, Suma;
    Maksymalny = Max(Tab, w, k);
    Suma = Sum(Tab, w, k);

    wyswietl2D(Tab, w, k);

    cout << endl << "Maksymalny element jest " << Maksymalny
        << endl << "Suma tablicy jest " << Suma;

    usunTablice2D(Tab, w);
}

void zad1_5(){
    int w;
    cout << "Podaj rozmiar kwadratowy: ";
    cin >> w;

    if (w % 2 != 0){
        w += 1;
    }

    int a = 7, b = 122;


    int **Tab=new int*[w];
    for(int i=0;i<w;i++){
       Tab[i]=new int[w];
    }
    wypelnijTablice2D(Tab, w, w, a, b);

    int Maksymalny, Suma;
    Maksymalny = Max(Tab, w, w);
    Suma = Sum(Tab, w, w);

    wyswietl2D(Tab, w, w);

    cout << endl << "Maksymalny element jest " << Maksymalny
        << endl << "Suma tablicy jest " << Suma;

    usunTablice2D(Tab, w);
}

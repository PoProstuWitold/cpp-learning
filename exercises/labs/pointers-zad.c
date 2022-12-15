// Proszę napisać programy zawierające następujące funkcje:
// 1. Dane: N, tablica {xi} i=0,...N-1. Funkcja F oblicza i zwraca:
//      a. poprzez return sumę liczb dodatnich z tablicy x,
//      b. poprzez parametr wskaźnikowy iloczyn wszystkich liczb.
// 2. Dane: N, tablica {xi} i=0,...N-1. Funkcja F oblicza i zwraca:
//      a. poprzez return średnią arytm. wszystkich liczb w tablicy, 
//      b. poprzez parametr wskaźnikowy informację, ile liczb w tablicy jest 
//      większych od średniej.
// 3. Dane: N, tablica {xi} i=0,...N-1. Funkcja F zwraca: 
//      a. danę tablicę x, w której elementy ujemne zastąpione są 0 czyli 
//      modyfikuje tablicę x,
//      b. poprzez parametr wskaźnikowy informację ile było zastąpień.. 

// UWAGA: Wprowadzenie danych, wywołanie funkcji, wyświetlenie wyników w 
// main()

// 1.
// return suma x>0
// pointer iloczyn T[N]
int F1(int k, float T[], float *iloczyn);

// 2.
// return srednia
// pointer ile liczb wiekszych od sredniej
float F2(int k, float T[], int *ile_wiekszych);

// 3.
// return tablica, ale ujemne zamienione na 0
// pointer informacja ile razy takie cos
float* F3(int k, float T[], int *ile_zastapien);

int main() {
    int N, i = 0;
    float iloczyn = 1;
    int ile_wiekszych = 0;
    int ile_zastapien = 0;

    float wynik1, wynik2, *wynik3;

    printf("Ile liczb: ");
    scanf("%d", &N);

    float T[N];

    for (i=0; i<N; i++) { 
        printf("podaj liczbe %d liczbe T[%d]: ", i+1, N);
        scanf("%f", &T[i]);
    }

    printf("\nTablica T[%d]\n", N);    //dlatego jako parametry aktualne używamy adresów tych zmiennych

    for (i=0; i<N; i++)
        printf("%.2f ", T[i]);

    // 1.
    wynik1 = F1(N, T, &iloczyn);

    printf("\n\nzad 1. \n");
    if (wynik1)
        printf("[return] suma dodatnich = %f\n", wynik1);
    else
        printf("[return] brak liczb dodatnik\n");
    
    if(iloczyn)
        printf("[pointer] iloczyn = %f \n\n", iloczyn);

    // 2.
    wynik2 = F2(N, T, &ile_wiekszych);

    printf("zad 2. \n");
    if (wynik2)
        printf("[return] srednia = %f\n", wynik2);
    else
        printf("[return] brak sredniej\n");
    
    if(ile_wiekszych)
        printf("[pointer] ile_wiekszych = %d \n\n", ile_wiekszych);

    // 3.
    wynik3 = F3(N, T, &ile_zastapien);

    printf("zad 3. \n");
    if (wynik3)
        printf("[return] tablica, ale ujemne zamienione na 0 = ");
        for (i=0; i<N; i++)
            printf("%.2f \t", wynik3[i]);
    
    if(ile_zastapien)
        printf("\n[pointer] ile_zastapien = %d \n\n", ile_zastapien);


    return 0;
}

int F1(int k, float T[], float *iloczyn) {
    int i, licz=0;

    float suma=0;
    float _iloczyn = 1;

    for (i=0; i<k; i++) { 
        if (T[i]> 0) { 
            licz++; 
            suma+=T[i];
        }
        _iloczyn *= T[i];
    }

    *iloczyn=_iloczyn;

    if (licz != 0) {    //podstawienie sredniej pod adres
        return suma;   //przekazanie z funkcji inf. ,że srednia obliczona
    }

    return 0; 
}

float F2(int k, float T[], int *ile_wiekszych) {
    int i = 0;
    int _ile_wiekszych = 0;
    int ilosc = 0;
    
    float suma = 0.0;
    float srednia = 0.0;
    
    for (i=0; i<k; i++) { 
        suma += T[i];
        ilosc++;
    }

    srednia = suma/ilosc;

    for (i=0; i<k; i++) { 
        if(T[i] > srednia) {
            _ile_wiekszych++;
        }
    }

    *ile_wiekszych=_ile_wiekszych;

    return srednia;
}

float* F3(int k, float T[], int *ile_zastapien) {
    int i = 0;
    int _ile_zastapien = 0;

    float* tab2 = malloc(sizeof(float) * k);

    for (i=0; i<k; i++) { 
        tab2[i] = T[i];
        if(T[i] < 0) {
            tab2[i] = 0;
            _ile_zastapien++;
        }
    }

    *ile_zastapien = _ile_zastapien;

    return tab2;
}
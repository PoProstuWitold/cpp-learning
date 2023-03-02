//Funkcja oblicza i zwraca: średnią liczb ujemnych (jeśli takie są) oraz inf.
// czy została obliczona. Średnia jest zwracana poprzez parametr wskaźnikowy
// inf. o jej obliczeniu poprzez return.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// SREDNIA LICZB UJEMNYCH
int F1(int k, float T[], float *sr) { 
    int i, licz=0;
    float s=0;
    for (i=0; i<k; i++) { 
        if (T[i]< 0) { 
            licz++; 
            s+=T[i];
        }
    }

    if (licz != 0) { 
        s=s/licz;
        *sr=s;      //podstawienie sredniej pod adres
        return 1;   //przekazanie z funkcji inf. ,że srednia obliczona
    }

    *sr=0;          //podst."dowolnej" wartości pod adres-i tak nie będzie wykorzystana
    return 0;       //przekazanie z funkcji inf. ,że sredniej nie ma
}

int main(int argc, char *argv[]) {
    int i, n, w;
    printf("ile liczb?");
    scanf("%d", &n);

    float A[n], sred;

    for (i=0; i<n; i++) { 
        printf("podaj liczbe ");
        scanf("%f", &A[i]);
    }

    w = F1(n, A, &sred); //uwaga: sred nie jest wskaźnikiem, 
    // dlatego w wywołaniu funkcji poprzedzamy zmienną symbolem jej adresu &
    
    if (w ==1)
        printf("srednia liczb ujemnych=%f\n", sred);
    else
        printf("brak liczb ujemnych \n");

    return 0;
}


//Funkcja oblicza i zwraca: max z tablicy T i max z tablicy V.
// oba wyniki zwracane poprzez parametry wskaźnikowe
// void MM(int k, float T[], float *mT, float V[], float *mV) { 
//     int i;
//     float s=0, maxT=T[0], maxV= V[0];
//     for (i=0; i<k; i++) { 
//         if (T[i]> maxT) 
//             maxT=T[i];
//         if (V[i]> maxV)
//             maxV=V[i];
//     }

//     *mT=maxT; //podst. obliczeń pod adresy, które są parametrami
//     *mV=maxV;
// }


// int main(int argc, char *argv[]) {
//     int i, n;
//     printf("ile liczb?");
//     scanf("%d", &n);

//     float A[n], B[n], mA, mB;

//     for (i=0; i<n; i++) { 
//         printf("podaj liczbe A ");
//         scanf("%f", &A[i]);
//         printf("podaj liczbe B ");
//         scanf("%f", &B[i]);
//     }

//     MM(n, A, &mA, B, &mB);      //zmienne mA, mB NIE są zmiennymi wskaźnikowymi
//     printf("\nTablica A\n");    //dlatego jako parametry aktualne używamy adresów tych zmiennych

//     for (i=0; i<n; i++)
//         printf("%.2f ", A[i]);
//         printf("\nmax=%.2f\n ", mA);;
//         printf("\nTablica B\n");
//     for (i=0; i<n; i++)
//         printf("%.2f ", B[i]);
//         printf("\nmax=%.2f\n ", mB); 
    
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

// program wyświetla max z wartosci wybranej funkcji
// w 10 punktach podanego przedziału
// wyznaczenie max za pomocą funkcji wywołujacej wybraną funkcję

float kwadrat (float x, float a, float b, float c) {
    return a*x*x+b*x+c;
}

float szescian (float x, float a, float b, float c) {
    return a*x*x*x+b*x+c;
}

float liniowa (float x, float a, float b, float c) {    
    //parametr c dla zgodnoœci z parametrem funkcyjnym
    return a*x+b;
}

float trygonometryczna (float x,float a, float b, float c) {
    return a*sin(x)+b*cos(x)+c;
}


float wartosci (float a, float b, float c, float p, float kon, float FF(float x,float a, float b, float c)) {   
    int i;
    float k, T[10], max;
    
    k=(kon-p)/10;

    for(i=0; i<10; i++) {
        T[i]=FF(p+i*k, a, b,c);
        printf("dla %.3f\twynik=%.4f\n", p+i*k, T[i]);
    }

    max=T[0];

    for(i=0; i<10; i++) {
        if (T[i]>max)
            max=T[i];
    }

    return max;
}


int main() {
    float pocz_przedzial, kon_przedz, w_a, w_b, w_c;
    float  M;
    int i;

    printf(" przedzial od - do");
    scanf("%f%f", &pocz_przedzial, &kon_przedz);

    printf(" parametry funkcji obliczanej a, b, c");
    scanf("%f%f%f", &w_a, &w_b, &w_c);

    M=wartosci( w_a, w_b, w_c, pocz_przedzial,kon_przedz, trygonometryczna );
    printf("\nmax=%f\n", M);

    return 0;
}

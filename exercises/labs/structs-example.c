#include <stdio.h>
#include <stdlib.h>

struct samochod {
    char marka[10];
    float l_km;
};

void flushBuffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main() {
    struct samochod S1, S2; // S1, S2 zmienne strukturalne
    float D, Z1, Z2;

    printf(" wpisz dane pierwszego samochodu\n" );
    printf(" marka: ");
    fgets(S1.marka, sizeof(S1.marka), stdin); //do elementu zmiennej strukturalnej
    
    //odwolujemy się poprzez tą zmienna-marka jest częścia S1
    printf("zuzycie paliwa na 100 km: ");
    scanf("%f", &S1.l_km);

    printf(" wpisz dane drugiego samochodu\n" );
    printf(" marka: ");

    fflush(stdin); // ZALEZY OD KOMPILATORA, ZŁA PRAKTYKA
    flushBuffer(); // WSZEDZIE
    
    fgets(S2.marka, sizeof(S2.marka), stdin);
    printf("zuzycie paliwa na 100 km: ");
    scanf("%f", &S2.l_km);
    printf("dlugosc trasy: ");
    scanf("%f", &D);

    Z1=S1.l_km*D/100;
    Z2=S2.l_km*D/100;
    
    printf("\nsamochod pierwszy:\n %s zuzyje %.2f l. paliwa\n", S1.marka, Z1);
    printf("samochod drugi:\n %s zuzyje %.2f l. paliwa\n", S2.marka, Z2);
    
    return 0;
}
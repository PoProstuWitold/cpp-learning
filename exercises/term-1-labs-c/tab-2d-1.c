#include <stdio.h>
#include <math.h>

int main() { 
    int i, j, w, k, kolumna;

    printf("ile wierszy? ");
    scanf("%d",&w);

    printf("ile kolumn? ");
    scanf("%d",&k);

    int rozmiar = 0;
    float T[w][k], srednia = 0, r;

    printf("\nwymiary tablicy: [wiersze][kolumny] [%d][%d] \n", w, k);

    for(i=0; i<w; i++)
        for (j=0; j<k; j++) { 
            printf("podaj element [%d][%d] tablicy: ", i, j);
            scanf("%f",&T[i][j]);
        } 

    printf("\ntablica\n"); 
    for(i=0; i<w; i++) {
        for (j=0; j<k; j++)
            printf("%.2f\t",T[i][j]);
            printf("\n"); 
    } 



    // Obliczyć średnią arytm. liczb w kolumnie wskazanej przez użytkownika. 
    // Uwaga: trzeba sprawdzić czy kolumna o tym numerze istnieje!
    printf("\npodaj kolumne: ");
    scanf("%d", &kolumna);

    while(kolumna > k || kolumna == 0) {
        printf("podana kolumna nie istnieje \n");
        printf("podaj kolumne: ");
        scanf("%d", &kolumna);
    }

    for (j=0; j<k; j++) {
        srednia += T[j][kolumna-1];
        printf("%f\t",srednia);
        rozmiar++;
        printf("rozmiar %d\t",rozmiar);
    } 

    printf("\nSrednia w kolumnie [wiersze][kolumny] [x][%d] wynosi: %f \n", kolumna-1, srednia/rozmiar);




    //zamiana elementów brzegowych wierszy
    for(i=0; i<k; i++) {
        r=T[0][i];
        T[0][i]=T[w-1][i];
        T[w-1][i]=r;
    } 

    printf("\ntablica po zamianie brzegowych wierszy\n");

    for(i=0; i<w; i++) {
        for (j=0; j<k; j++)
        printf("%.2f\t",T[i][j]);
        printf("\n"); 
    } 
    


    // Sprawdzić, czy w tablicy jest liczba 0.
    for(i=0; i<w; i++) {
        for (j=0; j<k; j++)
            if(T[i][j] == 0) {
                printf("\nW tablicy znajduje sie zero \n");
                break;
            } 
    } 


    // Sprawdzić, czy tablica jest symetryczna względem środkowej kolumny
    printf("\nsymetryczna wzgledem srodkowej kolumny: "); 
    for(i=0; i<w; i++) {
        for (j=0; j<k; j++)
            if(k % 2 != 0) {
                while(j != k) {
                    if(T[i][j] != T[i][k-j-1]) {
                        printf("nie \n");
                    } else {
                        printf("tak \n");
                    }
                    break;
                } 
                break;
            }
            break;
    } 



    return 0;
}

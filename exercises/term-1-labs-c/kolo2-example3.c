#include <stdio.h>
#include <stdlib.h>
// float *sum_avg(int n, float array[n][n], float *average) {
float *sum_avg(int n, float **array, float *average) {
    float *new_array = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < n; j++) {
            // array[wiersze][kolumny]
            sum += array[j][i];
        }
        new_array[i] = sum;
    }
    float sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += new_array[i];
    }
    *average = (float)sum2 / n;
    return new_array;
}
int main() {
    int n;
    printf("Podaj ilosc wierszy i kolumn: ");
    scanf("%d", &n);
    // float array[n][n];
    float **array = (float**)malloc(n * sizeof(float));
    for (int w=0; w<n ; w++)
        array[w]=(float*) malloc(n * sizeof (float) );
    float average;
    printf("Podaj elementy tablicy: \n");
    printf("[wiersze][kolumny]\n");
    // wiersze
    for (int i = 0; i < n; i++) {
        // kolumny
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]", i, j);
            scanf("%f", &array[i][j]);
        }
    }
    float *new_array = sum_avg(n, array, &average);
    printf("Nowa tablica: ");
    for (int i = 0; i < n; i++) {
        printf("%f, ", new_array[i]);
    }
    printf("\nSrednia nowej tablicy: %f", average);
    return 0;
}
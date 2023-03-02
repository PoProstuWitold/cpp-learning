#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S1 {
    char miasto[20];
    int ludnosc;
    float powierzchnia;
} s1;

typedef struct S2 {
    char miasto[20];
    float gestosc;
} s2;

s2 *funkcja(s1* miasta_s1, int n, s2* miasto_min);

int main() {
    int n;
    // s2 *miasto_min;
    s2 *miasto_min = (s2*)malloc(sizeof(s2));
    printf("Podaj n: ");
    scanf("%d", &n);
    
    s1 *miasta_s1 = (s1*)malloc(n * sizeof(s1));
    
    for(int i = 0; i < n; i++) {
        printf("podaj miasto: ");
        scanf(" %19[^\n]s", miasta_s1[i].miasto);
        printf("podaj ludnosc: ");
        scanf("%d", &miasta_s1[i].ludnosc);
        printf("podaj powierzchnie: ");
        scanf("%f", &miasta_s1[i].powierzchnia);
    }
    
    // s2 *miasta_s2 = funkcja(miasta_s1, n, &miasto_min);
    s2 *miasta_s2 = funkcja(miasta_s1, n, miasto_min);
    
    printf("MIASTA S2\n");
    for(int j = 0; j < n; j++) {
        printf("miasto: %s\n", miasta_s2[j].miasto);
        printf("gestosc: %f\n\n", miasta_s2[j].gestosc);
    }
    
    printf("MIASTO MIN\n");
    printf("miasto: %s\n\n", miasto_min->miasto);
    printf("gestosc: %f\n\n", miasto_min->gestosc);
    // printf("miasto: %s\n\n", (*miasto_min).miasto);
    // printf("gestosc: %f\n\n", (*miasto_min).gestosc);
    
    return 0;
}

s2 *funkcja(s1* miasta_s1, int n, s2 *miasto_min) {
    s2 *miasta_s2 = (s2*)malloc(n * sizeof(s2));
    int index = 0;
    float gestosc = 0.0;
    
    for(int i = 0; i < n; i++) {
        // miasta_s2[i].miasto = miasta_s1[i].miasto;
        strcpy(miasta_s2[i].miasto, miasta_s1[i].miasto);
        miasta_s2[i].gestosc = (miasta_s1[i].ludnosc/miasta_s1[i].powierzchnia);

    }
    
   for(int j = 0; j < n; j++) {
        if(miasta_s2[j].gestosc > gestosc) {
            //                  >
            miasta_s2[j].gestosc = gestosc;
            // gestosc = miasta_s2[j].gestosc;
            index = j;
        }
    }
    
    *miasto_min = miasta_s2[index];
    return miasta_s2;
    
}
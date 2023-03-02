#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "if for zadania"

// 1. Dane: przedział [A,B], krok K. Wyświetlić wartości wyrażenia x2+x+1 dla 
// x nalezy do [A,B] czyli x=A, x=A+K, x=A+2K,...

void print_author_info(void);

int main() { 
    float a, b, w, y; 
    print_author_info();
    
    printf("Podaj a "); 
    scanf("%f", &a); 

    printf("Podaj b "); 
    scanf("%f", &b); 

    printf("Podaj krok "); 
    scanf("%f", &w); 

    if (a<=b && w>0) {
        while (a<=b) { 
            y=pow(a, 2) + a + 1;
            printf("x=%.2f\tf(x)=%f\n",a,y);
            a+=w; 
        } 
    } else printf("blad danych"); 

    return 0;

}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
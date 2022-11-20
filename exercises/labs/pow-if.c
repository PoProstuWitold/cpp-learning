#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "powtórzenie if"

// Proszę wczytać 3 liczby i wyświetlić największą. 
// Należy przeanalizować iuwzględnić w komunikatach wyjściowych następujące przypadki:
// • są to trzyróżneliczby,
// • dwie liczby mają największą(tę samą) wartość,
// • wszystkie liczby są równe.

void print_author_info(void);

int main() { 
    print_author_info();
    
    int a, b, c;

    printf("Podaj 3 numery całkowite: \n");

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    printf("c: ");
    scanf("%d", &c);

    if (a > b && a > c)
        printf("Największy numer to 'a': %d", a);
    if (b > a && b > c)
        printf("Największy numer to 'b': %d", b);
    if (c > a && c > b)
        printf("Największy numer to 'c': %d", c);

    if(a == b && a > c)
        printf("Numery 'a' i 'b' mają taką samą wartość i wynosi ona: %d", a); 
    if(a == c && a > b)
        printf("Numery 'a' i 'c' mają taką samą wartość i wynosi ona: %d", a);  
    if(b == c && b > a)
        printf("Numery 'b' i 'c' mają taką samą wartość i wynosi ona: %d", b);  

    if (a == b && b == c)
        printf("Wszystkie numery mają taką samą wartość i wynosi ona: %d", a);

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
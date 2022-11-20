#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "powtorzenie for 2 (bez tablic)"

// 2. Proszę wczytać Nocen, obliczyć i wyświetlić następujące wyniki:
// średnią arytmetyczną ocen>=3.0,
// liczbę ocen=2.0,
// liczbę ocen>4.0.
// Uwaga: Komunikaty wyjściowe powinny zawierać opisany wynik liczbowy 
// lub informację o braku poszukiwanych danych np.: brak ocen niedostatecznych.

void print_author_info(void);

struct size_sum {
    int size;
    float sum;
};

int main() { 
    print_author_info();

    // srednia - srednia arytmetyczną ocen >= 3.0
    // x - liczba ocen = 2.0
    // y - liczba ocen > 4.0

    struct size_sum srednia = { 0, 0.0 };
    int n, i = 0, x = 0, y = 0;
    float num;

    printf("Wprowadz n liczb: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Wprowadz %d. ocene: ", i + 1);
        scanf("%f", &num);

        while(!(num >= 2.0 && num <= 5.0)) {
            printf("Wprowadz %d. ocene z przedzialu [2.0; 5.0]: ", i + 1);
            scanf("%f", &num);
        }

        if(num >= 3.0) {
            srednia.size++;
            srednia.sum += num;
        }

        if(num == 2.0) {
            x++;
        }

        if(num > 4.0) {
            y++;
        }
    }

    if(srednia.size)
        printf("Srednia ocen >= 3.0: %f \n", srednia.sum/srednia.size);
    else 
        printf("Srednia ocen >= 3.0: brak ocen >= 3 \n");

    if(x)
        printf("Liczba ocen = 2.0: %d \n", x);
    else 
        printf("Liczba ocen = 2.0: brak ocen niedostatecznych \n");

    if(y)
        printf("Liczba ocen > 4.0: %d \n", y);
    else 
        printf("Liczba ocen > 4.0: brak ocen > 4 \n");
        

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
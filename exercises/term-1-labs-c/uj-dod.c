#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "dodawanie liczb ujemnych i dodatnich"

// 3. Użytkownik podaje liczby całkowite ( nieokreślona liczba podawanych liczb). 
// Wczytywać te liczby i sumować oddzielnie dodatnie i ujemne, aż ilość wczytanych 
// dodatnich będzie równa ilości ujemnych. Wyniki: suma dodatnich, suma ujemnych.

void print_author_info(void);

struct size_sum {
    int size;
    double sum;
};


int main() { 
    struct size_sum basic = { 0, 0.0 };
    struct size_sum dodatnie = { 0, 0.0 };
    struct size_sum ujemne = { 0, 0.0 };

    int num;

    print_author_info();
    printf("-----------------------------\n");
    printf("Podaj ile liczb: "); 
    scanf("%d", &basic.size); 
    printf("Podaj %d liczb: \n", basic.size);

    for(int i=0; i<basic.size; i++) {
        printf("Podaj %d liczbę: ", i+1); 
        scanf("%d", &num); 

        if(num < 0) {
            ujemne.size++;
            ujemne.sum = ujemne.sum + num;
        } else if(num > 0) {
            dodatnie.size++;
            dodatnie.sum = dodatnie.sum + num;
        } else {
            // nothing
        }

        if((dodatnie.size != 0) && (ujemne.size == dodatnie.size)) {
            break;
        }
    }

    if(ujemne.size == dodatnie.size) { 
        printf("Liczba dodatnich = liczba ujemnych\n");
    } else {
        printf("Maksymalna iteracja osiągnięta\n");
    }
    printf("Dodatnie: suma=%lf, ilość=%d\n", dodatnie.sum, dodatnie.size);
    printf("Ujemne: suma=%lf, ilość=%d\n", ujemne.sum, ujemne.size);

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
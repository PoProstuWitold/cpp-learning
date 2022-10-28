#include <stdio.h>
#include <math.h>
#include <ctype.h>

using namespace std;

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "Delta kalkulator"

int insert_number(char const name[]);
void empty_stdin(void);
void print_author_info(void);

int main() {
    float a, b, c, delta, x0, x1, x2;

    do {
        a = insert_number("a");
        b = insert_number("b");
        c = insert_number("c");
        delta = pow(b, 2) - (4 * a * c);

        if(delta == 0) {
            //x0=
            x0=(-b*1.0)/(2.0*a);
            printf("f(x)=%0.3fx^2 + %0.3fx + %0.3f \n", a, b, c);
            printf("Delta równa 0. Rozwiązanie x0=%0.3f \n", x0);
        }

        if(delta > 0) {
            //x1=
            x1=(-b*1.0-sqrt(delta))/(2.0*a);
            //x2=
            x2=(-b*1.0+sqrt(delta))/(2.0*a);
            printf("f(x)=%0.3fx^2 + %0.3fx + %0.3f \n", a, b, c);
            printf("Delta większa od 0. Rozwiązania x1=%0.3f, x2=%0.3f \n", x1, x2);
        }

        if(delta < 0) {
            printf("f(x)=%0.3fx^2 + %0.3fx + %0.3f \n", a, b, c);
            printf("Delta mniejsza niż 0. Brak rozwiązań");
        }

    } while (isdigit(a) && isdigit(b) && isdigit(c));
    

    return 0;
}

int insert_number(char const name[]) {
    float number;
        for (;;) {  
            int rtn = 0;
            printf("\nPodaj liczbe %s:", name);
            rtn = scanf ("%f", &number);

            if (rtn == EOF) {
                return 1;
            }
            else if (rtn == 0) {
                printf(" Błąd: Liczba %s nie jest numerem rzeczywistym.\n", name);
                empty_stdin();
            }
            else {
                empty_stdin();
                break;
            }
        }

        return number;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}

void empty_stdin (void) { 
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}
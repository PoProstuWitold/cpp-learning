#include <stdio.h>
#include <math.h>
#include <algorithm>
// command to include math.h lib needs to have flag -lm: gcc -o lab lab-10-13.cpp -lm
using namespace std;

// empty stdin helper
void empty_stdin (void) { 
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

//search for int in array
int search_for_number(int *a, int search) {

    for(int i = 0; i < 100; i++) {
        if(a[i] == search) {      // or if(*(a + i) == search)
            return 1;
        }
    }

    return 0;
}

char get_formula() {
    int formulaArray[] = { 1,2,3,41,42,43,44,45,46,47,48 };
    int userChoice, rtn = 0;

    for (;;) {  /* loop continually until valid input or EOF */
        
        printf("\nPodaj wzór:");
        rtn = scanf ("%d", &userChoice);    /* save return */

        if (rtn == EOF) {   /* user generates manual EOF */
            return 1;
        }
        else if (rtn == 0) {    /* matching failure */
            printf(" Błąd: Wartość nie jest numerem całkowitym.\n");
            empty_stdin();
        }
        else if (!(search_for_number(formulaArray, userChoice))) {  /* validate range */
            printf(" Błąd: Wartość nie odpowiada żadnemu numerowi wzoru.\n");
            empty_stdin();
        }
        else if (search_for_number(formulaArray, userChoice)) {  /* validate range */
            empty_stdin();
            break;
        }
        else {  /* good input */
            empty_stdin();
            break;
        }
    }

    return userChoice;
}

int insert_number(float number, char const name[]) {
        for (;;) {  /* loop continually until valid input or EOF */
            int rtn = 0;
            printf("\nPodaj liczbe %s:", name);
            rtn = scanf ("%f", &number);    /* save return */

            if (rtn == EOF) {   /* user generates manual EOF */
                return 1;
            }
            else if (rtn == 0) {    /* matching failure */
                printf(" Błąd: Liczba %s nie jest numerem rzeczywistym.\n", name);
                empty_stdin();
            }
            else {  /* good input */
                empty_stdin();
                break;
            }
        }

        return number;
}

int main() {
    int formula, formulaArray[] = { 1,2,3,41,42,43,44,45,46,47,48 };
    float a, b, x, y;

    // has to be this way to silent gcc compiler warnings
    char const *a_name = "a", *b_name = "b";

    printf( "autor: Witold Zawada\n"
            "kierunek/semestr: informatyka I stopnia (stacjonarne)/semestr 1\n"
            "grupa: I1S 1.10/20\n"
            "program: Kalkulator z wyborami\n"
            "-------------WZORY--------------\n"
            "(1) Pole: x=a*b\n"
            "    Obwód: y=(2*a)+(2*b)\n"
            "(2) Pole: x=PI*a^2\n"
            "    Obwód: y=2*PI*a\n"
            "(3) x=(a+b)/2\n"
            "(41) x=sqrt(2*a^2 + b^2)\n"
            "(42) x=(a*sin(b))/cbrt(27)\n"
            "(43) x=sqrt(|a-b|)+a^3\n"
            "(44) x=cos(2*b)-sqrt(a^2)+1\n"
            "(45) x=(a+sin(b))/|a^3|+1\n"
            "(46) x=cbrt(a-b*cos(a))\n"
            "(47) x=a+sqrt(a^2+((a^2+a)/3)^2)\n"
            "(48) x=2/3*(a+b)^3-sqrt(|a|)+10*b\n"
            "\n");

    do {
        formula = get_formula();

        a = insert_number(a, a_name);
        b = insert_number(b, b_name);
        
        switch(formula) {
        case 1:
            // Pole
            x=a*b;
            // Obwód
            y=(2*a)+(2*b);
            printf("Pole: %0.3f\n", x);
            printf("Obwod: %0.3f\n", y);
            break;
        
        case 2:
            // Pole
            x=M_PI*pow(a,2);
            // Obwód
            y=2*M_PI*a;
            printf("Pole: %0.3f\n", x);
            printf("Obwod: %0.3f\n", y);
            break;
        case 3:
            x=(float(a+b))/2;
            printf("Wynik: %0.3f\n", x);
            break;
        case 41:
            // First formula
            x=2*(a*a) + (b*b);
            x=sqrt(2*pow(a, 2) + pow(b, 2));
            printf("Wynik: %0.3f\n", x);
            break;
        case 42:
            // Second formula
            x=(a*sin(b))/cbrt(27);
            printf("Wynik: %0.3f\n", x);
            break;
        case 43:
            // Third formula
            x=sqrt(abs(a-b))+pow(a, 3);
            printf("Wynik: %0.3f\n", x);
            break;
        case 44:
            // Fourth formula
            x=cos(2*b)-sqrt(pow(a, 2))+1;
            printf("Wynik: %0.3f\n", x);
            break;
        case 45:
            // Fifth formula
            x=(a+sin(b))/(abs(pow(a,3))+1);
            printf("Wynik: %0.3f\n", x);
            break;
        case 46:
            // Sixth formula
            x=cbrt(a-b*cos(a));
            printf("Wynik: %0.3f\n", x);
            break;
        case 47:
            // Seventh formula
            x=a+sqrt(pow(a, 2)+pow((pow(a,2)-a)/3, 2));
            printf("Wynik: %0.3f\n", x);
            break;
        case 48:
            // Eigth formula
            x=2.0/3.0*pow(a+b, 3)-sqrt(abs(a))+10*b;
            printf("Wynik: %0.3f\n", x);
            break;
        default:
            printf("Wybierz poprawny numer: ");
            scanf("%d", &formula);
            break;
    } 
    
    } while(search_for_number(formulaArray, formula) && !(sizeof(a) == sizeof(int) && sizeof(b) == sizeof(int)));
        

    return 0;
}
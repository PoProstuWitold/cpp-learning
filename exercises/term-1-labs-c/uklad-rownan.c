#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "Układ równań"

int insert_number(char const name[]);
float * calculate_uklad(float a1x, float a2x, float b1y, float b2y, float c1, float c2);
void empty_stdin(void);
void print_author_info(void);

int main() {
    float a1, a2, b1, b2, c1, c2, w, wx, wy;
    float *r;

    do {
        a1 = insert_number("a1");
        a2 = insert_number("a2");
        b1 = insert_number("b1");
        b2 = insert_number("b2");
        c1 = insert_number("c1");
        c2 = insert_number("c2");

        r = calculate_uklad(a1, a2, b1, b2, c1, c2);
        printf("w=%f\n", r[0]);
        printf("wx=%f\n", r[1]);
        printf("wy=%f\n", r[2]);
        printf("x=%f\n", r[1]/r[0]);
        printf("y=%f\n", r[2]/r[0]);

    } while (isdigit(a1) && isdigit(a2) && isdigit(b1) && isdigit(b2) && isdigit(c1) && isdigit(c2));
    

    return 0;
}

float * calculate_uklad(float a1, float a2, float b1, float b2, float c1, float c2) {
    float w, wx, wy;
    static float r[2];

    w=a1*b2-a2*b1;
    wx=c1*b2-c2*b1;
    wy=a1*c2-a2*c1;

    w = a1*b2 - b1*a2;
    wx = c1*b2 - b1*c2;
    wy = a1*c2 - c1*a2;

    if(w != 0) {
        r[0] = w;
        r[1] = wx;
        r[2] = wy;

        return r;
    }

    if(wx == 0 && wy == 0) {
        printf("Układ ma nieskończenie wiele rozwiązań");
    } else {
        printf("Układ sprzeczny");
    }

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
#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "bank zadanie"

// 2. Bank oferuje lokatę półroczną oprocentowaną p% w skali roku (pomijamy podatek od 
// zysku). Klient wpłacił X zł. Po jakim czasie wypłaci co najmniej podwojoną kwotę 
// wpłaty? Wyniki: wypłata oraz liczba odnowień lokaty

void print_author_info(void);

int main() { 
    int deposit_renew = 0;
    float p, basic_deposit, enough_money; 
    print_author_info();
    
    printf("Podaj oprocentowanie w skali roku na półroczną lokatę: "); 
    scanf("%f", &p); 
    // p = 0.02;

    printf("Podaj kwotę "); 
    scanf("%f", &basic_deposit);
    
    enough_money = basic_deposit * 2;
    while (basic_deposit < enough_money) {
            basic_deposit=basic_deposit+(basic_deposit*p);
            deposit_renew++;
            printf("depozyt = %0.2f\todnowienia depozytu = %d\n",basic_deposit,deposit_renew);
    }


    return 0;
    
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
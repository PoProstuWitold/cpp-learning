#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "for loops"

void print_author_info(void);

int main() {

    int num, size;
    int size_neg=0, size_1_10=0, size_every_second=0, size_even=0, size_odd=0;
    double sum_sqrt=0.0, sum_neg=0, sum_1_10=0.0, sum_odd=0.0, sum_even=0.0, product_every_sec=1.0;


    print_author_info();

    printf("Enter the value of n: ");
    // TO DO: Input validation
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);

    for(int i=0; i<size; i++) {
        printf("Enter %d of %d number: ", i+1, size);
        scanf("%d", &num);

        sum_sqrt = sum_sqrt + pow(num, 2);

        if(num < 0) {
            size_neg++;
            sum_neg = sum_neg+num;
        }

        if(num >= 1 && num <= 10) {
            size_1_10++;
            sum_1_10 = sum_1_10 + num;
        }

        if(i % 2 == 0 || i == 0) {
            size_every_second++;
            product_every_sec = num * product_every_sec;
        }

        if(num % 2 == 0) {
            size_even++;
            sum_even = sum_even + num;
        }

        if(!(num % 2 == 0)) {
            size_odd++;
            sum_odd = sum_odd + num;
        }
    }

    printf("\nSum of squares of all %d numbers = %lf \n", size, sum_sqrt);
    printf("\nThere are %d negative numbers. Arithmetic mean of them = %lf \n", size_neg, sum_neg/size_neg);
    printf("\nThere are %d numbers from <1,10>. Sum of them = %lf \n", size_1_10, sum_1_10);
    printf("\nThere are %d second number (starting from 1st input). Product of them = %lf \n", size_every_second, product_every_sec);
    printf("\nThere are %d even number. Sum of them = %lf \n", size_even, sum_even);
    printf("\nThere are %d odd number. Sum of them = %lf \n", size_odd, sum_odd);

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
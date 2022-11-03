#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "for loops"

void print_author_info(void);
int insert_number(int num, int num1, int num2);
void empty_stdin(void);

struct size_sum {
    int size;
    double sum;
};


int main() {

    int num;

    struct size_sum basic = { 0, 0.0 };
    struct size_sum negative = { 0, 0.0 };
    struct size_sum basic_1_10 = { 0, 0.0 };
    struct size_sum every_second = { 0, 1.0 };
    struct size_sum even = { 0, 0.0 };
    struct size_sum odd = { 0, 0.0 };

    print_author_info();
    printf("-----------------------------\n");
    basic.size = insert_number(num, 0, 0);
    printf("Enter %d numbers: \n", basic.size);
    
    double array[basic.size];
    int difference, not_match_size = 0, array_size = sizeof(array)/sizeof(array[0]);

    for(int i=0; i<basic.size; i++) {
        // 1. obliczyć i wyświetlić sumę kwadratów liczb
        num = insert_number(num, i+1, basic.size);
        basic.sum += pow(num, 2);

        // 2. obliczyć i wyświetlić średnią arytmetyczną liczb ujemnych
        if(num < 0) {
            negative.size++;
            negative.sum += num;
        }

        // 3. obliczyć i wyświetlić sumę liczb z przedziału <1,10>
        if(num >= 1 && num <= 10) {
            basic_1_10.size++;
            basic_1_10.sum += num;
        }

        // 4. obliczyć i wyświetlić iloczyn co drugiej liczby 
        // (zaczynamy od pierwszej przeczytanej)
        if(i % 2 == 0 || i == 0) {
            every_second.size++;
            every_second.sum *= num;
        }

        // 5. obliczyć i wyświetlić sumę liczb parzystych i sumę nieparzystych
        if(num % 2 == 0) {
            even.size++;
            even.sum += num;
        }
        // 5. obliczyć i wyświetlić sumę liczb parzystych i sumę nieparzystych
        if(!(num % 2 == 0)) {
            odd.size++;
            odd.sum += num;
        }

        // 6. sprawdzić, czy liczby tworzą ciąg arytmetyczny 
        // - jeśli nie, to podać ile liczb „nie pasowało”
        array[i] = num;
        if(i > 1) {
            if(difference != array[i] - array[i-1]) {
                not_match_size++;
            }
                // printf("\ndifference old: %lf\n");
                // printf("\ndifference new: %lf\n", array[i] - array[i-1]);
                difference = array[i] - array[i-1];
        } else {
            difference = array[i] - array[i-1];
        }
    }

    printf("\nThere are %d numbers. Sum of their squares = %lf \n", basic.size, basic.sum);
    printf("\nThere are %d negative numbers. Arithmetic mean of them = %lf \n", negative.size, negative.sum/negative.size);
    printf("\nThere are %d numbers from <1,10>. Sum of them = %lf \n", basic_1_10.size, basic_1_10.sum);
    printf("\nThere are %d second number (starting from 1st input). Product of them = %lf \n", every_second.size, every_second.sum);
    printf("\nThere are %d even number. Sum of them = %lf \n", even.size, even.sum);
    printf("\nThere are %d odd number. Sum of them = %lf \n", odd.size, odd.sum);
    if(not_match_size == 0) {
        printf("\nArray size: %d. All numbers have the same difference which is: %d. CIAG ARYTMETYCZNY\n", array_size, difference);
    } else {
        printf("\nArray size: %d. Not matching for ciag arytmetyczny: %d\n", array_size, not_match_size);
    }

    for(int j=0; j<array_size; j++) {
        printf("array %d: %0.1lf\t", j+1, array[j]);
    }

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}

int insert_number(int num, int num1, int num2) {
        for (;;) {  
            int rtn = 0;
            
            if(num1 == 0 && num2 == 0) {
                printf("Enter how many numbers you want to insert: ");
            } else {
                printf("Enter %d of %d number: ", num1, num2);
            }

            rtn = scanf ("%d", &num);

            if (rtn == EOF) {
                return 1;
            }
            else if (rtn == 0) {
                printf(" Błąd: Liczba nie jest numerem rzeczywistym\n");
                empty_stdin();
            }
            else {
                empty_stdin();
                break;
            }
        }

    return num;
}

void empty_stdin(void) { 
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}
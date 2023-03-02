#include <stdio.h>
#include <math.h>

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "powtorzenie for 1 (bez tablic)"

// 1.Proszę wczytać Nwyników pomiarów(liczb),
// wartości końców przedziału <A,B>orazobliczyć,
// wyświetlić sumę tych wynikówpomiarów, które należądo <A, B>.

void print_author_info(void);

int main() { 
    print_author_info();

    int n = 0, i = 0;
    float num, sum = 0, a = 0.0, b=0.0;

    printf("Wprowadz n liczb: ");
    scanf("%d", &n);

    printf("Wprowadz dolna i gorna granice przedzialu oddzielone spacja: ");
    scanf("%f %f", &a, &b);

    while(!(a <= b)) {
        printf("Wprowadz przedzial taki, ze 'a' <= 'b': ");
        scanf("%f %f", &a, &b);
    }

    for(i=0; i<n; i++) {
        printf("Wprowadz %d. liczbe: ", i + 1);
        scanf("%f", &num);

        if(num >= a && num <= b) {
            sum += num;
        }

    }

    printf("Suma liczb nalezacych do przedzialu [%f, %f] wynosi: %f", a, b, sum);

    return 0;
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
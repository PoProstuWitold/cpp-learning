#include <stdio.h>
#include <math.h>

// command to include math.h lib needs to have flag -lm: gcc -o lab lab-10-13.cpp -lm

#define AUTHOR "Witold Zawada"
#define STUDY_INFO "informatyka I stopnia (stacjonarne)/semestr 1"
#define GROUP "I1S 1.10/20"
#define PROGRAM_NAME "Program switch"

void empty_stdin (void);
void print_formulas(void);
void print_author_info(void);
int search_in_array(int *a, int search);
int insert_number(char const name[]);
char get_option(int options[]);

int main() {
    int option1, option2;
    int options1[] = { 1,2 };
    int options2[] = { 1,2 };
    float a, b, x, y;

    // has to be this way to silent gcc compiler warnings
    char const *a_name = "a", *b_name = "b";


    print_author_info();
    print_formulas();

    do {
        option1 = get_option(options1);
        

        // IF
        if(option1 == 1) {
            printf(
            "(1)m/sek -> km/ godz\n"
            "(2)km/godz -> m/sek\n"
            "\n");
            option2 = get_option(options2);

            if(option2 == 1) {
                printf("\nPodaj liczbe prędkość w m/sek: ");
                a = insert_number(a_name);
                x=(a*18.0)/5.0;
                printf("Prędkość w km/h: %f\n", x);
            } else if(option2 == 2) {
                printf("\nPodaj liczbe prędkość w km/h: ");
                a = insert_number(a_name);
                y=a*(5.0/18.0);
                printf("Prędkość w m/sek: %f\n", y);
            } else {
                printf("Wybierz poprawny numer xD1: ");
                scanf("%d", &option2);
            }
            
        } else if(option1 == 2) {
             printf(
            "(1)stopnie -> radiany\n"
            "(2)radiany -> stopnie\n"
            "\n");
            option2 = get_option(options2);

            if(option2 == 1) {
                printf("\nPodaj liczbe miara kąta w stopniach: ");
                b = insert_number(b_name);
                x=b*(M_PI/180);
                printf("Miara kąta w radianach: %f\n", x);
            } else if(option2 == 2) {
                printf("\nPodaj liczbe miara kąta w radianach: ");
                b = insert_number(b_name);
                y=b*(M_PI/180);
                printf("Miara kąta w stopniach: %f\n", y);
            } else {
                printf("Wybierz poprawny numer xD1: ");
                scanf("%d", &option2);
            }

        } else {
            printf("Wybierz poprawny numer xDmast: ");
            scanf("%d", &option1);
        }
        
        // SWITCH CASE
        // switch(option1) {
        //     case 1:
        //             printf(
        //                 "(1)m/sek -> km/ godz\n"
        //                 "(2)km/godz -> m/sek\n"
        //                 "\n");
        //             option2 = get_option(options2);
        //         switch (option2) {
        //             case 1:
        //                 printf("\nPodaj liczbe prędkość w m/sek: ");
        //                 scanf("%f", &a);
        //                 x=(a*18.0)/5.0;
        //                 printf("Prędkość w km/h: %f\n", x);
        //                 break;
        //             case 2:
        //                 printf("\nPodaj liczbe prędkość w km/h: ");
        //                 scanf("%f", &a);
        //                 y=a*(5.0/18.0);
        //                 printf("Prędkość w m/sek: %f\n", y);
        //                 break;
                    
        //             default:
        //                 printf("Wybierz poprawny numer xD1: ");
        //                 scanf("%d", &option2);
        //                 break;
        //             }
        //         break;
            
        //     case 2:
        //         printf(
        //                 "(1)stopnie -> radiany\n"
        //                 "(2)radiany -> stopnie\n"
        //                 "\n");
        //             option2 = get_option(options2);
        //         switch (option2) {
        //                 case 1:
        //                     printf("\nPodaj liczbe miara kąta w stopniach: ");
        //                     scanf("%f", &b);
        //                     x=b*(M_PI/180);
        //                     printf("Miara kąta w radianach: %f\n", x);
        //                     break;
        //                 case 2:
        //                     printf("\nPodaj liczbe miara kąta w radianach: ");
        //                     scanf("%f", &b);
        //                     y=b*(M_PI/180);
        //                     printf("Miara kąta w stopniach: %f\n", y);
        //                     break;
                      
        //                 default:
        //                     printf("Wybierz poprawny numer xD2: ");
        //                     scanf("%d", &option2);
        //                     break;
        //                 }
        //             break;
        //     default:
        //         printf("Wybierz poprawny numer xDmast: ");
        //         scanf("%d", &option1);
        //         break;
        // } 
    
    } while(search_in_array(options1, option1) && search_in_array(options2, option2) && !(sizeof(a) == sizeof(int)));
        

    return 0;
}

// empty stdin helper
void empty_stdin (void) { 
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

//search for int in array
int search_in_array(int *a, int search) {
    int arrLen = sizeof a / sizeof a[0];
    for(int i = 0; i < arrLen; i++) {
        if(a[i] == search) {      
            return 1;
        }
    }

    return 0;
}

char get_option(int options[]) {
    int userChoice, rtn = 0;

    for (;;) {  
        
        printf("\nPodaj opcję:");
        rtn = scanf ("%d", &userChoice);    

        if (rtn == EOF) {   
            return 1;
        }
        else if (rtn == 0) {    
            printf(" Błąd: Wartość nie jest numerem całkowitym.\n");
            empty_stdin();
        }
        else if (!(search_in_array(options, userChoice))) {  
            printf(" Błąd: Wartość nie odpowiada żadnemu numerowi wzoru.\n");
            empty_stdin();
        }
        else if (search_in_array(options, userChoice)) {  
            empty_stdin();
            break;
        }
        else {
            empty_stdin();
            break;
        }
    }

    return userChoice;
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

void print_formulas(void) {
    printf("-------------WZORY--------------\n"
            "(1)Prędkość w m/sek i km/godz\n"
            "(2)Miara kąta w stopniach i radianach\n"
            "\n");
}

void print_author_info(void) {
    printf("autor: %s\n", AUTHOR),
    printf("kierunek/semestr: %s\n", STUDY_INFO);
    printf("grupa: %s\n", GROUP);
    printf("program: %s \n", PROGRAM_NAME);
}
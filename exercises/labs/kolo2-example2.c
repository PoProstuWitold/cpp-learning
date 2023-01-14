#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hotel {
    char kod_pokoju[3]; //ilosc osob, np. p1, p2, p10
    float cena;
    int status; // wolny-1, zajęty-2
} hotel;

typedef struct Koszt {
    hotel pokoj;
    float koszt;
} koszta;

koszta *koszt(hotel *pokoje, int ilosc);
int wolne(hotel *pokoje, int ilosc);
float zysk(hotel *pokoje, int ilosc);
int rezerwacja(hotel *pokoje, int ilosc);

int main() {
    int ilosc;

    printf("Ile pokoi chcesz wprowadzić? ");
    scanf("%i", &ilosc);

    hotel *pokoje = calloc(ilosc, sizeof(hotel));
    koszta *koszt_osoby;

    for(int i = 0; i < ilosc; i++) {

        printf("Podaj kod (np. 'p1' - pokój jednosobowy) pokoju %d: ", i+1);
        scanf("%s", &pokoje[i].kod_pokoju);

        printf("Podaj cene pokoju %d: ", i+1);
        scanf("%f", &pokoje[i].cena);

        printf("Podaj status pokoju %d (np. wolny-1, zajęty-2): ", i+1);
        scanf("%d", &pokoje[i].status);

        printf("\n");
    }

    koszt_osoby = koszt(pokoje, ilosc);

    printf("Koszt dla 1 osoby w każdym pokoju: \n");
    for(int j = 0; j < ilosc; j++) {
        printf("Pokój %d\n", j + 1);
        printf("\tkod: %s\n", koszt_osoby[j].pokoj.kod_pokoju);
        printf("\tcena: %f\n", koszt_osoby[j].pokoj.cena);
        printf("\tstatus: %d\n", koszt_osoby[j].pokoj.status);
        printf("\tkoszt na osobe: %f\n", koszt_osoby[j].koszt);
    }

    int wolne_pokoje = wolne(pokoje, ilosc);
    printf("Liczba wolnych pokoi: %i\n", wolne_pokoje);

    float zysk_pokoje = zysk(pokoje, ilosc);
    printf("Zysk z aktualnie zajętych pokoi: %.2f\n", zysk_pokoje);

    if (rezerwacja(pokoje, ilosc)) 
        printf("Jest wolny pokój dla 3 osób.\n");
    else 
        printf("Nie ma wolnego pokoju dla 3 osób.\n");


    free(pokoje);

    return 0;
}

koszta *koszt(hotel *pokoje, int ilosc) {
    koszta *koszt_osoby = malloc(ilosc * sizeof(koszta));

    for (int i = 0; i < ilosc; i++) {
        koszt_osoby[i].pokoj = pokoje[i];
        if (strcmp(pokoje[i].kod_pokoju, "p1") == 0) {
            koszt_osoby[i].koszt = pokoje[i].cena;
        }
        if (strcmp(pokoje[i].kod_pokoju, "p2") == 0) {
            koszt_osoby[i].koszt = (pokoje[i].cena / 2);
        }
        if (strcmp(pokoje[i].kod_pokoju, "p3") == 0) {
            koszt_osoby[i].koszt = (pokoje[i].cena / 3);
        }
    }
    return koszt_osoby;
}

int wolne(hotel *pokoje, int ilosc) {
    int ile_wolnych = 0;
    for (int i = 0; i < ilosc; i++) {
        if (pokoje[i].status == 1) {
            ile_wolnych++;
        }
    }
    return ile_wolnych;
}

float zysk(hotel *pokoje, int ilosc) {
    float zysk = 0;
    for (int i = 0; i < ilosc; i++) {
        if (pokoje[i].status == 2) {
            zysk += pokoje[i].cena;
        }
    }
    return zysk;
}

int rezerwacja(hotel *pokoje, int ilosc) {
    for (int i = 0; i < ilosc; i++) {
        if (strcmp(pokoje[i].kod_pokoju, "p3") == 0 && pokoje[i].status == 1) {
            return 1;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hotel {
    char * kod_pokoju; // ilosc osob, np. p1, p2, p3
    float cena; // 40, 60, 100...
    int status; // wolny-1, zajęty-2
} hotel;

typedef struct Koszt {
    hotel pokoj;
    float koszt;
} cost;

cost* koszt(hotel *pokoje, int ilosc);
hotel* wolne(hotel *pokoje, int ilosc, int *ile_wolnych);
float zysk(hotel *pokoje, int ilosc);
int rezerwacja(hotel *pokoje, int ilosc);

int main() {
    int ilosc;
    printf("Ile pokoi chcesz wprowadzić? ");
    scanf("%i", &ilosc);

    hotel *pokoje = calloc(ilosc, sizeof(hotel));
    for(int i = 0; i < ilosc; i++) {
        printf("Podaj kod (np. 'p1' - pokój jednosobowy) pokoju %d: ", i+1);
        scanf("\n%m[^\n]", &pokoje[i].kod_pokoju);
        printf("Podaj cene pokoju %d: ", i+1);
        scanf("%f", &pokoje[i].cena);
        printf("Podaj status pokoju %d (np. wolny-1, zajęty-2): ", i+1);
        scanf("%d", &pokoje[i].status);
    }

    cost *koszt_osoby = koszt(pokoje, ilosc);
    printf("Koszt dla 1 osoby w każdym pokoju: \n");
    for(int j = 0; j < ilosc; j++) {
        printf("Pokój %d\n", j + 1);
        printf("\tkod: %s\n", koszt_osoby[j].pokoj.kod_pokoju);
        printf("\tcena: %f\n", koszt_osoby[j].pokoj.cena);
        printf("\tstatus: %d\n", koszt_osoby[j].pokoj.status);
        printf("\tkoszt na osobe: %f\n", koszt_osoby[j].koszt);
    }

    int ile_wolnych = 0;
    hotel *wolne_pokoje = wolne(pokoje, ilosc, &ile_wolnych);
    printf("Wolne pokoje: %i\n", ile_wolnych);
    for(int k = 0; k < ile_wolnych; k++) {
        printf("Pokój %d\n", k + 1);
        printf("\tkod: %s\n", wolne_pokoje[k].kod_pokoju);
        printf("\tcena: %f\n", wolne_pokoje[k].cena);
        printf("\tstatus: %d\n", wolne_pokoje[k].status);
    }

    float zysk_pokoje = zysk(pokoje, ilosc);
    printf("Zysk z aktualnie zajętych pokoi: %.2f\n", zysk_pokoje);

    if (rezerwacja(pokoje, ilosc)) 
        printf("Jest wolny pokój dla 3 osób.\n");
    else 
        printf("Nie ma wolnego pokoju dla 3 osób.\n");

    return 0;
}

cost* koszt(hotel *pokoje, int ilosc) {
    cost *koszt_osoby = malloc(ilosc * sizeof(cost));

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

hotel* wolne(hotel *pokoje, int ilosc, int *ile_wolnych) {
    int _ile_wolnych = 0;
    int helper_index = 0;

    for (int i = 0; i < ilosc; i++) {
        if (pokoje[i].status == 1) {
            _ile_wolnych++;
        }
    }
    
    hotel *wolne_pokoje = malloc(_ile_wolnych * sizeof(hotel));

    for (int j = 0; j < ilosc; j++) {
        if (pokoje[j].status == 1) {
            wolne_pokoje[helper_index] = pokoje[j];
            helper_index++;
        }
    }

    *ile_wolnych = _ile_wolnych;

    return wolne_pokoje;
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
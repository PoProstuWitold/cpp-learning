int main(int argc, char* argv[]) { 
    int j, i, n, *x; // x wskaznik liczby calkowitej, to bedzie tablica liczb

    printf("podaj ilosc liczb ");
    scanf("%d", &n); 

    x=(int*)malloc(n*sizeof(int));// rezerwacja pamięci dla n liczb całkowitych

    printf("dane"); 

    for(i=0;i<n;i++) { 
        printf("\nLiczba: "); 
        scanf("%d", x+i); // zapis wskaźnikowy
    } 

    printf("wpisanie liczb ujemnych z danej tablicy do nowej tablicy");
    int *NX; //deklaracja wskaznika dla nowej tablicy
    NX=(int*)malloc(sizeof(int)); // rezerwacja pamięci dla 1 liczby calkowitej 
    j=0; //zmienna j jest nr kolejnej przepisywanej liczby, 

    //a jednocześnie inf. ile aktualnie liczb jest w nowej tablicy
    for(i=0;i<n;i++) { 
        if(x[i]< 0) { 
            NX[j]=x[i];
            j++; //znalazła się kolejna liczba, więc zwiększamy j
            NX=(int*)realloc(NX,(j+1)*sizeof(int));// zmiana rezerwacji dla NX
        } //-teraz rezerwacja dla j+1liczb całkowitych
    }

    if (j>0) { //zmienna j jest inf. ile liczb wpisano do nowej tablicy
        printf("\nelementy danej tablicy\n");
        for(i=0;i<n;i++)
            printf("%d\t", x[i]);
            printf("\nelementy nowej tablicy\n");
        for(i=0;i<j;i++) //w nowej tablicy jest j liczb, dlatego taki zakres pętli
            printf("%d\t", NX[i]);
    } else printf("\nbrak liczb spelniajacych warunki\n");

    
    return 0;
}

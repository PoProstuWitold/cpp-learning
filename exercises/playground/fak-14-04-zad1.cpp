#include <iostream>

using namespace std;

int main() {
    cout << "Fakultety 14/04/2023 - zad 01" << endl;
    int n, iloscParzystych = 0, iloscNieparzystych = 0;
    float suma = 0, sumaNieparzystych = 0;
    
    for (int i = 0; i < 10; i++) {
        cout << "Podaj " << i + 1 << ". liczbę: ";
        cin >> n;

        suma += n;

        if (n % 2 == 0) {
            iloscParzystych++;
        } else {
            iloscNieparzystych++;
            sumaNieparzystych += n;
        }
    }

    double srednia = suma / 10.0;
    double sredniaNieparzystych;


    cout << "Suma: " << suma << endl;
    cout << "Średnia: " << srednia << endl;
    cout << "Liczba parzystych: " << iloscParzystych << endl;
    if (iloscNieparzystych > 0) {
        sredniaNieparzystych = sumaNieparzystych / iloscNieparzystych;
        cout << "Średnia arytmetyczna liczb nieparzystych: ";
        cout << sredniaNieparzystych << endl;
    }

    return 0;
}
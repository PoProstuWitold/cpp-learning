#include <iostream>
using namespace std;

int main() {
    int dn, niedziele = 0;

    cout << "Podaj numer dnia w 2023 roku: ";
    cin >> dn;

    // Sprawdzenie, czy numer dnia jest w przedziale [1, 365]
    if (!(dn >= 1 && dn <= 365)) {
        cout << "Niepoprawny numer dnia" << endl;
    }
    
    // Obliczenie liczby niedziel i wyświetlenie numerów tych niedziel
    for (int i = 1; i <= dn; i++) {
        if (i % 7 == 1) {
            niedziele++;
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Liczba niedziel do dnia " << dn << " w 2023 roku: " << niedziele << endl;

    return 0;
}
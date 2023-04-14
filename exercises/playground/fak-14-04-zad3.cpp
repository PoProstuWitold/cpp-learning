#include <iostream>
using namespace std;

int main() {
    int n, i = 1;
    
    while (i <= 3) { // Pętla wykonuje się trzy razy
        cout << "Podaj liczbe n (proba " << i << "): ";
        cin >> n;
        
        if (n <= 0) { // Sprawdzenie, czy n jest liczbą naturalną dodatnią
            cout << "Podana liczba nie jest liczba naturalna dodatnia." << endl;
            i++;
        } else {
            // Wypisanie ciągu liczb naturalnych parzystych mniejszych lub równych n w porządku malejącym
            cout << "Ciąg liczb naturalnych parzystych mniejszych lub równych " << n << ":" << endl;
            for (int j = n; j >= 2; j -= 2) {
                cout << j << " ";
            }
            cout << endl;
            break; // Przerwanie pętli, jeśli podana liczba jest poprawna
        }
    }

    if (i > 3) { // Komunikat, jeśli użytkownik trzy razy podał niepoprawne dane
        cout << "Przekroczono maksymalna liczbe prob." << endl;
    }
    
    return 0;
}
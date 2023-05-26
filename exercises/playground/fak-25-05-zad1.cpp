#include <iostream>

using namespace std;

int main() {
    int n;
    int tries = 0;
    bool valid;

    do {
        valid = true;
        cout << "Podaj ilosc elementow: ";
        cin >> n;
        tries++;
    } while (!valid && tries < 3);

    if(!valid) {
        cout << "Nie udalo sie wprowadzic poprawnej ilosci elementow.";
        return 1;
    }

    int T[n];
    for (int i = 0; i < n; i++) {
        cout << "Podaj element " << i + 1 << ": ";
        cin >> T[i];
    }

    int min = T[0];
    int min_index = 0;
    int min_count = 1;

    for (int i = 1; i < n; i++) {
        if (T[i] < min) {
            min = T[i];
            min_index = i;
            min_count = 1;
        } else if (T[i] == min) {
            min_count++;
        }
    }	

    cout << "Element minimalny: " << min << endl;
    cout << "Pierwsze wystapienie: " << min_index << endl;
    cout << "Liczba elementow minimalnych: " << min_count << endl;
    cout << "Indeksy: ";
    for (int i = 0; i < n; i++) {
        if (T[i] == min) {
            cout << i << " ";
        }
    }
    cout << endl;


    return 0;
}

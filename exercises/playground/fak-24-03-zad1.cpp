#include <iostream>

using namespace std;

int main() {
    int elMin, elMax;

    int a1, a2, a3;
    cout << "Fakultety 24/03/2023 - zad 01" << endl;
    
    cout << "Podaj 3 liczby calkowite: ";

    cin >> a1 >> a2 >> a3;

    if(a1 > a2) {
        elMax = a1;
        elMin = a2;
    } else {
        elMax=a2;
        elMin=a1;
    }

    if(elMax<a3) {
        elMax = a3;
    } else {
        if(elMin>a3) {
            elMin = a3;
        }
    }

    cout << "elMin = " << elMin << endl;
    cout << "elMax = " << elMax << endl;

    return 0;
}
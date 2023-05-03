#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
void wczytajPlik(string *&tekst, string *pattern, int *n);
void kr(string pattern, string text, int lenP, int lenT, int p, int off, int *&index);

int main() {
    string *tekst;
    int *index;
    int N, dlT;

    string pattern;
    wczytajPlik(tekst, &pattern, &N);

    int dlW = pattern.length();

    cout << "Wzorzec: " << pattern << endl
         << endl;

    for (int i = 0; i < N; i++) {
        dlT = tekst[i].length();

        kr(pattern, tekst[i], dlW, dlT, N, 'a', index);

        cout << "Linijka " << i + 2 << " - Tekst: " << tekst[i] << endl;
        if (index[dlT + 1] == -1) {
            cout << "Linijka " << i + 2 << ":"
                 << " Nie ma wzorca w tekscie!" << endl;
            continue;
        }

        cout << "Linijka " << i + 2 << ": ";
        for (int j = 0; j <= index[dlT + 1]; j++) {
            cout << index[j];
            if (j != index[dlT + 1])
                cout << ", ";
        }
        cout << endl;
    }
    return 0;
}

long make_hash(long HASH, int s, int off, int p, int exp) {
    return (s - off) * pow(p, exp);
}

long update_hash(int HASH, int s_prev, int s_next, int off, int p, int exp) {
    long u_hash = HASH - (s_prev - off) * pow(p, exp);
    u_hash = u_hash * p;
    return u_hash + (s_next - off);
}

void kr(string pattern, string text, int lenP, int lenT, int p, int off, int *&index) {
    long
        hashP = 0,
        hashT = 0;
    int i = 0;

    index = new int[lenT + 2];
    int e = -1;

    for (; i < lenP; i++) {
        hashP = hashP +
                make_hash(hashP, pattern[i], off, p, lenP - i - 1);
        hashT = hashT +
                make_hash(hashT, text[i], off, p, lenP - i - 1);
    }
    i = lenP;
    int j = 0;
    while (i <= lenT) {
        if (hashP == hashT) {
            index[e + 1] = j;
            e++;
        }
        if (i < lenT) {
            hashT = update_hash(hashT, text[j], text[i], off, p, lenP - 1);
        }
        i++;
        j++;
    }
    index[lenT + 1] = e;
}

void wczytajPlik(string *&tekst, string *pattern, int *n) {
    string linia, pomoc;
    ifstream plik, plikTemp;

    plikTemp.open("tekst.txt");
    plik.open("tekst.txt");

    int N = -1;
    while (getline(plikTemp, pomoc))
        N++;
    plikTemp.close();

    plik >> *pattern;
    tekst = new string[N];
    for (int i = 0; i < N; i++) {
        plik >> linia;
        stringstream ss(linia);
        getline(ss, tekst[i]);
    }
    plik.close();
    *n = N;
}

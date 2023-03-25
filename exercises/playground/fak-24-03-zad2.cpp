#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Fakultety 24/03/2023 - zad 02" << endl;
    float a, b, c;
    // arytmetyczny - reszta, geometryczny - iloraz, staly - reszta =/= 0, iloraz = 1
    bool carytm, cgeom, cstaly;

    int reszta, iloraz;
    
    cout << "Podaj 3 liczby calkowite: ";

    cin >> a >> b >> c;

    // staly
    if(a == b && b == c) {
        cstaly = true;
        cout << "Ciag staly" << endl;
    }
   
    // arytmetyczny
    if(b-a == c-b || c-a == b-c) {
        carytm = true;
        cout << "Ciag arytmetyczny" << endl;
    }

    // geometryczny
    if(
        !(a==0 || b==0 || c==0) &&
        (a*c == b*b || b*c == a*a || a*b == c*c)
    ) {
        cgeom = true;
        cout << "Ciag geometryczny" << endl;
    }

    if(!cstaly && !carytm && !cgeom) {
        cout << "Podane liczby nie pasuja do zadnego ciagu" << endl;
    }


    return 0;
}
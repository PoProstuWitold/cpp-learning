#include <iostream>

using namespace std;

bool areDigitsSame(int num) {
    int digit = num % 10;
    while (num) {
        if (num % 10 != digit)
            return false;
        num /= 10;
    }
    return true;
}

int mirrorNumber(int num) {
    int reversed = 0;
    while (num) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

bool isPalindrome(int num) {
    return num == mirrorNumber(num);
}

int main() {
    int a;
    cout << "Podaj liczbe calkowita a, a > 0: ";
    cin >> a;

    if (areDigitsSame(a))
        cout << "Wszystkie cyfry liczby sa takie same." << endl;
    else
        cout << "Nie wszystkie cyfry liczby sa takie same." << endl;

    cout << "Liczba 'lustro' to: " << mirrorNumber(a) << endl;

    if (isPalindrome(a))
        cout << "Podana liczba jest palindromem." << endl;
    else
        cout << "Podana liczba nie jest palindromem." << endl;

    return 0;
}

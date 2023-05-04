#include <iostream>
#include <string>

using namespace std;

string algorytmCezara(string message, int key);
string rozszyfruj(string changedMessage, int key);


int main() {
    string message;
    int key;

    cout << "Podaj wiadomosc do zaszyfrowania: ";
    getline(cin, message);
    cout << "Podaj klucz: ";
    cin >> key;
    string encrypted = algorytmCezara(message, key);
    cout << "Zaszyfrowana wiadomosc: " << encrypted << endl;

    string decrypted = rozszyfruj(encrypted, key);
    cout << "Rozszyfrowana wiadomosc: " << decrypted << endl;

    return 0;
}

string algorytmCezara(string message, int key) {
    string encryptedMessage;
    
    char encryptedLetter;
    for(int i = 0; i < message.length(); i++) {
        if(message[i] != ' ') {
            encryptedLetter = ((toupper(message[i]) - 'A' + key) % 26) + 'A';
        } else {
            encryptedLetter = ' ';
        }
        // cout << "message[i]: " << message[i] << " encryptedLetter: " << encryptedLetter << endl;
        encryptedMessage += encryptedLetter;
    }

    return encryptedMessage;
}

string rozszyfruj(string changedMessage, int key) {
    string message;

    char decryptedLetter;
    for(int i = 0; i < changedMessage.length(); i++) {
        if(changedMessage[i] != ' ') {
            decryptedLetter = ((toupper(changedMessage[i]) - 'A' - key + 26) % 26) + 'A';
        } else {
            decryptedLetter = ' ';
        }
        // cout << "message[i]: " << message[i] << " encryptedLetter: " << decryptedLetter << endl;
        message += decryptedLetter;
    }

    return message;
}
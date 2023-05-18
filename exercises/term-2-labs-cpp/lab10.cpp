#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using std::cin, std::cout, std::endl, std::string, std::ifstream;

struct Node {
    char data;
    Node* next;
} typedef node;

struct Queue {
    node* head = NULL;
    node* tail = NULL;
} typedef queue;


void enqueue(Queue& q, char val);
bool isEmpty(queue& q);
char dequeue(queue& q);
void clear(queue& q);
void readFromFile(queue& q, string filename);
char generateRandomChar();

int main() {
    srand(time(0));
    queue q;

    int choice{1};
    string filename{};
    char val{};

    while (choice != 0) {
        cout << "--------------------KOLEJKA-w-C++------------------\n";
        cout << "1. Sprawdz czy kolejka jest pusta\n";
        cout << "2. Dodaj element do kolejki\n";
        cout << "3. Usun element z kolejki\n";
        cout << "4. Pobierz element z kolejki\n";
        cout << "5. Usun wszystkie elementy z kolejki\n";
        cout << "6. Wczytaj duze litery alfabetu lacinskiego z pliku\n";
        cout << "7. Wyjscie z programu\n";
        cout << "---------------------------------------------------\n";
        cout << "Wybierz opcje: ";
        
        cin >> choice;

        switch (choice) {
            case 1:
                cout << (isEmpty(q) ? "Kolejka JEST pusta\n" : "Kolejka NIE JEST pusta\n");
                break;
            case 2:
                val = generateRandomChar();
                enqueue(q, val);
                cout << "Dodano wartosc " << val << " do kolejki\n";
                break;
            case 3:
                val = dequeue(q);
                if(val)
                    cout << "Usunieto wartosc " << val << " z kolejki\n";
                break;
            case 4:
                if(isEmpty(q)) 
                    cout << "Kolejka JEST pusta\n";
                else
                    cout << "Pierwszy element w kolejce: " << q.head->data << "\n";
                break;
            case 5:
                clear(q);
                cout << "Wyczyszczono kolejke\n";
                break;
            case 6:
                filename = "znaki2.txt";
                readFromFile(q, filename);
                cout << "Wypelniono kolejke znakami z pliku: " << filename << "\n";
                break;
            case 7:
                choice = 0;
                cout << "Program zakonczyl dzialanie\n";
                break;
            default:
                cout << "Nieznana opcja\n";
                break;
        }
    }
}

void enqueue(Queue& q, char val) {
    node* newNode = new node;
    newNode->data = val;
    newNode->next = NULL;

    if (q.head == NULL) {
        q.head = newNode;
        q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

bool isEmpty(queue& q) {
    return q.head == NULL;
}

char dequeue(queue& q) {
    if (isEmpty(q)) {
        cout << "Kolejka jest pusta, nie da się usunac elementu\n";
        return '\0';
    }

    node* temp = q.head;
    char val = q.head->data;
    q.head = q.head->next;
    delete temp;

    if (q.head == NULL) {
        q.tail = NULL;
    }

    return val;
}

void clear(queue& q) {
    while (!isEmpty(q)) {
        char c = dequeue(q);
        cout << "Usunieto: " << c << endl;
    }
}

void readFromFile(queue& q, string filename) {
    ifstream file(filename);
    char c;
    while (file.get(c)) {
        if (isupper(c))
            enqueue(q, c);
    }
}

char generateRandomChar() {
    return 'A' + rand() % 26;
}
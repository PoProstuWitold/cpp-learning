#include <iostream>

using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Overflow\n\tProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << x << endl;
        arr[++top] = x;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Underflow\n\tProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing " << peek() << endl;

        return arr[top--];
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1;
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1; // or return size() == 0;
    }

    bool isFull() {
        return top == capacity - 1; // or return size() == capacity;
    }
};

int main() {
    cout << "Laboratorium 9: Implementacja stosu" << endl;
    Stack pt(3);
 
    pt.push(1);
    pt.push(2);
 
    pt.pop();
    pt.pop();
 
    pt.push(3);
 
    cout << "The top element is " << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl;
 
    pt.pop();
 
    if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    } else {
        cout << "The stack is not empty\n";
    }

    return 0;
}
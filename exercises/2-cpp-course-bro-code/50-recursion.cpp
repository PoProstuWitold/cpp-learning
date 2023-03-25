#include <iostream>

// void walk(int steps);
int factorial(int num);

int main() {

    // recursion = a programming technique where a function
    //             invokes itself from within
    //             break a complex concept into repeatable single step

    // (iterative vs recursive)

    // advantages = less code and is cleaner
    //              useful for soring and searching algorithms

    // disadvantages = uses more memory
    //                 slower

    std::cout << factorial(10);
    // walk(10);

    return 0;
}


void walk(int steps) {
    // iterational
    // for(int i = 0; i<steps; i++) {
    //     std::cout << "You take step" << std::endl;
    // }

    // recursive
    if(steps > 0) {
        std::cout << "You take step" << std::endl;
        walk(steps - 1);
    }
}


int factorial(int num) {
    // iterational
    // int result = 1;
    // for(int i = 1; i <= num; i++) {
    //     result = result * i;
    // }

    // recursive
    if(num > 1) {
        return num * factorial(num - 1);
    } else {
        return 1;
    }
}

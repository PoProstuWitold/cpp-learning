#include <iostream>

int main() {

    // pointers = variable that stores a memory address of another variable
    //                    sometimes it's easier to work with an address         

    // & address-of operator
    // * dereference operator, to access value stored at memory address pointer is pointing

    std::string name = "Witold";
    std::string *pName = &name;


    int age = 19;
    int *pAge = &age;
    

    // array is already an adress, so no adress-of operator
    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    std::string *pFreePizzas = freePizzas;

    std::cout << *pName << '\n';
    std::cout << *pAge << '\n';
    std::cout << *pFreePizzas << '\n';

    return 0;
}
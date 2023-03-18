#include <iostream>

int main() {

    // memory address = a location in memory where data is stored
    // a memory address can accessed with & (address-of operator)

    std::string name = "Witold";
    int age = 19;
    bool debil = true;

    std::cout << &name << '\n';
    std::cout << &age << '\n';
    std::cout << &debil << '\n';

    return 0;
}
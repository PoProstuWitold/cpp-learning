#include <iostream>

int main() {
    std::string name;


    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // if(name.empty()) {
    //     std::cout << "You didn't enter your name";
    // } else if(name.length() > 12) {
    //     std::cout << "Your name can't be over 12 characters";
    // } else {
    //     std::cout << "Welcome " << name;
    // }

    name.append("Kot");
    std::cout << "Hello " << name << std::endl;

    std::cout << "Hello " << name.at(2) << std::endl;

    name.insert(0, "@");
    std::cout << "Hello " << name << std::endl;

    std::cout << "Hello " << name.find(' ') << std::endl;

    name.erase(0, 3);
    std::cout << "Hello " << name << std::endl;

    name.clear();
    std::cout << "Hello " << name << std::endl;

    return 0;
}
#include <iostream>

class Human {
    public:
        std::string name;
        std::string occupation;
        int age;

        void eat() {
            std::cout << "The person " << name << " is eating" << std::endl;
        }

        void drink() {
            std::cout << "The person " << name << " is drinking" << std::endl;
        }

        void sleep() {
            std::cout << "The person " << name << " is sleeping" << std::endl;
        }
};

class Car{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

        void accelerate() {
            std::cout << "You step on the gas!\n";
        }

        void brake() {
            std::cout << "You step on the brakes!\n";
        }
};

int main() {

    // object = A collection of attributes and methods
    //          They can have characteristics and could perform actions.
    //          Can be used to mimic real world items (eg. Phone, Book, Dog)
    //          Created from a class which acts like "blue-print"

    Human human1;
    human1.name = "Witold";
    human1.occupation = "developer";
    human1.age = 19;
    human1.eat();
    human1.drink();
    human1.sleep();

    Car car1;

    car1.make = "Ford";
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "silver";

    std::cout << car1.make << '\n';
    std::cout << car1.model << '\n';
    std::cout << car1.year << '\n';
    std::cout << car1.color << '\n';

    car1.accelerate();
    car1.brake();

    return 0;
}
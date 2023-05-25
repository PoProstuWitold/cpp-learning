#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Element {
    int number;
    Element* next;
};

struct Single_list {
    Element* head;
    Element* tail;
    int counter;

    Single_list() {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }

    bool is_empty() {
        if(counter == 0) {
            std::cout << "List is empty." << std::endl;
            return true;
        }
        else {
            std::cout << "List is not empty." << std::endl;
            return false;
        }
    }

    void add_element_to_end() {
        Element* new_element = new Element;
        new_element->number = rand() % 50 + 1;
        new_element->next = nullptr;

        if (head == nullptr) {
            head = new_element;
            tail = new_element;
        }
        else {
            tail->next = new_element;
            tail = new_element;
        }

        counter++;
    }

    void add_element_to_front() {
        Element* new_element = new Element;
        new_element->number = rand() % 50 + 1;

        if (head == nullptr) {
            new_element->next = nullptr;
            head = new_element;
            tail = new_element;
        }
        else {
            new_element->next = head;
            head = new_element;
        }

        counter++;
    }

    void add_element_at_position(int position) {
        if (position < 1 || position > counter + 1) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        Element* new_element = new Element;
        new_element->number = rand() % 50 + 1;

        if (position == 1) {
            new_element->next = head;
            head = new_element;
            if (tail == nullptr) {
                tail = new_element;
            }
        }
        else {
            Element* temp = head;
            for (int i = 1; i < position - 1; i++) {
                temp = temp->next;
            }
            new_element->next = temp->next;
            temp->next = new_element;

            if (new_element->next == nullptr) {
                tail = new_element;
            }
        }

        counter++;
    }

    void remove_element_from_end() {
        if (counter == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (counter == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Element* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }

            delete tail;
            tail = temp;
            tail->next = nullptr;
        }

        counter--;
    }

    void remove_element_from_front() {
        if (counter == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Element* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        counter--;
    }

    void remove_element_from_position(int position) {
        if (counter == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (position < 1 || position > counter) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        if (position == 1) {
            remove_element_from_front();
            return;
        }

        Element* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        Element* to_be_deleted = temp->next;
        temp->next = to_be_deleted->next;

        if (to_be_deleted == tail) {
            tail = temp;
        }

        delete to_be_deleted;
        counter--;
    }

    void get_first_element() {
        if (head != nullptr) {
            std::cout << "First element: " << head->number << std::endl;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    }

    void get_last_element() {
        if (tail != nullptr) {
            std::cout << "Last element: " << tail->number << std::endl;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    }

    void calculate_average() {
        if (counter == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Element* temp = head;
        int sum = 0;
        while (temp != nullptr) {
            sum += temp->number;
            temp = temp->next;
        }

        double average = (double)sum / counter;
        std::cout << "Average: " << average << std::endl;
    }

    void find_max_element() {
        if (counter == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Element* temp = head;
        int max_value = temp->number;
        int max_position = 1;
        int current_position = 1;
        while (temp != nullptr) {
            if (temp->number > max_value) {
                max_value = temp->number;
                max_position = current_position;
            }
            temp = temp->next;
            current_position++;
        }

        std::cout << "Max value: " << max_value << ", at position: " << max_position << std::endl;
    }

    void print_list() {
        if (counter == 0) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Element* temp = head;
        while (temp != nullptr) {
            std::cout << temp->number << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }

    void delete_list() {
        while (counter > 0) {
            remove_element_from_front();
        }
    }
};

int main() {
    srand(time(NULL));
    Single_list* list = new Single_list;

    int choice;
    int position;

    do {
        std::cout << "\n1.Check if list is empty"
                  << "\n2.Add element to end"
                  << "\n3.Add element to front"
                  << "\n4.Add element at position"
                  << "\n5.Remove element from end"
                  << "\n6.Remove element from front"
                  << "\n7.Remove element from position"
                  << "\n8.Get first element"
                  << "\n9.Get last element"
                  << "\n10.Calculate average"
                  << "\n11.Find max element"
                  << "\n12.Print list"
                  << "\n13.Delete list"
                  << "\n14.Exit"
                  << "\n\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                list->is_empty();
                break;
            case 2:
                list->add_element_to_end();
                break;
            case 3:
                list->add_element_to_front();
                break;
            case 4:
                std::cout << "Enter position: ";
                std::cin >> position;
                list->add_element_at_position(position);
                break;
            case 5:
                list->remove_element_from_end();
                break;
            case 6:
                list->remove_element_from_front();
                break;
            case 7:
                std::cout << "Enter position: ";
                std::cin >> position;
                list->remove_element_from_position(position);
                break;
            case 8:
                list->get_first_element();
                break;
            case 9:
                list->get_last_element();
                break;
            case 10:
                list->calculate_average();
                break;
            case 11:
                list->find_max_element();
                break;
            case 12:
                list->print_list();
                break;
            case 13:
                list->delete_list();
                break;
            case 14:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }

    } while (choice != 14);

    delete list;

    return 0;
}

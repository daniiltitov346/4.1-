#include "frequency_counter.h"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iostream>

void process_sequence() {
    char choice;
    long long n;

    std::cout << "Choose method ('u' - user input, 'r' - random): ";
    std::cin >> choice;

    std::cout << "Enter count of numbers: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid count!" << std::endl;
        return;
    }

    FrequencyCounter counter;

    if (choice == 'u') {
        std::cout << "Enter numbers (0 to " << counter.get_max_value() << "):" << std::endl;
        for (long long i = 0; i < n; ++i) {
            int num;
            if (std::cin >> num) {
                counter.add_number(num);
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Skipped." << std::endl;
            }
        }
    }
    else if (choice == 'r') {
        std::srand(std::time(nullptr));
        for (long long i = 0; i < n; ++i) {
            int num = std::rand() % (counter.get_max_value() + 1);
            counter.add_number(num);
        }
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }

    counter.print_unique_sorted();
}

int main() {
    process_sequence();
    return 0;
}
//Vector v1(10);
//Vector v2(v1);
//Vector v3 = v1;
//
//Vector v1(10), v2(20);
//v2 = v1;
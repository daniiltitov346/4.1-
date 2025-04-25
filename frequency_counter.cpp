#include "frequency_counter.h"
#include <iostream>

FrequencyCounter::FrequencyCounter() : presence_flags(MAX_VALUE + 1, false) {}

void FrequencyCounter::add_number(int num) {
    if (num >= 0 && num <= MAX_VALUE) {
        presence_flags[num] = true;
    }
}

void FrequencyCounter::print_unique_sorted() const {
    std::cout << "Unique numbers in ascending order: ";
    bool first = true;

    for (int i = 0; i <= MAX_VALUE; ++i) {
        if (presence_flags[i]) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << i;
            first = false;
        }
    }

    if (first) {
        std::cout << "No numbers were added.";
    }
    std::cout << std::endl;
}
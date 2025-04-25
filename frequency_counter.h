#include <vector>

class FrequencyCounter {
private:
    std::vector<bool> presence_flags; // Только флаги наличия чисел
    static const int MAX_VALUE = 10000000;

public:
    FrequencyCounter();
    void add_number(int num);
    void print_unique_sorted() const;
    int get_max_value() const { return MAX_VALUE; }
};


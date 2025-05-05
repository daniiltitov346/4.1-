class FrequencyCounter {
private:
    class Vector {
    private:
        int* data;
        size_t size;
    public:
        Vector(size_t size) : size(size) {
            data = new int[size](); // Инициализация нулями
        }

        ~Vector() {
            delete[] data;
        }

        int& operator[](size_t index) {
            return data[index];
        }

        const int& operator[](size_t index) const {
            return data[index];
        }

        size_t getSize() const {
            return size;
        }
    };

    Vector frequency_vector;
    static const int MAX_VALUE = 10000000;

public:
    FrequencyCounter();
    void add_number(int num);
    void print_unique_sorted() const;
    int get_max_value() const { return MAX_VALUE; }
};


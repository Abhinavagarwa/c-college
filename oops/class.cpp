#include <iostream>

// Template class BiggerFinder with special functions, constructor, and destructor
template <typename T>
class BiggerFinder {
private:
    T num1, num2;

public:
    // Constructor to initialize the class with two numbers
    BiggerFinder(T a, T b) : num1(a), num2(b) {
        std::cout << "BiggerFinder object created with values " << num1 << " and " << num2 << std::endl;
    }

    // Destructor
    ~BiggerFinder() {
        std::cout << "BiggerFinder object destroyed." << std::endl;
    }

    // Special function to find the bigger of the two numbers
    T findBigger() {
        return (num1 > num2) ? num1 : num2;
    }
};

int main() {
    // Example usage with int data type
    BiggerFinder<int> intBiggerFinder(10, 7);
    std::cout << "The bigger number is: " << intBiggerFinder.findBigger() << std::endl;

    // Example usage with double data type
    BiggerFinder<double> doubleBiggerFinder(3.5, 4.2);
    std::cout << "The bigger number is: " << doubleBiggerFinder.findBigger() << std::endl;

    return 0;
}

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    Complex() : real(0.0), imaginary(0.0) {}

    // Constructor with one argument (initialize real and imaginary to equal values)
    Complex(double value) : real(value), imaginary(value) {}

    // Constructor with two arguments (initialize real and imaginary to different values)
    Complex(double realValue, double imaginaryValue) : real(realValue), imaginary(imaginaryValue) {}

    // Function to display the complex number
    void display() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }

    // Overloaded addition operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
};

int main() {
    // Creating objects using different constructors
    Complex c1;                  // Default constructor
    Complex c2(5.0);             // Constructor with one argument
    Complex c3(2.0, 3.0);         // Constructor with two arguments

    // Displaying the complex numbers
    std::cout << "Complex Number 1: ";
    c1.display();

    std::cout << "Complex Number 2: ";
    c2.display();

    std::cout << "Complex Number 3: ";
    c3.display();

    // Adding two complex numbers
    Complex result = c2 + c3;

    // Displaying the result
    std::cout << "\nResult of Addition: ";
    result.display();

    return 0;
}

#include <iostream>

// Forward declaration of class B to let class A know it exists
class B;

// Class A declaration
class A {
private:
    int numA;

public:
    A(int valueA) : numA(valueA) {}

    // Friend function declaration
    friend void findGreatest(const A& objA, const B& objB);
};

// Class B declaration
class B {
private:
    int numB;

public:
    B(int valueB) : numB(valueB) {}

    // Friend function declaration
    friend void findGreatest(const A& objA, const B& objB);
};

// Friend function definition
void findGreatest(const A& objA, const B& objB) {
    if (objA.numA > objB.numB) {
        std::cout << "The greatest number is: " << objA.numA << std::endl;
    } else if (objB.numB > objA.numA) {
        std::cout << "The greatest number is: " << objB.numB << std::endl;
    } else {
        std::cout << "Both numbers are equal." << std::endl;
    }
}

int main() {
    A objA(10);
    B objB(20);
    std::cout<<"enter the numbers  10   20 "<<"\n";
    findGreatest(objA, objB);

    return 0;
}

#include <iostream>
template <typename T>
T square(T num) {
    return num * num;
}
int main() {
      int intNum = 5;
    float floatNum = 3.5;
    double doubleNum = 2.7;
    std::cout << "Square of " << intNum << " is: " << square(intNum) << std::endl;
    std::cout << "Square of " << floatNum << " is: " << square(floatNum) << std::endl;
    std::cout << "Square of " << doubleNum << " is: " << square(doubleNum) << std::endl;
    return 0;
}

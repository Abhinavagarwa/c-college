#include <iostream>
#include <cstring>
#include <cctype>

class String {
private:
    char *str;
    int length;

public:
    // Constructors
    String() : str(nullptr), length(0) {}
    
    String(const char *s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Overload + operator for concatenation
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];

        strcpy(result.str, str);
        strcat(result.str, other.str);

        return result;
    }

    // Overload = operator for string copy
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;

            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Overload <= operator for string comparison
    bool operator<=(const String& other) const {
        return strcmp(str, other.str) <= 0;
    }

    // Function to display the length of a string
    int getLength() const {
        return length;
    }

    // Function to convert to lower case
    void toLower() {
        for (int i = 0; i < length; ++i) {
            str[i] = std::tolower(str[i]);
        }
    }

    // Function to convert to upper case
    void toUpper() {
        for (int i = 0; i < length; ++i) {
            str[i] = std::toupper(str[i]);
        }
    }

    // Function to display the string
    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    String str1("Hello");
    String str2("World");

    // Concatenation
    String result = str1 + str2;
    std::cout << "Concatenation: ";
    result.display();

    // String copy
    String copiedStr = str1;
    std::cout << "Copied String: ";
    copiedStr.display();

    // String comparison
    if (str1 <= str2) {
        std::cout << "str1 is less than or equal to str2" << std::endl;
    } else {
        std::cout << "str1 is greater than str2" << std::endl;
    }

    // Display length
    std::cout << "Length of str1: " << str1.getLength() << std::endl;

    // Convert to lower case
    str1.toLower();
    std::cout << "Lowercase of str1: ";
    str1.display();

    // Convert to upper case
    str1.toUpper();
    std::cout << "Uppercase of str1: ";
    str1.display();

    return 0;
}

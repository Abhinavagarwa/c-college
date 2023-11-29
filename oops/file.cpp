#include <iostream>
#include <fstream>
#include <string>

class Student {
public:
    std::string name;
    int age;
    char sex;
    float height;
    float weight;

    // Function to input student information from the keyboard
    void read() {
        std::cout << "Enter student information:\n";
        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Age: ";
        std::cin >> age;

        std::cout << "Sex (M/F): ";
        std::cin >> sex;

        std::cout << "Height (in meters): ";
        std::cin >> height;

        std::cout << "Weight (in kg): ";
        std::cin >> weight;

        // Clear the input buffer
        std::cin.ignore(numeric_limits<std::streamsize>std::max(), '\n');
    }

    // Function to display student information
    void display() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Sex: " << sex << "\n";
        std::cout << "Height: " << height << " meters\n";
        std::cout << "Weight: " << weight << " kg\n";
    }
};

int main() {
    // Specify the file name
    std::string fileName = "student_info.txt";

    // Create a Student object
    Student student;

    // Open the file for writing
    std::ofstream outputFile(fileName, std::ios::binary);

    // Check if the file is open successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return 1;
    }

    // Read student information from the keyboard
    student.read();

    // Write the student object to the file
    outputFile.write(reinterpret_cast<char*>(&student), sizeof(Student));

    // Close the file
    outputFile.close();

    // Open the file for reading
    std::ifstream inputFile(fileName, std::ios::binary);

    // Check if the file is open successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return 1;
    }

    // Read the student object from the file
    Student readStudent;
    inputFile.read(reinterpret_cast<char*>(&readStudent), sizeof(Student));

    // Close the file
    inputFile.close();

    // Display the read student information
    std::cout << "\nStudent Information Read from File:\n";
    readStudent.display();

    return 0;
}

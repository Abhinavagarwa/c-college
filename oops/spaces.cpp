#include <iostream>
#include <fstream>
#include <string>

void removeWhiteSpaces(const std::string &inputFileName, const std::string &outputFileName) {
    // Open the input file
    std::ifstream inputFile(inputFileName);

    // Check if the input file is open successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file " << inputFileName << std::endl;
        return;
    }

    // Open the output file
    std::ofstream outputFile(outputFileName);

    // Check if the output file is open successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file " << outputFileName << std::endl;
        return;
    }

    // Process each line in the input file
    std::string line;
    while (std::getline(inputFile, line)) {
        // Remove white spaces from the line
        for (char &c : line) {
            if (c != ' ' && c != '\t' && c != '\v' && c != '\n' && c != '\r') {
                outputFile << c;
            }
        }
        outputFile << '\n'; // Add a newline after each processed line
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "White spaces removed successfully. Output saved to " << outputFileName << std::endl;
}

int main() {
    // Specify the input and output file names
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    // Call the function to remove white spaces
    removeWhiteSpaces(inputFileName, outputFileName);

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

void removeWhiteSpaces(const std::string &inputFileName, const std::string &outputFileName) {
    // Open the input file
    std::ifstream inputFile(inputFileName);

    // Check if the input file is open successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file " << inputFileName << std::endl;
        return;
    }

    // Open the output file
    std::ofstream outputFile(outputFileName);

    // Check if the output file is open successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file " << outputFileName << std::endl;
        return;
    }

    // Process each line in the input file
    std::string line;
    while (std::getline(inputFile, line)) {
        // Remove white spaces from the line
        for (char &c : line) {
            if (c != ' ' && c != '\t' && c != '\v' && c != '\n' && c != '\r') {
                outputFile << c;
            }
        }
        outputFile << '\n'; // Add a newline after each processed line
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "White spaces removed successfully. Output saved to " << outputFileName << std::endl;
}

int main() {
    // Specify the input and output file names
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    // Call the function to remove white spaces
    removeWhiteSpaces(inputFileName, outputFileName);

    return 0;
}

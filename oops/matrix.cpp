#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols, 0)) {}

    void setData(const std::vector<std::vector<int>>& input) {
        if (input.size() == static_cast<size_t>(rows) && input[0].size() == static_cast<size_t>(cols)) {
            data = input;
        } else {
            std::cout << "Invalid matrix dimensions." << std::endl;
        }
    }

    void display() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cout << "Matrix dimensions are not compatible for multiplication." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    Matrix matrix1(2, 3);
    matrix1.setData({{1, 2, 3}, {4, 5, 6}});

    Matrix matrix2(3, 2);
    matrix2.setData({{7, 8}, {9, 10}, {11, 12}});

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.display();

    Matrix resultMatrix = matrix1 * matrix2;

    std::cout << "\nResult of Matrix Multiplication:" << std::endl;
    resultMatrix.display();

    return 0;
}

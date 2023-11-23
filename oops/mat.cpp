#include <iostream> 
#include <vector>
class Matrix { 
    private:
std::vector<std::vector<int>> data; int rows;
int cols;
public:
Matrix(int m, int n) : rows(m), cols(n) {
data.resize(m, std::vector<int>(n, 0)); }
void fillMatrix() {
std::cout << "Enter matrix elements row by row:" << std::endl;
for (int i = 0; i < rows; i++) {
   for (int j = 0; j < cols; j++) {
      std::cout << "Enter element at row " << i + 1 << " and column " << j + 1 << ": ";
      std::cin >> data[i][j]; }
    }
}
void printMatrix() {
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
          std::cout << data[i][j] << " "; 
        }
          std::cout << std::endl; 
        }
}
Matrix multiply(Matrix &other) {
if (cols != other.rows) {
std::cerr << "Matrix multiplication not possible. Inner dimensions must match." << std::endl;
return Matrix(0, 0); }
Matrix result(rows, other.cols); 
for (int i = 0; i < rows; i++) {
for (int j = 0; j < other.cols; j++) { 
    int sum = 0;
    for (int k = 0; k < cols; k++) {
        sum += data[i][k] * other.data[k][j];
         }
        result.data[i][j] = sum; 
        }
}
return result; }
};
int main() {
int m, n, p, q;

std::cout << "Enter the dimensions of the first matrix (m x n): "; std::cin >> m >> n;
std::cout << "Enter the dimensions of the second matrix (p x q): "; std::cin >> p >> q;
if (n != p) {
std::cerr << "Matrix multiplication not possible. Inner dimensions must match." << std::endl;
return 1; 
}
Matrix matrix1(m, n);
Matrix matrix2(p, q); matrix1.fillMatrix(); matrix2.fillMatrix();
std::cout << "Matrix 1:" << std::endl; matrix1.printMatrix();
std::cout << "Matrix 2:" << std::endl; matrix2.printMatrix();
Matrix result = matrix1.multiply(matrix2);
if (result.getRows() == 0 || result.getCols() == 0) {
return 1; 
}
std::cout << "Result of Matrix Multiplication:" << std::endl; result.printMatrix();
return 0;
}
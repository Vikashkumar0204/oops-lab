#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int data[10][10]; // 2D array to hold matrix elements

public:
    // Function to get matrix size and elements from the user
    void input() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        
        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Function to print the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Declaring the friend function inside the class
    friend Matrix addMatrices(const Matrix& m1, const Matrix& m2);
};

// Defining the friend function outside the class
Matrix addMatrices(const Matrix& m1, const Matrix& m2) {
    Matrix result;
    
    // Check if the matrices are the same size
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        cout << "\nError: Matrices must have identical dimensions for addition!\n";
        result.rows = 0;
        result.cols = 0;
        return result;
    }

    // Set the size of the result matrix
    result.rows = m1.rows;
    result.cols = m1.cols;

    // Add corresponding elements
    for (int i = 0; i < m1.rows; ++i) {
        for (int j = 0; j < m1.cols; ++j) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    
    return result;
}

int main() {
    Matrix mat1, mat2, sum;

    cout << "--- Matrix 1 ---\n";
    mat1.input();

    cout << "\n--- Matrix 2 ---\n";
    mat2.input();

    // Call the friend function to add them together
    sum = addMatrices(mat1, mat2);

    // Only print the result if the addition was successful
    if (sum.rows != 0 && sum.cols != 0) {
        cout << "\n--- Resultant Matrix (Sum) ---\n";
        sum.display();
    }

    return 0;
}

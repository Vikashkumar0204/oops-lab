#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];

    // 1. Input the 3x3 matrix from the user
    cout << "Enter the elements of a 3x3 matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // 2. Display the original matrix
    cout << "\nOriginal 3x3 Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // 3. Display the Upper Triangular Matrix
    cout << "\nUpper Triangular Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Condition for upper triangle: column index (j) >= row index (i)
            if (i <= j) {
                cout << matrix[i][j] << "\t";
            } else {
                cout << "0\t"; // Prints 0 for elements below the diagonal
            }
        }
        cout << endl;
    }

    return 0;
}

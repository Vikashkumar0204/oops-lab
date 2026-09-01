#include <iostream>
using namespace std;

int main() {
    int n;
    int binaryNum[32]; // Array to store binary digits
    int i = 0;

    // Prompt the user for input
    cout << "Enter a decimal number: ";
    cin >> n;

    // Edge case: if the input number is 0
    if (n == 0) {
        cout << "Binary equivalent: 0" << endl;
        return 0;
    }

    // Loop to convert decimal to binary
    while (n > 0) {
        binaryNum[i] = n % 2; // Store remainder in array
        n = n / 2;            // Divide the number by 2
        i++;                  // Increment array index
    }

    // Display the binary equivalent in reverse order
    cout << "Binary equivalent: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
    cout << endl;

    return 0;
}

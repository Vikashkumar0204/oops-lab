#include <iostream>
using namespace std;

int main() {
    int num, remainder;
    int reversedNum = 0;

    // Take user input
    cout << "Enter an integer: ";
    cin >> num;

    // Store the original number for the final output display
    int originalNum = num; 

    // Handle negative numbers by converting them to positive
    if (num < 0) {
        num = -num;
    }

    // Process the number digits using a do-while loop
    do {
        remainder = num % 10;                  // Extract the last digit
        reversedNum = reversedNum * 10 + remainder; // Append digit to reversed number
        num /= 10;                             // Remove the last digit
    } while (num > 0);

    // If the original input was negative, make the result negative
    if (originalNum < 0) {
        reversedNum = -reversedNum;
    }

    // Print the results
    cout << "Original Number: " << originalNum << endl;
    cout << "Reversed Number: " << reversedNum << endl;

    return 0;
}

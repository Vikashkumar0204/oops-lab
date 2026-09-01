#include <iostream>
using namespace std;

int main() {
    int num, reversedNum = 0, remainder;

    // Prompt user for input
    cout << "Enter an integer: ";
    cin >> num;

    // Loop to reverse the number
    while (num != 0) {
        remainder = num % 10;          // Extract the last digit
        reversedNum = reversedNum * 10 + remainder; // Append digit to reversed number
        num /= 10;                    // Remove the last digit from original number
    }

    // Display the result
    cout << "Reversed Number = " << reversedNum << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int num, originalNum, remainder;
    // Using long long to prevent integer overflow during reversal
    long long reversedNum = 0; 

    cout << "Enter an integer: ";
    cin >> num;

    // Store the original number for final comparison
    originalNum = num; 

    // Negative numbers are not palindromes (e.g., -121 reversed is 121-)
    if (num < 0) {
        cout << originalNum << " is not a palindrome number." << endl;
        return 0;
    }

    // Mathematical logic to reverse the number
    while (num > 0) {
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num /= 10;
    }

    // Check if original and reversed numbers match
    if (originalNum == reversedNum) {
        cout << originalNum << " is a palindrome number." << endl;
    } else {
        cout << originalNum << " is not a palindrome number." << endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

// Function to count the number of digits
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to check if the number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int digits = countDigits(num);
    int sum = 0;

    while (num != 0) {
        int remainder = num % 10;
        
        // round() handles potential floating-point inaccuracies from pow()
        sum += round(pow(remainder, digits)); 
        
        num /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}

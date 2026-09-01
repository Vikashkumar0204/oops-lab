#include <iostream>

int main() {
    int num, originalNum;
    int sum = 0;

    // Input a 3-digit number from the user
    std::cout << "Enter a 3-digit number: ";
    std::cin >> num;

    // Store the original number for display purposes
    originalNum = num;

    // Extract each digit using modulus (%) and division (/) operators
    int first_digit  = num / 100;         // Gets the hundreds place
    int second_digit = (num / 10) % 10;   // Gets the tens place
    int third_digit  = num % 10;          // Gets the units place

    // Add all the digits
    sum = first_digit + second_digit + third_digit;

    // Output the final result
    std::cout << "The sum of the digits of " << originalNum << " is: " << sum << std::endl;

    return 0;
}

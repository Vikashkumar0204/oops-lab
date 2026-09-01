#include <iostream>

int main() {
    long long n;
    std::cout << "Enter a positive integer (n): ";
    std::cin >> n;

    // Handle edge case for invalid inputs
    if (n < 1) {
        std::cout << "Please enter a number greater than or equal to 1." << std::endl;
        return 1;
    }

    // Method 1: Using a standard for-loop (Time Complexity: O(n))
    long long loopSum = 0;
    for (int i = 1; i <= n; ++i) {
        loopSum += i;
    }

    // Method 2: Using the mathematical formula (Time Complexity: O(1))
    // Formula: (n * (n + 1)) / 2
    long long formulaSum = (n * (n + 1)) / 2;

    // Displaying the results
    std::cout << "\n--- Results ---" << std::endl;
    std::cout << "Sum using Loop:    " << loopSum << std::endl;
    std::cout << "Sum using Formula: " << formulaSum << std::endl;

    return 0;
}

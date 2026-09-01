#include <iostream>
using namespace std;

int main() {
    int n;

    // Prompt the user for the number of elements
    cout << "Enter the number of elements (n): ";
    cin >> n;

    // Ensure the array has a valid size
    if (n <= 0) {
        cout << "Please enter a valid array size greater than 0." << endl;
        return 1;
    }

    // Declare a dynamic array of size n
    int* arr = new int[n];
    int sum = 0;

    // Input array elements from the user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Traverse the array and calculate the sum
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Display the final result
    cout << "The sum of all elements in the array is: " << sum << endl;

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}

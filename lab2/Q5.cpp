#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Step 1: Input the size of the array
    cout << "Enter the number of elements (n): ";
    cin >> n;

    // Validate the array size
    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    // Use dynamic arrays (std::vector) to handle runtime sizing safely
    vector<int> originalArr(n);
    vector<int> reversedArr(n);

    // Step 2: Input elements into the original array
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> originalArr[i];
    }

    // Step 3: Copy elements to the new array in reverse order
    for (int i = 0; i < n; i++) {
        // Element at index 'i' goes to index 'n - 1 - i' from the back
        reversedArr[n - 1 - i] = originalArr[i];
    }

    // Step 4: Display the original array
    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) {
        cout << originalArr[i] << " ";
    }

    // Step 5: Display the reversed array
    cout << "\nReversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

    return 0;
}

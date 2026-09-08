#include <iostream>
using namespace std;

class ArraySum {
private:
    int arr[100];
    int size;

public:
    // Constructor to input array elements
    ArraySum(int s) {
        size = s;
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Friend function declaration
    friend int calculateSum(ArraySum *ptr);
};

// Friend function definition using an object pointer
int calculateSum(ArraySum *ptr) {
    int sum = 0;
    for (int i = 0; i < ptr->size; i++) {
        sum += ptr->arr[i]; // Accessing private members via pointer
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Creating object using constructor and passing size
    ArraySum obj(n);

    // Passing the address of the object to the friend function
    int total = calculateSum(&obj);

    cout << "The sum of all elements is: " << total << endl;

    return 0;
}

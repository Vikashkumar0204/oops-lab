#include <iostream>
using namespace std;

class Fibonacci {
private:
    int limit;

public:
    // Default constructor
    Fibonacci() {
        cout << "Enter the number of terms: ";
        cin >> limit;
    }

    // Function to generate and display the series
    void generateSeries() {
        int first = 0, second = 1, next;

        cout << "Fibonacci Series: ";

        for (int i = 0; i < limit; i++) {
            if (i <= 1) {
                next = i; // The first two numbers are 0 and 1
            } else {
                next = first + second;
                first = second;
                second = next;
            }
            cout << next << " ";
        }
        cout << endl;
    }
};

int main() {
    // Creating an object automatically calls the default constructor
    Fibonacci fib; 
    
    // Generating the series
    fib.generateSeries(); 
    
    return 0;
}

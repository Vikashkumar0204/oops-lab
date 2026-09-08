#include <iostream>
#include <cmath> // Needed for the pow() function

using namespace std;

class Armstrong {
private:
    int num;
    int sum;

public:
    // Parameterized Constructor to initialize the original number
    Armstrong(int n) {
        num = n;
        sum = 0;
    }

    // Copy Constructor where the Armstrong calculation takes place
    Armstrong(const Armstrong &obj) {
        // Copy the number from the original object
        num = obj.num; 
        sum = 0;
        
        int temp = num;
        int digits = 0;

        // Step 1: Count the total number of digits
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        // Reset temp to the original number for digit extraction
        temp = num;

        // Step 2: Calculate the sum of digits raised to the power of total digits
        while (temp > 0) {
            int remainder = temp % 10;
            sum += pow(remainder, digits);
            temp /= 10;
        }
    }

    // Function to check if the calculated sum matches the original number
    void checkResult() {
        if (sum == num) {
            cout << num << " is an Armstrong number." << endl;
        } else {
            cout << num << " is not an Armstrong number." << endl;
        }
    }
};

int main() {
    int inputNumber;

    cout << "Enter a number: ";
    cin >> inputNumber;

    // Create the first object using the parameterized constructor
    Armstrong originalObj(inputNumber);

    // Create a second object using the Copy Constructor
    // This triggers the calculation inside the copy constructor
    Armstrong copyObj = originalObj; 

    // Display the final result using the copied object
    copyObj.checkResult();

    return 0;
}

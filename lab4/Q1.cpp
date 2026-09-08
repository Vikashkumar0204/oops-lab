#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Declaration of the friend function
    friend Complex addComplex(Complex c1, Complex c2);

    // Function to display the complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Definition of the friend function (Defined outside the class without ::)
Complex addComplex(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real; // Accessing private data members directly
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main() {
    float r1, i1, r2, i2;

    // Input for first complex number
    cout << "Enter real and imaginary parts of 1st complex number: ";
    cin >> r1 >> i1;
    Complex num1(r1, i1);

    // Input for second complex number
    cout << "Enter real and imaginary parts of 2nd complex number: ";
    cin >> r2 >> i2;
    Complex num2(r2, i2);

    // Adding numbers using friend function
    Complex result = addComplex(num1, num2);

    // Displaying the numbers and result
    cout << "\nFirst Complex Number: ";
    num1.display();
    
    cout << "Second Complex Number: ";
    num2.display();
    
    cout << "Sum: ";
    result.display();

    return 0;
}

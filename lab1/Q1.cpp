#include <iostream>

using namespace std;

int main() {
    // Declare variables for decimal values
    double radius, area, circumference;
    
    // Define the value of PI as a constant
    const double PI = 3.14159265358979323846;

    // Prompt the user to enter the radius
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Calculate area (PI * r^2) and circumference (2 * PI * r)
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    // Display the results
    cout << "\n--- Results ---" << endl;
    cout << "Area of the circle: " << area << endl;
    cout << "Circumference of the circle: " << circumference << endl;

    return 0;
}


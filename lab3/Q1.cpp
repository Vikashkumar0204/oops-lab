#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, designation;
    int code, experience, age;

    // Read input from the keyboard
    cout << "Enter Employee Name: ";
    getline(cin, name);

    cout << "Enter Employee Code: ";
    cin >> code;

    // Clear the input buffer
    cin.ignore(); 

    cout << "Enter Employee Designation: ";
    getline(cin, designation);

    cout << "Enter Years of Experience: ";
    cin >> experience;

    cout << "Enter Age: ";
    cin >> age;

    // Display the output
    cout << "\n--- Employee Information ---\n";
    cout << "1. Employee Name: " << name << endl;
    cout << "2. Employee Code: " << code << endl;
    cout << "3. Employee Designation: " << designation << endl;
    cout << "4. Years of Experience: " << experience << endl;
    cout << "5. Age: " << age << endl;

    return 0;
}

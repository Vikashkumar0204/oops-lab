#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int code;

    // Nested class
    class Details {
    private:
        string designation;
        float salary;

    public:
        void readDetails() {
            cout << "Enter Designation: ";
            cin >> designation;
            cout << "Enter Salary: ";
            cin >> salary;
        }

        void displayDetails() const {
            cout << "Designation: " << designation << endl;
            cout << "Salary: " << salary << endl;
        }
    };

    Details empDetails; // Object of the nested class

public:
    void readEmployee() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Employee Code: ";
        cin >> code;
        empDetails.readDetails(); // Calling nested class function
    }

    void displayEmployee() const {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        empDetails.displayDetails(); // Calling nested class function
    }
};

int main() {
    Employee emp;
    
    emp.readEmployee();
    emp.displayEmployee();

    return 0;
}

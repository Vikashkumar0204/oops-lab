#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SUB = 10;

struct Student {
    string name;
    int rollNo;
    int numSubjects;
    string subjects[MAX_SUB];
    float marks[MAX_SUB];
    float cgpa;
};

void readStudent(Student &s) {
    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter roll number: ";
    cin >> s.rollNo;

    do {
        cout << "Enter number of subjects (1-" << MAX_SUB << "): ";
        cin >> s.numSubjects;
    } while (s.numSubjects < 1 || s.numSubjects > MAX_SUB);
    cin.ignore();   // clear leftover newline before getline

    float total = 0;
    for (int i = 0; i < s.numSubjects; i++) {
        cout << "  Subject " << i + 1 << " name: ";
        getline(cin, s.subjects[i]);
        cout << "  Marks in " << s.subjects[i] << " (out of 100): ";
        cin >> s.marks[i];
        cin.ignore();
        total += s.marks[i];
    }

    // CGPA on a 10-point scale: average marks / 10
    s.cgpa = (total / s.numSubjects) / 10.0f;
}

void displayStudent(const Student &s) {
    cout << "\nName      : " << s.name;
    cout << "\nRoll No   : " << s.rollNo;
    cout << "\nSubjects and marks:\n";
    for (int i = 0; i < s.numSubjects; i++) {
        cout << "  " << left << setw(20) << s.subjects[i]
             << right << setw(6) << s.marks[i] << "\n";
    }
    cout << "CGPA      : " << fixed << setprecision(2) << s.cgpa << "\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    Student students[50];
    if (n < 1 || n > 50) {
        cout << "Please enter a number between 1 and 50.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";
        readStudent(students[i]);
    }

    cout << "\n========== Student Records ==========";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Student " << i + 1 << " ---";
        displayStudent(students[i]);
    }

    return 0;
}

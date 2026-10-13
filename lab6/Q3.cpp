#include <iostream>
#include <string>
using namespace std;

// Root class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "Unknown", int a = 0) : name(n), age(a) {
        cout << "Person constructor called\n";
    }

    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

// virtual inheritance avoids duplicate Person in the TA object
class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string subj) : Person(n, a), subject(subj) {
        cout << "Teacher constructor called\n";
    }

    void teach() const {
        cout << name << " teaches " << subject << ".\n";
    }
};

class Student : virtual public Person {
protected:
    string course;
    float cgpa;

public:
    Student(string n, int a, string c, float g) : Person(n, a), course(c), cgpa(g) {
        cout << "Student constructor called\n";
    }

    void study() const {
        cout << name << " is studying " << course << " (CGPA: " << cgpa << ").\n";
    }
};

// Derived from both Teacher and Student
class TeachingAssistant : public Teacher, public Student {
    int hoursPerWeek;

public:
    // The most derived class must construct the virtual base directly
    TeachingAssistant(string n, int a, string subj, string c, float g, int hrs)
        : Person(n, a), Teacher(n, a, subj), Student(n, a, c, g), hoursPerWeek(hrs) {
        cout << "TeachingAssistant constructor called\n";
    }

    void displayTA() const {
        cout << "\n--- Teaching Assistant Record ---\n";
        displayPerson();  // no ambiguity, only one Person exists
        cout << "Assists in: " << subject << "\n";
        cout << "Enrolled in: " << course << ", CGPA: " << cgpa << "\n";
        cout << "Duty hours/week: " << hoursPerWeek << "\n";
    }
};

int main() {
    TeachingAssistant ta("Ravi", 24, "Data Structures", "M.Tech CSE", 8.7f, 10);

    ta.displayTA();
    ta.teach();   // from Teacher
    ta.study();   // from Student

    return 0;
}

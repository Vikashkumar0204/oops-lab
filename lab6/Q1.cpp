#include <iostream>
#include <string>

// Tier 1: Base Class
class Student {
protected:
    std::string name;
    int id;

public:
    Student(std::string n, int i) : name(n), id(i) {}

    void displayBaseInfo() const {
        std::cout << "ID: " << id << " | Name: " << name << "\n";
    }
};

// Tier 2: Intermediate Class (Inherits from Student)
class Undergraduate : public Student {
protected:
    double gpa;

public:
    Undergraduate(std::string n, int i, double g) : Student(n, i), gpa(g) {}

    void displayGPA() const {
        std::cout << "GPA: " << gpa << "\n";
    }
};

// Tier 3: Derived Class (Inherits from Undergraduate)
class GraduatingSenior : public Undergraduate {
public:
    GraduatingSenior(std::string n, int i, double g) : Undergraduate(n, i, g) {}

    // Method to determine graduation honors based on GPA tier
    std::string determineHonors() const {
        if (gpa >= 3.9) return "Summa Cum Laude";
        if (gpa >= 3.7) return "Magna Cum Laude";
        if (gpa >= 3.5) return "Cum Laude";
        return "Standard Graduation";
    }

    // Displays the full performance profile
    void displayProfile() const {
        displayBaseInfo();
        displayGPA();
        std::cout << "Graduation Status: " << determineHonors() << "\n";
        std::cout << "-----------------------------------\n";
    }
};

int main() {
    std::cout << "--- Academic Portal: Student Performance Tracker ---\n\n";

    // Creating instances of graduating seniors with different performance levels
    GraduatingSenior student1("Alice Smith", 101, 3.95);
    GraduatingSenior student2("Bob Jones", 102, 3.62);
    GraduatingSenior student3("Charlie Brown", 103, 3.20);

    // Displaying tracking information and final honors
    student1.displayProfile();
    student2.displayProfile();
    student3.displayProfile();

    return 0;
}
#include <iostream>
#include <string>

// Tier 1: Base Class
class Student {
protected:
    std::string name;
    int id;

public:
    Student(std::string n, int i) : name(n), id(i) {}

    void displayBaseInfo() const {
        std::cout << "ID: " << id << " | Name: " << name << "\n";
    }
};

// Tier 2: Intermediate Class (Inherits from Student)
class Undergraduate : public Student {
protected:
    double gpa;

public:
    Undergraduate(std::string n, int i, double g) : Student(n, i), gpa(g) {}

    void displayGPA() const {
        std::cout << "GPA: " << gpa << "\n";
    }
};

// Tier 3: Derived Class (Inherits from Undergraduate)
class GraduatingSenior : public Undergraduate {
public:
    GraduatingSenior(std::string n, int i, double g) : Undergraduate(n, i, g) {}

    // Method to determine graduation honors based on GPA tier
    std::string determineHonors() const {
        if (gpa >= 3.9) return "Summa Cum Laude";
        if (gpa >= 3.7) return "Magna Cum Laude";
        if (gpa >= 3.5) return "Cum Laude";
        return "Standard Graduation";
    }

    // Displays the full performance profile
    void displayProfile() const {
        displayBaseInfo();
        displayGPA();
        std::cout << "Graduation Status: " << determineHonors() << "\n";
        std::cout << "-----------------------------------\n";
    }
};

int main() {
    std::cout << "--- Academic Portal: Student Performance Tracker ---\n\n";

    // Creating instances of graduating seniors with different performance levels
    GraduatingSenior student1("Alice Smith", 101, 3.95);
    GraduatingSenior student2("Bob Jones", 102, 3.62);
    GraduatingSenior student3("Charlie Brown", 103, 3.20);

    // Displaying tracking information and final honors
    student1.displayProfile();
    student2.displayProfile();
    student3.displayProfile();

    return 0;
}

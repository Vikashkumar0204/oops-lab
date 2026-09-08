#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Function to set time
    void setTime(int h, int m) {
        hours = h;
        minutes = m;
    }

    // Function to display time
    void displayTime() {
        cout << hours << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
    }

    // Declare friend function to add two Time objects
    friend Time addTime(Time t1, Time t2);
};

// Definition of friend function
Time addTime(Time t1, Time t2) {
    Time temp;
    
    // Add minutes
    temp.minutes = t1.minutes + t2.minutes;
    
    // Convert extra minutes into hours
    temp.hours = t1.hours + t2.hours + (temp.minutes / 60);
    
    // Keep remaining minutes under 60
    temp.minutes = temp.minutes % 60;
    
    return temp;
}

int main() {
    Time t1, t2, t3;

    // Set first time
    t1.setTime(5, 40);
    
    // Set second time
    t2.setTime(3, 35);

    // Add times using friend function
    t3 = addTime(t1, t2);

    cout << "First Time: ";
    t1.displayTime();

    cout << "Second Time: ";
    t2.displayTime();

    cout << "Total Time: ";
    t3.displayTime();

    return 0;
}

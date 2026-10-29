#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Returns 0 = Sunday, 1 = Monday, ..., 6 = Saturday
int dayOfWeek(int d, int m, int y) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y--;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year;
    cout << "Enter year: ";
    cin >> year;

    if (year < 1) {
        cout << "Please enter a valid year.\n";
        return 1;
    }

    if (isLeap(year)) days[1] = 29;

    cout << "\n========== Calendar " << year << " ==========\n";

    for (int m = 1; m <= 12; m++) {
        cout << "\n  --- " << months[m - 1] << " ---\n";
        cout << " Su Mo Tu We Th Fr Sa\n";

        int start = dayOfWeek(1, m, year);

        // leading spaces before the 1st
        for (int i = 0; i < start; i++)
            cout << "   ";

        for (int d = 1; d <= days[m - 1]; d++) {
            cout << setw(3) << d;
            if ((start + d) % 7 == 0)
                cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}

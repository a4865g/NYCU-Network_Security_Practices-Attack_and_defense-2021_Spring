#include <iostream>
using namespace std;

int main() {
    int input_year;
    cout << "Enter a year: ";
    cin >> input_year;
    if (input_year % 4 == 0) {
        if (input_year % 100 == 0) {
            if (input_year % 400 == 0)
                cout << input_year << " is a leap year."<<endl;
            else
                cout << input_year << " is not a leap year."<<endl;
        }
        else
            cout << input_year << " is a leap year."<<endl;
    }
    else
        cout << input_year << " is not a leap year."<<endl;
    return 0;
}
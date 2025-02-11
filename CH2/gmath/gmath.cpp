#include <iostream>
#include <cmath>
#include <string>
#include "gmath.h"
using namespace std;

extern const double PI = 3.141592653589;

double sindegrees(double angle){
    return sin(toradians(angle));
}

double cosdegrees(double angle){
    return cos(toradians(angle));
}

double todegrees(double radians){
    return radians * 180 / PI ;
}

double toradians(double degrees){
    return degrees * PI / 180;
}


double parseexpression(const string& input) {
    size_t pos = input.find('/');
    if (pos != string::npos) {

        string numerator = input.substr(0, pos);
        string denominator = input.substr(pos + 1);

        double num = (numerator == "pi") ? PI : stod(numerator);
        double denom = stod(denominator);

        return num / denom;
    }

    if (input == "pi") return PI;
    return stod(input);// only surppot till pi / n
}


int main() {
    int choice;
    cout << "Select input type:\n";
    cout << "1. Input angle in degrees\n";
    cout << "2. Input angle in radians\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    string input;
    double value;

    if (choice == 1) {
        cout << "Enter the angle in degrees (e.g., 'pi', 'pi/3', '90'): ";
        cin >> input;

        try {
            value = parseexpression(input);
            cout << "sin(" << value << "°) = " << sindegrees(value) << endl;
            cout << "cos(" << value << "°) = " << cosdegrees(value) << endl;
        } catch (const invalid_argument&) {
            cout << "Error: Invalid input!" << endl;
        } catch (const out_of_range&) {
            cout << "Error: Number is out of range!" << endl;
        }
    } else if (choice == 2) {
        cout << "Enter the angle in radians (e.g., 'pi', 'pi/3', '3.14'): ";
        cin >> input;

        try {
            value = parseexpression(input);
            cout << "sin(" << value << " rad) = " << sin(value) << endl;
            cout << "cos(" << value << " rad) = " << cos(value) << endl;
        } catch (const invalid_argument&) {
            cout << "Error: Invalid input!" << endl;
        } catch (const out_of_range&) {
            cout << "Error: Number is out of range!" << endl;
        }
    } else {
        cout << "Invalid choice! Please restart the program." << endl;
    }

    return 0;
}
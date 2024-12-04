#include <iostream>
using namespace std;

void findLargestAndSecondLargest(int numbers[], int size, int &largest, int &second_largest) {
    largest = 0;
    second_largest = 0;

    for (int i = 0; i < size; ++i) {
        int number = numbers[i];
        //use bubble sort
        if (number > largest) {
            second_largest = largest;
            largest = number;
        } else if (number > second_largest) {
            second_largest = number;
        }
    }
}

int main() {
    int numbers[100]; // Array to store the input numbers
    int size = 0;
    int largest, second_largest;

    // Input loop
    while (1) {
        int number;
        cout << "Enter a number (0 to stop): ";
        cin >> number;

        if (number == 0) {
            break;
        }
        // Store the number in the array
        numbers[size++] = number;
    }

    // Call the function to find the largest and second-largest numbers
    findLargestAndSecondLargest(numbers, size, largest, second_largest);

    // Output the results
    if (size == 0) {
        cout << "No numbers were entered." << endl;
    } else {
        cout << "The largest number is: " << largest << endl;
        if (size == 1) {
            cout << "There is no second largest number." << endl;
        } else {
            cout << "The second largest number is: " << second_largest << endl;
        }
    }
    return 0;
}

#include <iostream>
#include "Header.h"
#include <limits>
#include <stdexcept>

using namespace std;

// used chat gpt
// prompt: "can you make code that (copied Q1 and Q2 for prompt)"
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    string filename = "A1input.txt";  // The input file

    // Read data from file into the array
    readFromFile(arr, size, filename);

    // Display the current array contents
    cout << "Array contents after reading from file: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1. Check if a number exists
    int numToFind;
    cout << "Chose number to find\n";
    cin >> numToFind;
    int index = findElement(arr, size, numToFind);
    if (index != -1) {
        cout << "Found " << numToFind << " at index " << index << endl;
    }
    else {
        cout << numToFind << " not found in the array." << endl;
    }

    // 2. Modify an element
    int modifyIndex, newValue;
    try {
        cout << "Enter index to modify: ";
        cin >> modifyIndex;

        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a valid integer for the index.");
        }

        cout << "Enter new value: ";
        cin >> newValue;

        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a valid integer for the new value.");
        }

        modifyElement(arr, size, modifyIndex, newValue);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // 3. Removing a element
    cout << "Choose an index to remove integer from array\n";
    cin >> index;
    removeElement(arr, size, index);

    // 4. Add a new element
    int newElement;
    try {
        cout << "Enter new element to add to the array: ";
        cin >> newElement;

        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a valid integer.");
        }

        addElement(arr, size, newElement);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // Display the final array contents
    cout << "Final array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

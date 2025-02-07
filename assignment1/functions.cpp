#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Header.h"

using namespace std;

// Function to check if a certain integer exists in the array
int findElement(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to modify the value of an integer at a given index
void modifyElement(int arr[], int size, int index, int newValue) {
    try {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds!");
        }

        int oldValue = arr[index];
        arr[index] = newValue;
        cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
}

// Function to add a new integer to the end of the array
void addElement(int arr[], int& size, int newValue) {
    try {
        if (size >= MAX_SIZE) {
            throw overflow_error("Array is full. Cannot add more elements.");
        }

        arr[size] = newValue;
        size++;
        cout << "Element " << newValue << " added to the end of the array." << endl;
    }
    catch (const overflow_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
}

// Function to remove an element at a given index
void removeElement(int arr[], int& size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];  // Shift elements left
        }
        size--; // Decrease the array size
        cout << "Element at index " << index << " removed." << endl;
    }
    else {
        cout << "Index out of bounds!" << endl;
    }
}

// Function to read integers from a file into the array
void readFromFile(int arr[], int& size, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    int num;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        while (ss >> num) {
            if (size < MAX_SIZE) {
                arr[size] = num;
                size++;
            }
            else {
                cout << "Array is full. Cannot read more data from file." << endl;
                break;
            }
        }
    }

    inputFile.close();
}

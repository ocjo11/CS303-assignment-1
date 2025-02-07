#pragma once
using namespace std;
const int MAX_SIZE = 100; // Maximum size of the array
// input: array, size of array, and the number its looking for
// output: returns the index or exits if not found
int findElement(int arr[], int size, int num);

// input: array, size of array, index, and value that it will replace it with
// output: no return only modification to array
void modifyElement(int arr[], int size, int index, int newValue);

// input: array, size of array, and the number it will add
// output: no return only modification to array
void addElement(int arr[], int& size, int newValue);

// input: array, size of array, and index to remove
// output: no return only modification to array
void removeElement(int arr[], int& size, int index);

// input: array, size of array, and the name of the file
// output: no return only creation of array
void readFromFile(int arr[], int& size, const string& filename);
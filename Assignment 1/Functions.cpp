#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

/*searches the array with a given value, and returns the index, else it returns -1 if the value is not found in the array*/
int indexCheck(int value, int currSize, int arr[]) {
    for (int i = 0; i < currSize; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;

}

/*Initalizes oldVal to represent the value of the array given by the index before changing it to the given value. It then prints both to the user.
Exception was added to satisfy Q2 to check if index is out of range*/
void indexModify(int index, int value, int& currSize, int arr[]) {
    try {
        if (index < 0 || index >= currSize) {
            throw out_of_range("Index given is not a valid index for the array");
        }
        int oldVal = arr[index];
        arr[index] = value;
        cout << "The value " << oldVal << " has been replaced with " << value << " at index " << index << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Error: An unknown error has occurred" << endl;
    }
}
/* Adds a value to the end of the array
Exception was added to satisfy Q2 to check if index is out of range*/
void addValue(int value, int& currSize, int arr[]) {
    try {
        // Check if the array has reached max size
        if (currSize >= 200) {
            throw out_of_range("Array is full, cannot add more values");
        }
        
        arr[currSize] = value;
    }
    catch (const out_of_range& e) {
        // Handles exception
        cout << "Error: " << e.what() << endl;
    }
}
/* Sets the value of a given index of the array to zero*/

void removeValue(int index, int arr[]) {
    arr[index] = 0;
}
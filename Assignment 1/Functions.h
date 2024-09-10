#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

// Checks if a value exists in the array
int indexCheck(int value, int currSize, int arr[]);

// Modifies the value at a specified index
void indexModify(int index, int value, int& currSize, int arr[]);

// Adds a new value to the array
void addValue(int value, int& currSize, int arr[]);

// Removes a value at a specified index
void removeValue(int value, int arr[]);
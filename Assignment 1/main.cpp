#include <iostream>
#include <string>
#include <fstream> 
#include "Functions.h"
using namespace std;


int main() {
    ifstream inFile;
    inFile.open("A1input.txt");
    int inVal;
    int index;
    int indexNumber = 0;
    const int arrSize = 200; //max array size
    int currSize = 100; //current number of elements
    int intArr[arrSize] = {0}; //array with 200 elements
    char userInput = 'z'; //intiialize user input variable
    //read integers from file into array
    while (inFile >> inVal) {
        intArr[indexNumber] = inVal;
        indexNumber++;
    }
    inFile.close();
    //prints a menu to the user and allows the program to be reran until the user enters 'q' to quit
    while (userInput != 'q') {
        cout << "\nMenu: " << endl;
        cout << "a. Check if integer exists in Array" << endl;
        cout << "b. Modify value of integer at specific index" << endl;
        cout << "c. Add value to end of Array" << endl;
        cout << "d. Remove value at specific index" << endl;
        cout << "e. Print Array" << endl;
        cout << "q. Quit" << endl;
        cout << "Please enter a command: ";

        cin >> userInput;
        //Check if integer exists in array
        if (userInput == 'a') {
            cout << "\nPlease enter an integer to check if it exists in the array: ";
            cin >> inVal;
            int index = indexCheck(inVal, currSize, intArr);
            if (index == -1) {
                cout << "The integer " << inVal << " does not exist in the array." << endl;
            }
            else {
                cout << "The integer " << inVal << " exists in the array at index " << index << endl;
            }

        }
        //Modify value of integer at specific index
        else if (userInput == 'b') {
            cout << "Please enter an integer to use for modification: ";
            cin >> inVal;
            cout << "Please enter the index of the array to modify: ";
            cin >> index;
            indexModify(index, inVal, currSize, intArr);
        }
        //Add a new integer to end of the array, increments currSize to match number of elements
        else if (userInput == 'c') {
            cout << "Please enter an integer to add to the end of array: ";
            cin >> inVal;
            addValue(inVal, currSize, intArr);
            currSize++;
        }
        //Remove integer at specific index
        else if (userInput == 'd') {
            cout << "Please enter the index of the array to remove: ";
            cin >> index;
            removeValue(index, intArr);
        }
        //Print current elements in the array
        else if (userInput == 'e') {
            for (int i = 0; i < currSize; i++) {
                cout << "Index " << i << ": " << intArr[i] << endl;
            }

        }
        //Quit program
        else if (userInput == 'q') {
            cout << "Quitting program!" << endl;
            break;
        }
        //Handle invalid inputs
        else {
            cout << "Invalid input, please try again!" << endl;
        }
    }

    return 0;
}
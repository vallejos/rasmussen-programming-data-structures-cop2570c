/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: November 4, 2017
 * File: main.cpp
 * Purpose: QuickSort.
 *          Module 05 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

// program name
const string APP_NAME = "Quick Sort Algorithm";

// define main menu options
const array<string, 3> MENU_OPTIONS = {
    "Simulate with Random data",
    "Enter data",
    "Exit program"
};

/**
 * Print main menu options
 */
void printMenuOptions() {
    cout << endl << "---------------------------" << endl;
    cout << APP_NAME << endl;
    cout << "---------------------------" << endl;

    for (int i=0; i<MENU_OPTIONS.size(); i++) {
        cout << i+1 << ". " << MENU_OPTIONS[i] << endl;
    }

    cout << endl << "Select an option: ";
}

int getRandomInt(int min, int max) {
    return min + (static_cast<int>(rand() % (max - min + 1)));
}

bool inArray(int value, int* arr, int size) {
    bool found = false;

    for (int i=0; i<size; i++) {
        if (arr[i] == value) {
            found = true;
        }
    } // for
    
    return found;
}

/**
 * Generate random arrays
 * @param size
 * @param arr0
 * @param arr1
 * @param arr2
 * @param arr3
 */
void generateRandomArrays(int size, int* arr0, int* arr1, int* arr2, int* arr3) {
    int value;
    bool ok = false;
    
    // complete the array
    for (int i=0; i<size; i++) {
        
        // make sure the random numbers are not already in the array
        while (!ok) {
            // get a random value to insert
            value = getRandomInt(1, size*10);

            if (!inArray(value, arr0, size)) {
                // value is not in the array -> insert it
                arr0[i] = value;
                arr1[i] = value;
                arr2[i] = value;
                arr3[i] = value;
                ok = true;

            }

        } // while

        ok = false;

    } // for
}

/**
 * Just print out the whole array
 * @param data
 * @param size
 */
void print(int* data, int size) {
    for (int i=0; i<size; i++) {
        cout << data[i] << " ";

    }
}

/**
 * Returns a pivot based on the approach given.
 * @param first
 * @param last
 * @param approach
 * @return 
 */
int getPivot(int first, int last, int approach) {
    int pivot;

    switch (approach) {
        case 2:
            // pivot near start
            pivot = first;
            break;

        case 3:
            // pivot near end
            pivot = last;
            break;

        case 1:
        default:
            // pivot in the middle
            pivot = (first + last) / 2;

    }

    return pivot;
}

/**
 * Swaps 2 elements in an array.
 * @param data
 * @param i
 * @param j
 */
void swap(int* data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

/**
 * Sorts the array using quick sort algorithm.
 * Choose a pivot based on the approach given.
 * Returns the number of swap operations done.
 * @param data
 * @param first
 * @param last
 * @param approach
 * @return
 */
int quickSort(int* data, int first, int last, int approach) {
    int ops = 0;
    int i = first;
    int j = last;
    
    // get pivot
    int pivot = getPivot(i, j, approach);

    while (i <= j) {

        while (data[i] < data[pivot]) {
            i++;
        }

        while (data[j] > data[pivot]) {
            j--;
        }

        if (i <= j) {
            ops++;
            swap(data, i, j);
            i++;
            j--;
        }
    }

    if (j > first) {
        // Sort the left half. 
        ops += quickSort(data, first, j, approach);
    }

    if (i < last) {
        // Sort the right half. 
        ops += quickSort(data, i, last, approach);
    }
    
    return ops;
}

/**
 * Generate random arrays of the given size and sort them
 * @param size
 */
void simulate(int size, bool display) {
    // declare some used variables
    int* data0 = new int[size];
    int* data1 = new int[size];
    int* data2 = new int[size];
    int* data3 = new int[size];
    int ops1, ops2, ops3;

    // generate arrays (each array should be the same at this point)
    generateRandomArrays(size, data0, data1, data2, data3);

    // sort the arrays and get the number of operations
    ops1 = quickSort(data1, 0, size-1, 1);
    ops2 = quickSort(data2, 0, size-1, 2);    
    ops3 = quickSort(data3, 0, size-1, 3);
    
    if (display) {
        // print original array
        cout << "Unsorted Array: ";
        print(data0, size);
    }

    // show results for first approach
    cout << endl << endl << "> QuickSort #1: pivot is at the median" << endl;
    cout << "Swaps done: " << ops1 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data1, size);
    }
    
    // show results for second approach
    cout << endl << endl << "> QuickSort #2: pivot is at the start" << endl;    
    cout << "Swaps done: " << ops2 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data2, size);
    }

    // show results for third approach
    cout << endl << endl << "> QuickSort #3: pivot is at the end" << endl;    
    cout << "Swaps done: " << ops3 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data3, size);
    }
    
}

/**
 * Run sorting algorithm with data entered by the user
 * @param size
 */
void enterArray(int size, bool display) {
    // declare some variables
    int* data0 = new int[size];
    int* data1 = new int[size];
    int* data2 = new int[size];
    int* data3 = new int[size];
    int ops1, ops2, ops3;
    int value;
    
    // enter the data
    for (int i=0; i<size; i++) {
        cout << "Enter value " << i+1 << " of " << size << ": ";
        cin >> value;
        
        data0[i] = value;
        data1[i] = value;
        data2[i] = value;
        data3[i] = value;
        
    }

    // sort the arrays and get the number of operations
    ops1 = quickSort(data1, 0, size-1, 1);
    ops2 = quickSort(data2, 0, size-1, 2);    
    ops3 = quickSort(data3, 0, size-1, 3);

    if (display) {
        // print original array
        cout << "Unsorted Array: ";
        print(data0, size);
    }
    
    // show results for first approach
    cout << endl << endl << "> QuickSort #1: pivot is at the median" << endl;
    cout << "Swaps done: " << ops1 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data1, size);
    }
    
    // show results for second approach
    cout << endl << endl << "> QuickSort #2: pivot is at the start" << endl;    
    cout << "Swaps done: " << ops2 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data2, size);
    }

    // show results for third approach
    cout << endl << endl << "> QuickSort #3: pivot is at the end" << endl;    
    cout << "Swaps done: " << ops3 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data3, size);
    }
    
}

/**
 * main function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    int choice;
    char option;
    
    int num;
    bool end = false;
    bool display = false;
    
    while (!end) {
        printMenuOptions();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << endl << "Enter size of array (elements will be integers randomly generated): ";
                cin >> num;

                if (num > 0) {
                    cout << "Values will be randomly generated from 1 to " << num*10 << endl;
                    cout << "Do you want to display the sorted arrays? <y/N>: ";
                    cin >> option;
                    display = (option == 'y') ? true : false;
                    
                    simulate(num, display);
                } else {
                    cout << endl << "Incorrect size." << endl;
                }
                
                break;

            case 2:
                cout << endl << "Enter size of array (you will enter the numbers): ";
                cin >> num;

                if (num > 0) {
                    cout << "Do you want to display the sorted arrays? <y/N>: ";
                    cin >> option;
                    display = (option == 'y') ? true : false;

                    enterArray(num, display);
                } else {
                    cout << endl << "Incorrect size." << endl;
                }

                break;

            case 3:
                end = true;
                break;

            default:
                cout << endl << "Incorrect option. Try again." << endl;
        }
    }
    
    return 0;
}

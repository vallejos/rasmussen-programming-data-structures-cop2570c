/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: November 7, 2017
 * File: main.cpp
 * Purpose: Sorting Arrays using Merge Sort, Quick Sort, Bubble Sort, and Insertion Sort.
 *          Module 06 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Returns random integer between min and max
 * @param min
 * @param max
 * @return 
 */
int getRandomInt(int min, int max) {
    return min + (static_cast<int>(rand() % (max - min + 1)));
}

/**
 * Returns whether an integer is in the array or not
 * @param value
 * @param arr
 * @param size
 * @return 
 */
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
 * @param arr4
 */
void generateRandomArrays(int size, int* arr0, int* arr1, int* arr2, int* arr3, int* arr4) {
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
                arr4[i] = value;
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
 * Merge 2 sub arrays
 * @param arr
 * @param l
 * @param m
 * @param r
 */
int merge(int* data, int first, int med, int last) {
    int ops = 0;
    int i, j, k;
    int n1 = med - first + 1;
    int n2 =  last - med;
 
    // create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = data[first + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = data[med + 1+ j];
    }
 
    // Merge the temp arrays back into data
    i = 0; // Initial index of first sub array
    j = 0; // Initial index of second sub array
    k = first; // Initial index of merged sub array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        
        ops++;
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
        ops++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
        ops++;
    }

    return ops;
}

/**
 * Merge Sort
 * @param data
 * @param first
 * @param last
 * @return 
 */
int mergeSort(int* data, int first, int last) {
    int ops = 0;

    if (first < last) {
        int m = first + (last - first) / 2;

        // Sort first and second halves
        ops += mergeSort(data, first, m);
        ops += mergeSort(data, m+1, last);

        ops += merge(data, first, m, last);
    }
    
    return ops;
}

/**
 * Bubble Sort
 * @param data
 * @param first
 * @param last
 * @return 
 */
int bubbleSort(int* data, int first, int last) {
    int ops = 0;
    int i = first, j = last;
    
    for (i = 0; i <= last; i++) {
        // Last i elements are already in place   
        for (j = 0; j < last - i; j++) {
            if (data[j] > data[j+1]) {
                ops++;
                swap(data, j, j+1);
            }
        }
    }
    
    return ops;
}

/**
 * Insertion Sort
 * @param data
 * @param first
 * @param last
 * @return 
 */
int insertionSort(int* data, int first, int last) {
    int ops = 0;
    int i, key, j;

    for (i = 1; i <= last; i++) {
        key = data[i];
        j = i-1;

        // Move elements that are greater than key, to one position ahead 
        // of their current position
        while (j >= 0 && data[j] > key) {
            ops++;
            data[j+1] = data[j];
            j = j-1;
        }
        data[j+1] = key;
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
    int* data4 = new int[size];
    int ops1, ops2, ops3, ops4;

    // generate arrays (each array should be the same at this point)
    generateRandomArrays(size, data0, data1, data2, data3, data4);

    // sort the arrays and get the number of operations
    ops1 = quickSort(data1, 0, size-1, 1);
    ops2 = mergeSort(data2, 0, size-1);
    ops3 = bubbleSort(data3, 0, size-1);
    ops4 = insertionSort(data4, 0, size-1);
    
    if (display) {
        // print original array
        cout << "Unsorted Array: ";
        print(data0, size);
    }

    // show results for quick sort
    cout << endl << endl << "> QuickSort" << endl;
    cout << "Swaps done: " << ops1 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data1, size);
    }

    // show results for merge sort
    cout << endl << endl << "> MergeSort" << endl;
    cout << "Swaps done: " << ops2 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data2, size);
    }
    
    // show results for bubble sort
    cout << endl << endl << "> BubbleSort" << endl;
    cout << "Swaps done: " << ops3 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data3, size);
    }

    // show results for insertion sort
    cout << endl << endl << "> InsertionSort" << endl;
    cout << "Swaps done: " << ops4 << endl;
    if (display) {
        cout << "Sorted Array: ";
        print(data4, size);
    }
    
}

/**
 * main function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    int arraySize = 10000;
    
    // start
    simulate(arraySize, false);
    
    return 0;
}


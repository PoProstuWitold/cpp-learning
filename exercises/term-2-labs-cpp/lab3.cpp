#include <iostream>

using namespace std;


// helpers
void printArray(int arr[], int n);

int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

int main() {
    cout << "Podstawy algorytmiki - laboratorium 3" << endl;

    // Get the size of the array from user input
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Get the range of random numbers from user input
    int a, b;
    cout << "Enter the range of random numbers (separated by space): ";
    cin >> a >> b;
            
    // Allocate memory for the array dynamically
    int* arr = new int[size];

    // Fill the array with random numbers in range [a,b]
    srand(time(0)); // seed random number generator with current time
    for (int i = 0; i < size; i++) {
        arr[i] = a + rand() % (b - a + 1); // generate random number in range [a,b]
    }

    cout << "Bubble sort" << endl;
    // cout << "The array before sorting is: ";
    // printArray(arr, size);
    cout << "Sorting started" << endl;
    quickSort(arr, 0, size-1);
    cout << "Sorting finished" << endl;
    // cout << "The array after sorting is: ";
    // printArray(arr, size);


    // Free memory allocated for the array 
    delete[] arr;


    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}


// Quicksort
// Quicksort is a divide and conquer algorithm. Quicksort first 
// divides a large array into two smaller sub-arrays: 
// the low elements and the high elements. 
// Quicksort can then recursively sort the sub-arrays

// The steps are:

// 1. Pick an element, called a pivot, from the array.
// 2. Partitioning: reorder the array so that all elements with values 
// less than the pivot come before the pivot, while all elements with values 
// greater than the pivot come after it (equal values can go either way). 
// After this partitioning, the pivot is in its final position. 
// This is called the partition operation.
// 3. Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.

// Complexity
// Name	        Best        Average     Worst	Memory	    Stable	Comments
// Quicksort	nlog(n)	    nlog(n)	    n^2	    log(n)	    No      Quicksort is usually done in-place with O(log(n)) stack space	

void quickSort(int arr[], int start, int end) {

    // base case
    if (start >= end) return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
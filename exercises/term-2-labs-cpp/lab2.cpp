#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// helpers
void printArray(int arr[], int n);
void commonArrayTask();

// sorting algorithms
void bubbleSort(int * arr, int n, int mode);
void bubbleSort2D(int** arr, int rows, int columns, int mode, int columnNumber);
void selectionSort(int * arr, int n, int mode);
void insertionSort(int * arr, int n, int mode);


int main() {
    cout << "Podstawy algorytmiki - laboratorium 2" << endl;
    commonArrayTask();
    return 0;
}



// HELPERS

// Swap 2 elements
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Common task needed for all sortings
void commonArrayTask() {
    // Get the size of the array from user input
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Get the range of random numbers from user input
    int a, b;
    cout << "Enter the range of random numbers (separated by space): ";
    cin >> a >> b;

    // Get the mode of sorting from user input
    bool mode;
    cout << "Enter the mode of sorting (0 for descending, 1 ascending): ";
    cin >> mode;

    // Allocate memory for the array dynamically
    int* arr = new int[size];

    // Fill the array with random numbers in range [a,b]
    srand(time(0)); // seed random number generator with current time
    for (int i = 0; i < size; i++) {
        arr[i] = a + rand() % (b - a + 1); // generate random number in range [a,b]
    }

    // Print the array before sorting
    cout << "The array before sorting is: ";
    printArray(arr, size);

    // // Sort the array using bubble sort algorithm
    bubbleSort(arr, size, mode);

    // Print the array after sorting
    cout << "The array after sorting is: ";
    printArray(arr, size);

    // Free memory allocated for the array 
    delete[] arr;
}


// Bubble Sort
// Bubble sort, sometimes referred to as sinking sort, 
// is a simple sorting algorithm that repeatedly steps through the list to be sorted, 
// compares each pair of adjacent items and swaps them if they are in the wrong order 
// (ascending or descending arrangement). The pass through the list is repeated until no swaps are needed, 
// which indicates that the list is sorted.

// Complexity
// Name	        Best    Average     Worst	Memory	Stable	Comments
// Bubble sort	n^2	    n^2	        n^2	    1	    Yes	

// mode: 0 - descending, 1 - ascending
void bubbleSort(int * arr, int n, int mode = 0) {
    cout << "Bubble sort" << endl;
    bool changed;

    n -= 1;

    for (int i = 0; i < n; i++) { 

        changed = false; 

        for (int j = 0; j < n - i; j++) { 

            if (arr[j] > arr[j + 1]) {
 
                swap(arr[j], arr[j+1]);            
                changed = true; 
            } 
        } 

        if (changed == false)
            return;
    } 
}

void bubbleSort2D(int** arr, int rows, int columns, int mode, int columnNumber) {

}




// Selection Sort
// Selection sort is a sorting algorithm, specifically an in-place comparison sort. 
// It has O(n2) time complexity, making it inefficient on large lists, 
// and generally performs worse than the similar insertion sort. 
// Selection sort is noted for its simplicity, and it has performance advantages 
// over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.

// Complexity
// Name	            Best    Average     Worst	Memory	Stable	Comments
// Selection sort	n^2	    n^2	        n^2	    1	    Yes	

void selectionSort(int * arr, int n, int mode) {

}




// Insertion Sort
// Insertion sort is a simple sorting algorithm that builds the final sorted array 
// (or list) one item at a time. It is much less efficient on large lists 
// than more advanced algorithms such as quicksort, heapsort, or merge sort.

// Complexity
// Name	        Best    Average     Worst	Memory	Stable	Comments
// Bubble sort	n	    n^2	        n^2	    1	    Yes	

void insertionSort(int * arr, int n, int mode) {

}

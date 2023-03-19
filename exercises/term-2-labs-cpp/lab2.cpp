#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// helpers
void printArray(int arr[], int n);
void print2DArray(int* arr2D[], int r, int c);

// sorting algorithms
void bubbleSort(int * arr, int n, int mode);
void bubbleSort2D(int** arr, int rows, int columns, int mode, int columnNumber);
void selectionSort(int * arr, int n, int mode);
void insertionSort(int * arr, int n, int mode);


int main() {
    cout << "Podstawy algorytmiki - laboratorium 2" << endl;

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
    cout << "Enter the mode of sorting (0 - ascending, 1 - descending): ";
    cin >> mode;

    // Get the dimensions of the array from user input
    int rows, cols;
    cout << "Enter the number of rows and columns of the array: ";
    cin >> rows >> cols;

    // Allocate memory for the 2D array dynamically
    int** arr2D = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr2D[i] = new int[cols];
    }

    // Fill the 2D array with random numbers in range [a,b]
    srand(time(0)); // seed random number generator with current time
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2D[i][j] = a + rand() % (b - a + 1); // generate random number in range [a,b]
        }
    }
            
    // Allocate memory for the array dynamically
    int* arr = new int[size];

    // Fill the array with random numbers in range [a,b]
    srand(time(0)); // seed random number generator with current time
    for (int i = 0; i < size; i++) {
        arr[i] = a + rand() % (b - a + 1); // generate random number in range [a,b]
    }

    // Sort the array using bubble sort algorithm
    int algorithm;
    cout << "Enter the sorting algorithm from the following:" << endl;
    cout << "1. bubbleSort:" << endl;
    cout << "2. bubbleSort2D:" << endl;
    cout << "3. selectionSort:" << endl;
    cout << "4. insertionSort:" << endl;
    cin >> algorithm;

    switch(algorithm) {
        case 1:
            cout << "Bubble sort" << endl;
            cout << "The array before sorting is: ";
            printArray(arr, size);

            bubbleSort(arr, size, mode);

            cout << "The array after sorting is: ";
            printArray(arr, size);
            break;
        case 2:
            cout << "Bubble sort 2D" << endl;

            cout << "The 2D array before sorting is: " << endl;
            print2DArray(arr2D, rows, cols);

            bubbleSort2D(arr2D, rows, cols, mode, 2);

            cout << "The 2D array after sorting is: " << endl;
            print2DArray(arr2D, rows, cols);
            break;
        case 3:
            cout << "Selection sort" << endl;
            cout << "The array before sorting is: ";
            printArray(arr, size);

            selectionSort(arr, size, mode);
            
            cout << "The array after sorting is: ";
            printArray(arr, size);
            break;
        case 4:
            cout << "Insertion sort" << endl;
            cout << "The array before sorting is: ";
            printArray(arr, size);

            insertionSort(arr, size, mode);

            cout << "The array after sorting is: ";
            printArray(arr, size);
            break;
        default:
            cout << "Invalid algorithm choice." << endl;
            break;
    }

    // Free memory allocated for the array 
    delete[] arr;


    return 0;
}



// HELPERS
// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DArray(int* arr2D[], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }
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
void bubbleSort(int * arr, int n, int mode) {
    bool changed;
    n -= 1;

    for (int i = 0; i < n; i++) { 
        changed = false; 

        for (int j = 0; j < n - i; j++) { 
            // mode: 0 - Ascending Order, 1 - Descending Order
            if((mode == 0 && arr[j] > arr[j + 1]) || (mode == 1 && arr[j] < arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                changed = true;
            }
        } 

        if (changed == false)
            return;
    } 
}

void bubbleSort2D(int** arr, int rows, int columns, int mode, int columnNumber) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns - i - 1; j++) {

            bool shouldSwap = false;

            if(mode == 0) { // Ascending Order
                if(arr[j][columnNumber] > arr[j+1][columnNumber])
                    shouldSwap = true;
            } else { // Descending Order
                if(arr[j][columnNumber] < arr[j+1][columnNumber])
                    shouldSwap = true;
            }
            
            if(shouldSwap) {
                int* temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;

        for(int j = i+1; j < n; j++) {
            // mode: 0 - Ascending Order, 1 - Descending Order
            if((mode == 0 && arr[j] < arr[minIndex]) || (mode == 1 && arr[j] > arr[minIndex]))
                minIndex = j;
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}




// Insertion Sort
// Insertion sort is a simple sorting algorithm that builds the final sorted array 
// (or list) one item at a time. It is much less efficient on large lists 
// than more advanced algorithms such as quicksort, heapsort, or merge sort.

// Complexity
// Name	        Best    Average     Worst	Memory	Stable	Comments
// Bubble sort	n	    n^2	        n^2	    1	    Yes	

void insertionSort(int * arr, int n, int mode) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;

        // mode: 0 - Ascending Order, 1 - Descending Order
        while(j >= 0 && ((mode == 0 && arr[j] > key) || (mode == 1 && arr[j] < key))) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

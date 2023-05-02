#include <iostream>

using namespace std;

int linearSearch(int x[], int n, int wartosc);
int bisectionSearch(int x[], int n, int wartosc);

int main() {
    cout << "Laboratorium 07" << endl;

    int x[] = {1, 3, 5, 7, 9};
    int n = sizeof(x) / sizeof(x[0]);
    
    int wartosc;

    // Call linear search
    wartosc = 5;
    int linearIndex = linearSearch(x, n, wartosc);
    if (linearIndex != -1) {
        cout << "Found " << wartosc << " at index " << linearIndex << " using linear search" << endl;
    } else {
        cout << wartosc << " not found using linear search" << endl;
    }
    
    // Call binary search
    wartosc = 3;
    int binaryIndex = bisectionSearch(x, n, wartosc);
    if (binaryIndex != -1) {
        cout << "Found " << wartosc << " at index " << binaryIndex << " using binary search" << endl;
    } else {
        cout << wartosc << " not found using binary search" << endl;
    }

    return 0;
}

int linearSearch(int x[], int n, int wartosc) {
    for(int i = 0; i < n; i++) {
        if(x[i] == wartosc) {
            return x[i];
        }
    }

    return -1;
}

int bisectionSearch(int x[], int n, int wartosc) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (x[mid] == wartosc) {
            return mid;
        }
        else if (x[mid] < wartosc) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}
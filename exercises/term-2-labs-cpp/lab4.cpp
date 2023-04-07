#include <iostream>
#include <cassert>

using std::swap;

// x - tablica
// n - dlugosc tablicy
// granica (1, 2) - najwiekszy element do petli

// flaga polska
int podzial2czesci(int x[], int n, int granica);
int sort01(int n, int a[]);

// flaga francuska
void podzial3czesci(int x[], int n, int granica1, int granica2, int* i, int* k);
void sort012 (int n, int A[], int * p1, int * p2, int * p3);

int main() {
    // Test funkcji podzial2czesci
    int x1[] = {2, 5, 1, 7, 3, 8, 4, 6};
    int n1 = 8;
    int granica1 = 5;
    int result1 = podzial2czesci(x1, n1, granica1);
    assert(result1 == 4);
    for (int i = 0; i < n1; i++) {
        if (i < result1) {
            assert(x1[i] < granica1);
        } else {
            assert(x1[i] >= granica1);
        }
    }

    // Test funkcji sort01
    int a1[] = {0, 0, 0, 0, 1, 1};
    int n2 = 6;
    int result2 = sort01(n2, a1);
    assert(result2 == 4);

    // Test funkcji podzial3czesci
    int x2[] = {2, 5, 1, 7, 3, 8, 4, 6};
    int n3 = 8;
    int granica3_1 = 3;
    int granica3_2 = 6;
    int i3, k3;
    podzial3czesci(x2, n3, granica3_1, granica3_2, &i3, &k3);
    for (int j = 0; j < n3; j++) {
        if (j <= i3) {
            assert(x2[j] <= granica3_1);
        } else if (j < k3) {
            assert(x2[j] > granica3_1 && x2[j] <= granica3_2);
        } else {
            assert(x2[j] > granica3_2);
        }
    }

    // Test funkcji sort012
    int A[] = {0, 1, 2, 1, 0, 2, 1};
    int n4 = 7;
    int num_zeros, num_ones, num_twos;
    sort012(n4, A, &num_zeros, &num_ones, &num_twos);
    assert(num_zeros == 2);
    assert(num_ones == 3);
    assert(num_twos == 2);
    for (int i = 0; i < n4; i++) {
        if (i < num_zeros) {
            assert(A[i] == 0);
        } else if (i < num_zeros + num_ones) {
            assert(A[i] == 1);
        } else {
            assert(A[i] == 2);
        }
    }

    std::cout << "All tests pass" << std::endl;
}


int podzial2czesci(int x[], int n, int granica) {
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        while (x[i] < granica) {
            i++;
        }
        while (x[j] >= granica) {
            j--;
        }
        if (i <= j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }

    return i;
}

int sort01(int n, int a[]) {
    int left = 1, right = n, temp;
    while(left < right) {
        while(left < right && a[left] == 0) left++;
        while(left < right && a[right] == 1) right--;
        if(left < right) {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }
    if (a[right] == 0) return right;
    else return right - 1;
}
// Wynikiem funkcji jest indeks 
// ostatniego 0!
// Gdy wynik = 0, wtedy brak „0”.
// Gdy wynik = n , wtedy brak „1”.

// flaga francuska (w angielskiej literaturze "Dutch Flag")

void podzial3czesci(int x[], int n, int granica1, int granica2, int* i, int* k) {
    *i = -1;
    int j = 0;
    *k = n;

    while(j < *k) {
        if(x[j] <= granica1) {
            (*i)++;
            swap(x[*i], x[j]);
            j++;
        } else {
            if(x[j] > granica2) {
                (*k)--;
                swap(x[*k], x[j]);
            } else {
                j++;
            }
        }
    }
}

void sort012(int n, int A[], int* num_zeros, int* num_ones, int* num_twos) {
    int zero_count = 0, one_count = 0, two_count = n - 1, temp;
    while (one_count <= two_count) {
        if (A[one_count] == 0) {
            temp = A[zero_count];
            A[zero_count] = A[one_count];
            A[one_count] = temp;
            zero_count++;
            one_count++;
        } else if (A[one_count] == 1) {
            one_count++;
        } else {
            temp = A[one_count];
            A[one_count] = A[two_count];
            A[two_count] = temp;
            two_count--;
        }
    }

    *num_zeros = zero_count;
    *num_ones = one_count - zero_count;
    *num_twos = n - one_count;
}
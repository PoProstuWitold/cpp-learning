#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double number;
    cout << "Enter a number: ";
    cin >> number;

    double square_root = sqrt(number);
    cout << "The square root of " << number << " is " << square_root << endl;

    return 0;
}
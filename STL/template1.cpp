#include <bits/stdc++.h>
using namespace std;

// Template function to find an element in an array
template <class xyz>  // xyz is the custom data type name
int find(xyz* arr, xyz f, int sz) {
    for (int i = 0; i < sz; i++) {
        if (arr[i] == f)
            return i;
    }
    return -1;  // Return -1 if not found
}

int main() {
    // Example 1: Finding an integer
    int arr1[] = {10, 20, 30, 40, 50};
    int intTarget = 30;
    int intIndex = find(arr1, intTarget, 5);
    cout << "Index of " << intTarget << " in int array: " << intIndex << endl;

    // Example 2: Finding a double
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleTarget = 3.3;
    int doubleIndex = find(arr2, doubleTarget, 5);
    cout << "Index of " << doubleTarget << " in double array: " << doubleIndex
         << endl;

    // Example 3: Finding a character
    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    char charTarget = 'c';
    int charIndex = find(arr3, charTarget, 5);
    cout << "Index of '" << charTarget << "' in char array: " << charIndex
         << endl;

    // Example 4: Finding a string
    string arr4[] = {"apple", "banana", "cherry", "date", "elderberry"};
    string stringTarget = "cherry";
    int stringIndex = find(arr4, stringTarget, 5);
    cout << "Index of \"" << stringTarget
         << "\" in string array: " << stringIndex << endl;
    return 0;
}

// Author: tashobi_02 //

#include <bits/stdc++.h>
using namespace std;
/*
 tuple in C++ can store more than three values. In fact, there is no fixed limit
 to the number of elements a tuple can store, as long as memory constraints
 allow it.
*/
int main() {
    // Tuple with five values of different data types.
    tuple<int, string, double, char, bool> t = {42, "hello", 3.14, 'A', true};
    // Accessing and printing tuple elements.
    cout << "Integer: " << get<0>(t) << endl;
    cout << "String: " << get<1>(t) << endl;
    cout << "Double: " << get<2>(t) << endl;
    cout << "Char: " << get<3>(t) << endl;
    cout << "Bool: " << get<4>(t) << endl;
    // Modifying tuple elements.
    get<0>(t) = 100;
    get<1>(t) = "updated";
    get<4>(t) = false;
    // Printing updated tuple values.
    cout << "\nAfter modification:" << endl;
    cout << "Integer: " << get<0>(t) << endl;
    cout << "String: " << get<1>(t) << endl;
    cout << "Bool: " << get<4>(t) << endl;

    return 0;
}

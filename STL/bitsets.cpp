#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

/* The bitset in C++ STL is a container that stores a fixed-size sequence of
bits (binary digits), allowing you to manipulate bits individually or as a
group. It is useful for bitwise operations and is an efficient way to handle
binary data when the size is known at compile time. */

void soln() {
    // Create a bitset of size 8 (can hold 8 bits)
    bitset<8> b1;                    // Default is all 0s: 00000000
    bitset<8> b2(5);                 // Binary representation of 5: 00000101
    bitset<8> b3(string("101010"));  // From a string: 00101010

    cout << "b1: " << b1 << endl;  // Output: 00000000
    cout << "b2: " << b2 << endl;  // Output: 00000101
    cout << "b3: " << b3 << endl;  // Output: 00101010

    // Set, reset, and flip bits
    b1.set(1);    // Set bit at index 1 to 1
    b1.set(3);    // Set bit at index 3 to 1
    b2.reset(0);  // Reset bit at index 0 to 0
    b3.flip();    // Flip all bits

    cout << "After modification:" << endl;
    cout << "b1: " << b1 << endl;                  // Output: 00001010
    cout << "b2: " << b2 << endl;                  // Output: 00000100
    cout << "b3: " << b3 << endl;                  // Output: 11010101
                                                   // Access and query bits
    cout << "b1[3]: " << b1[3] << endl;            // Output: 1 (bit at index 3)
    cout << "b1.count(): " << b1.count() << endl;  // Output: 2 (number of 1s)
    cout << "b3.any(): " << b3.any()
         << endl;  // Output: 1 (true if any bit is 1)
    cout << "b3.none(): " << b3.none()
         << endl;  // Output: 0 (false if any bit is 1)

    // Convert to string or number
    cout << "b2 as unsigned long: " << b2.to_ulong() << endl;  // Output: 4
    cout << "b3 as string: " << b3.to_string() << endl;  // Output: 11010101
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
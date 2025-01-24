#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

/*
Some properties of bitwise operations:
a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b
Addition:
a+b = a|b + a&b
a+b = a⊕b + 2(a&b)
Subtraction:
a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))
*/

void soln() {
    lli a = 5, b = 3;

    // Properties of bitwise operations
    cout << "a | b = " << (a | b) << " = " << (a ^ b) + (a & b) << enl;
    cout << "a ^ (a & b) = " << (a ^ (a & b)) << " = " << ((a | b) ^ b) << enl;
    cout << "b ^ (a & b) = " << (b ^ (a & b)) << " = " << ((a | b) ^ a) << enl;
    cout << "(a & b) ^ (a | b) = " << ((a & b) ^ (a | b)) << " = " << (a ^ b)
         << enl;

    // Addition
    cout << "a + b = " << (a + b) << " = " << (a | b) + (a & b) << enl;
    cout << "a + b = " << (a + b) << " = " << (a ^ b) + 2 * (a & b) << enl;

    // Subtraction
    cout << "a - b = " << (a - b) << " = " << ((a ^ (a & b)) - ((a | b) ^ a))
         << enl;
    cout << "a - b = " << (a - b) << " = " << (((a | b) ^ b) - ((a | b) ^ a))
         << enl;
    cout << "a - b = " << (a - b) << " = " << ((a ^ (a & b)) - (b ^ (a & b)))
         << enl;
    cout << "a - b = " << (a - b) << " = " << (((a | b) ^ b) - (b ^ (a & b)))
         << enl;
}

int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
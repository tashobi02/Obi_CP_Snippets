#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
// better to use unsigned version for bitmasking operations
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    /* __builtin_popcount(x) is a function that
    counts the number of set bits (1s) in the binary representation of an
    integer x.
    */
    lli x;
    cin >> x;
    cout << __builtin_popcountll(x) << endl;
    cout << "Binary representation of x: " << bitset<64>(x) << endl;
    cout << "Binary representation of x (no leading zeros): "
         << bitset<64>(x).to_string().substr(
                bitset<64>(x).to_string().find('1'))
         << endl;
    // you need to add ll in the end for lli

    /* __builtin_ctz (count trailing zeros) is a
     function that counts the number of trailing zeros in the binary
     representation of an integer.
     */
    lli y;
    cin >> y;
    cout << __builtin_ctzll(y) << endl;
    cout << "Binary representation of y: " << bitset<64>(y) << endl;
    cout << "Binary representation of y (no leading zeros): "
         << bitset<64>(y).to_string().substr(
                bitset<64>(y).to_string().find('1'))
         << endl;
    // Compute the biggest power of 2 that is a divisor of x. Example: f(24) = 4
    lli z;
    cin >> z;
    cout << __builtin_ctzll(z) << endl;
    cout << "Binary representation of z: " << bitset<64>(z) << endl;
    cout << "Binary representation of z (no leading zeros): "
         << bitset<64>(z).to_string().substr(
                bitset<64>(z).to_string().find('1'))
         << endl;
    /*
    The __builtin_clz(x) is a function that counts
    the number of leading zeros in the binary representation of a number.
    */
    lli w;
    cin >> w;
    cout << __builtin_clzll(w) << endl;
    cout << "Binary representation of w: " << bitset<64>(w) << endl;
    cout << "Binary representation of w (no leading zeros): "
         << bitset<64>(w).to_string().substr(
                bitset<64>(w).to_string().find('1'))
         << endl;
    // Compute the smallest power of 2 that is not smaller than x. Example:
    // f(12) = 16
    lli q;
    cin >> q;
    cout << (1 << (64 - __builtin_clzll(q - 1))) << endl;
    cout << "Binary representation of q: " << bitset<64>(q) << endl;
    cout << "Binary representation of q (no leading zeros): "
         << bitset<64>(q).to_string().substr(
                bitset<64>(q).to_string().find('1'))
         << endl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
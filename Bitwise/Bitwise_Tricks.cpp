#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// check LSB to to see if x is odd or even
bool isEven(lli x) {
    if (x & 1)
        return false;  // odd
    else
        return true;  // even
}
// check if x is a power of 2
bool powerof2(lli x) {
    if ((x & (x - 1)) == 0)
        return true;
    else
        return false;
}
// check if the k-th bit is set
lli checkKthBit(lli x, lli k) { return x & (1 << k); }
// toggle the k-th bit
lli toggleKthBit(lli x, lli k) { return x ^ (1 << k); }
// set the k-th bit
lli setKthBit(lli x, lli k) { return x | (1 << k); }
// unset the k-th bit
lli unsetKthBit(lli x, lli k) { return x & ~(1 << k); }
// multiply x by 2^k
lli multiplyBy2powk(lli x, lli k) {
    return (x << k);  // left shift
}
// divide x by 2^k
lli divideBy2powk(lli x, lli k) {
    return (x >> k);  // right shift
}
// Number of bits to flip to convert x to y
lli bitFlip(lli x, lli y) { return __builtin_popcountll(x ^ y); }
// swap two numbers using XOR
void swap(lli &x, lli &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
// count the number of set bits
lli noOfSetBits(lli x) { return __builtin_popcountll(x); }
void soln() {
    lli x = 10, y = 20, k = 2;
    cout << "Is " << x << " even? " << isEven(x) << enl;
    cout << "Is " << x << " a power of 2? " << powerof2(x) << enl;
    cout << "Check " << k << "-th bit of " << x << ": " << checkKthBit(x, k)
         << enl;
    cout << "Toggle " << k << "-th bit of " << x << ": " << toggleKthBit(x, k)
         << enl;
    cout << "Set " << k << "-th bit of " << x << ": " << setKthBit(x, k) << enl;
    cout << "Unset " << k << "-th bit of " << x << ": " << unsetKthBit(x, k)
         << enl;
    cout << "Multiply " << x << " by 2^" << k << ": " << multiplyBy2powk(x, k)
         << enl;
    cout << "Divide " << x << " by 2^" << k << ": " << divideBy2powk(x, k)
         << enl;
    cout << "Number of set bits in " << x << ": " << noOfSetBits(x) << enl;
    cout << "Number of bits to flip to convert " << x << " to " << y << ": "
         << bitFlip(x, y) << enl;
    cout << "Before swap: x = " << x << ", y = " << y << enl;
    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
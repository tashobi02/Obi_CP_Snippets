#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void soln() {
    // Example of make_pair
    pair<lli, string> p1 = make_pair(1, "example");
    cout << "p1: (" << p1.first << ", " << p1.second << ")" << endl;

    // Example of swap
    // Here we are swapping the values of two pairs
    pair<lli, string> p2 = make_pair(2, "sample");
    cout << "p2 before swap: (" << p2.first << ", " << p2.second << ")" << endl;
    p1.swap(p2);
    cout << "p1 after swap: (" << p1.first << ", " << p1.second << ")" << endl;
    cout << "p2 after swap: (" << p2.first << ", " << p2.second << ")" << endl;

    // Example of tie
    // Here we are using tie to unpack the values of the pair
    lli a;
    string b;
    tie(a, b) = p1;
    cout << "Values from tie: a = " << a << ", b = " << b << endl;
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
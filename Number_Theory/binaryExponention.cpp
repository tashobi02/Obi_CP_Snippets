#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
lli MOD = 1e9 + 7;
// Compute x^n & m. This is a very common operation. For instance it is used in
// computing the modular multiplicative inverse.
lli binPow(lli a, lli b, lli m) {
    a %= m;
    lli res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void soln() {
    lli x, n, m;
    cin >> x >> n >> m;
    cout << binPow(x, n, m) << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
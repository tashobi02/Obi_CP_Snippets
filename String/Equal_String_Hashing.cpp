#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli p = 137, mod = 1e9 + 7;
const lli N = 2e6 + 10;
lli pw[N];
void preCalculate() {
    pw[0] = 1;
    for (lli i = 1; i < N; i++) {
        pw[i] = 1LL * pw[i - 1] * p % mod;
    }
}
lli getHash(string s) {
    lli n = s.size();
    lli hs = 0;
    for (lli i = 0; i < n; i++) {
        hs += 1LL * s[i] * pw[i] % mod;
        hs %= mod;
    }
    return hs;
}
void soln() {
    string a, b;
    cin >> a >> b;
    lli ha = getHash(a);
    lli hb = getHash(b);
    if (ha == hb)
        cout << "YES" << enl;
    else
        cout << "NO" << enl;
}
int main() {
    fast();
    preCalculate();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
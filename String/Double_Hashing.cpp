#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const lli N = 2e6 + 10;
lli pw1[N], pw2[N];
void preCalculate() {
    pw1[0] = 1;
    for (lli i = 1; i < N; i++) {
        pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
    }
    pw2[0] = 1;
    for (lli i = 1; i < N; i++) {
        pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    }
}
pair<lli, lli> getHash(string s) {
    lli n = s.size();
    lli hs1 = 0;
    for (lli i = 0; i < n; i++) {
        hs1 += 1LL * s[i] * pw1[i] % mod1;
        hs1 %= mod1;
    }
    lli hs2 = 0;
    for (lli i = 0; i < n; i++) {
        hs2 += 1LL * s[i] * pw2[i] % mod2;
        hs2 %= mod2;
    }
    return {hs1, hs2};
}
void soln() {
    string a, b;
    cin >> a >> b;
    auto ha = getHash(a);
    auto hb = getHash(b);
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
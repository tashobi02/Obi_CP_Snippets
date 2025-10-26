#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
string s;
const lli N = 2e6 + 10;
const lli p1 = 137, mod1 = 127657753;
const lli p2 = 277, mod2 = 987654319;
pair<lli, lli> pw[N], ipw[N], pref[N];
lli power(lli n, lli k, lli mod) {
    lli ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n += mod;
    while (k) {
        if (k & 1)
            ans = ans * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}
void preCalculate() {
    pw[0] = {1, 1};
    for (lli i = 1; i < N; i++) {
        pw[i].first = pw[i - 1].first * p1 % mod1;
        pw[i].second = pw[i - 1].second * p2 % mod2;
    }
    lli ip1 = power(p1, mod1 - 2, mod1);
    lli ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (lli i = 1; i < N; i++) {
        ipw[i].first = ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = ipw[i - 1].second * ip2 % mod2;
    }
}
void build(const string& s) {
    lli n = s.size();
    for (lli i = 0; i < n; i++) {
        int val = s[i] - 'a' + 1;
        pref[i].first = val * pw[i].first % mod1;
        pref[i].second = val * pw[i].second % mod2;
        if (i) {
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
        }
    }
}
pair<lli, lli> getHash(lli i, lli j) {
    assert(i <= j);
    pair<lli, lli> hs;
    hs.first = pref[j].first;
    hs.second = pref[j].second;
    if (i) {
        hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
        hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    }
    hs.first = hs.first * ipw[i].first % mod1;
    hs.second = hs.second * ipw[i].second % mod2;
    return hs;
}
lli lcp(lli i, lli j, lli x, lli y) {
    lli l = 1, r = min(j - i + 1, y - x + 1), ans = 0;
    while (l <= r) {
        lli mid = (l + r) >> 1LL;
        if (getHash(i, i + mid - 1) == getHash(x, x + mid - 1)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
lli compare(lli i, lli j, lli x, lli y) {
    lli lc = lcp(i, j, x, y);
    lli len1 = j - i + 1, len2 = y - x + 1;
    if (len1 == len2 && lc == len1)
        return 0;
    else if (lc == len1)
        return -1;
    else if (lc == len2)
        return 1;
    else
        return (s[i + lc] < s[x + lc] ? -1 : 1);
}
void soln() {
    cin >> s;
    lli n = s.size();
    s += s;
    build(s);
    lli mni = 0, mnj = n - 1;
    for (lli i = 1; i < n; i++) {
        lli x = compare(mni, mnj, i, i + n - 1);
        if (x == 1) {
            mni = i, mnj = i + n - 1;
        }
    }
    cout << s.substr(mni, n) << enl;
}
int main() {
    fast();
    preCalculate();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02

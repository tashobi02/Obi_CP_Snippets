#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2000000 + 10;
const lli p1 = 137, mod1 = 127657753;
const lli p2 = 277, mod2 = 987654319;
pair<lli, lli> pw[N], ipw[N];
lli ip1, ip2;
lli power(lli n, lli k, lli mod) {
    lli ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n += mod;
    while (k) {
        if (k & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
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

    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);

    ipw[0] = {1, 1};
    for (lli i = 1; i < N; i++) {
        ipw[i].first = ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = ipw[i - 1].second * ip2 % mod2;
    }
}
pair<lli, lli> pref1[N], pref2[N];
void build(const string& s, pair<lli, lli> pref[]) {
    lli n = (lli)s.size();
    for (lli i = 0; i < n; i++) {
        int val = s[i] - 'a' + 1;
        pref[i].first = val * pw[i].first % mod1;
        if (i)
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;

        pref[i].second = val * pw[i].second % mod2;
        if (i)
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}

pair<lli, lli> getHash(pair<lli, lli> pref[], lli i, lli j) {
    pair<lli, lli> hs;
    hs.first = pref[j].first;
    if (i)
        hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = hs.first * ipw[i].first % mod1;

    hs.second = pref[j].second;
    if (i)
        hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = hs.second * ipw[i].second % mod2;
    return hs;
}
void soln() {
    string s;
    cin >> s;
    lli n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());
    build(s, pref1);
    build(rev, pref2);
    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        lli lo = 0, hi = min(i, n - 1 - i);
        lli best = -1;
        while (lo <= hi) {
            lli mid = (lo + hi) >> 1;
            lli L = i - mid, R = i + mid;
            pair<lli, lli> h1 = getHash(pref1, L, R);
            pair<lli, lli> h2 = getHash(pref2, n - 1 - R, n - 1 - L);
            if (h1 == h2) {
                best = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        ans += (best + 1);
    }
    for (lli i = 0; i + 1 < n; i++) {
        lli lo = 0, hi = min(i, n - 2 - i);
        lli best = -1;
        while (lo <= hi) {
            lli mid = (lo + hi) >> 1;
            lli L = i - mid, R = i + 1 + mid;
            pair<lli, lli> h1 = getHash(pref1, L, R);
            pair<lli, lli> h2 = getHash(pref2, n - 1 - R, n - 1 - L);
            if (h1 == h2) {
                best = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        ans += (best + 1);
    }
    cout << ans << enl;
}
int main() {
    fast();
    preCalculate();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}
// Author: tashobi_02
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef unsigned long long int ull;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 200010;
const lli p1 = 137, mod1 = 127657753;
const lli p2 = 277, mod2 = 987654319;
vector<pair<lli, lli>> pw, ipw;
vector<pair<lli, lli>> pref1, pref2;
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
void preCalculate(lli maxN) {
    pw.assign(maxN + 1, {0, 0});
    ipw.assign(maxN + 1, {0, 0});
    pw[0] = {1, 1};
    for (int i = 1; i <= maxN; ++i) {
        pw[i].first = pw[i - 1].first * p1 % mod1;
        pw[i].second = pw[i - 1].second * p2 % mod2;
    }
    lli ip1 = power(p1, mod1 - 2, mod1);
    lli ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i <= maxN; ++i) {
        ipw[i].first = ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = ipw[i - 1].second * ip2 % mod2;
    }
}
void preCalculatePrefix(const string& s, vector<pair<lli, lli>>& pref) {
    int n = (int)s.size();
    pref.assign(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        lli val = (lli)(s[i] - 'a' + 1);
        if (val <= 0)
            val = (lli)(s[i]);
        pref[i].first = val * pw[i].first % mod1;
        pref[i].second = val * pw[i].second % mod2;
        if (i) {
            pref[i].first += pref[i - 1].first;
            if (pref[i].first >= mod1)
                pref[i].first -= mod1;
            pref[i].second += pref[i - 1].second;
            if (pref[i].second >= mod2)
                pref[i].second -= mod2;
        }
    }
}
pair<lli, lli> getHash(const vector<pair<lli, lli>>& pref, lli i, lli j) {
    pair<lli, lli> hs = pref[j];
    if (i) {
        hs.first -= pref[i - 1].first;
        if (hs.first < 0)
            hs.first += mod1;
        hs.second -= pref[i - 1].second;
        if (hs.second < 0)
            hs.second += mod2;
    }
    hs.first = hs.first * ipw[i].first % mod1;
    hs.second = hs.second * ipw[i].second % mod2;
    return hs;
}
void soln() {
    lli n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    lli maxN = n + 5;
    preCalculate(maxN);
    preCalculatePrefix(s1, pref1);
    preCalculatePrefix(s2, pref2);
    lli l = 0, r = n, bestLen = 0, bestPos = 0;
    while (l <= r) {
        lli mid = (l + r) >> 1;
        bool found = false;
        if (mid == 0) {
            found = true;
        } else {
            unordered_set<ull> st;
            st.reserve(max(1LL, n - mid + 1) * 2);
            for (int i = 0; i + mid - 1 < n; ++i) {
                auto h = getHash(pref1, i, i + mid - 1);
                ull key = ((ull)h.first << 32) ^ (ull)h.second;
                st.insert(key);
            }
            for (lli j = 0; j + mid - 1 < n && !found; ++j) {
                auto h = getHash(pref2, j, j + mid - 1);
                ull key = ((ull)h.first << 32) ^ (ull)h.second;
                if (st.find(key) != st.end()) {
                    found = true;
                    for (lli i = 0; i + mid - 1 < n; ++i) {
                        auto h1 = getHash(pref1, i, i + mid - 1);
                        ull k1 = ((ull)h1.first << 32) ^ (ull)h1.second;
                        if (k1 == key) {
                            bestPos = i;
                            break;
                        }
                    }
                }
            }
        }
        if (found) {
            bestLen = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (bestLen == 0) {
        cout << "" << enl;
    } else {
        cout << s1.substr(bestPos, bestLen) << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}
// Author: tashobi_02
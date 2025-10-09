#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
lli findLCP(const string& a, const string& b) {
    lli lcp = 0;
    lli mnl = min(a.length(), b.length());
    while (lcp < mnl && a[lcp] == b[lcp]) {
        lcp++;
    }
    return lcp;
}
void soln() {
    string s1, s2;
    cin >> s1 >> s2;
    lli lcp = findLCP(s1, s2);
    cout << lcp << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02

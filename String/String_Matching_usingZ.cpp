#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<lli> z_array(string s) {
    lli n = s.size();
    vector<lli> Z(n);
    lli l = 0, r = 0;
    for (lli i = 1; i < n; i++) {
        if (i < r) {
            Z[i] = min(r - i, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] > r) {
            l = i;
            r = i + Z[i];
        }
    }
    return Z;
}
void soln() {
    string text, match;
    cin >> text >> match;
    lli m = match.size();
    lli ct = 0;
    string merged = match + '#' + text;
    vector<lli> Z = z_array(merged);
    for (auto zz : Z) {
        if (zz == m)
            ct++;
        //    cout << zz << " ";
    }
    // cout << enl;
    cout << ct << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
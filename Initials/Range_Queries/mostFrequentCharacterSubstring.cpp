#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void soln() {
    string s;
    lli q;
    cin >> s >> q;
    const lli Alpha = 26;
    vector<vector<lli>> pfsFreq;
    lli n = s.size();
    pfsFreq.assign(n + 1, vector<lli>(Alpha, 0));
    for (lli i = 1; i <= n; i++) {
        pfsFreq[i] = pfsFreq[i - 1];
        pfsFreq[i][s[i - 1] - 'a']++;
    }
    while (q--) {
        lli l, r;
        cin >> l >> r;
        l--, r--;
        lli mx = 0;
        char mostCommon = 'a';
        for (lli i = 0; i < Alpha; i++) {
            lli ct = pfsFreq[r + 1][i] - pfsFreq[l][i];
            if (ct > mx) {
                mx = ct;
                mostCommon = 'a' + i;
            }
        }
        cout << mostCommon << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
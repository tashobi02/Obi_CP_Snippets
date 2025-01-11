#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    // you can also use vector of pairs vector of tuples
    // and even vector of vectors like 2D arrays
    vector<pair<lli, lli>> vp = {{1, 2}, {3, 4}, {5, 6}};
    for (lli i = 0; i < (lli)vp.size(); i++) {
        cout << vp[i].first << " " << vp[i].second << enl;
    }
    vector<vector<lli>> vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (lli i = 0; i < (lli)vv.size(); i++) {
        for (lli j = 0; j < (lli)vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << enl;
    }
    vector<tuple<lli, lli, lli>> vt = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (lli i = 0; i < (lli)vt.size(); i++) {
        cout << get<0>(vt[i]) << " " << get<1>(vt[i]) << " " << get<2>(vt[i])
             << enl;
    }
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> v(n, vector<lli>(m));
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    // simply you can construct custom containers to store data
    // vector of vectors, vector of stack and queue, vector of sets works too
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
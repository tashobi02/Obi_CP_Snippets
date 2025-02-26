#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> mat(n + 1, vector<lli>(n + 1, 0));
    for (lli i = 0; i < m; i++) {
        lli u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
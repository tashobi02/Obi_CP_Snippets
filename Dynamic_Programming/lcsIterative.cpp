#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    string a, b;
    cin >> a >> b;
    lli n = a.size(), m = b.size();
    vector<vector<lli>> mem(n + 1, vector<lli>(m + 1, 0));
    for (lli i = n - 1; i >= 0; i--) {
        for (lli j = m - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                mem[i][j] = mem[i + 1][j + 1] + 1;
            } else {
                mem[i][j] = max(mem[i + 1][j], mem[i][j + 1]);
            }
        }
    }
    cout << mem[0][0] << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
const lli MOD = 1e9 + 7;
lli ways[N];
void soln() {
    memset(ways, 0, sizeof ways);
    lli n;
    cin >> n;
    ways[0] = 1;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= i; j++) {
            ways[i] += ways[i - j] % MOD;
        }
    }
    cout << ways[n] << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
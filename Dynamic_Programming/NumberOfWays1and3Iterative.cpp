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
    memset(ways, -1, sizeof ways);
    lli n;
    cin >> n;
    ways[1] = 1;
    ways[2] = 1;
    ways[3] = 2;
    for (lli i = 4; i <= n; i++) {
        ways[i] = (ways[i - 1] + ways[i - 3]) % MOD;
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
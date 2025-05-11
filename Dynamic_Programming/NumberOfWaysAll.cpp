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
lli countWays(lli n) {
    if (n == 0)
        return 1;
    if (ways[n] != -1)
        return ways[n];
    lli ans = 0;
    for (lli i = 1; i <= n; i++) {
        ans += countWays(n - i);
        ans %= MOD;
    }
    return ways[n] = ans;
}
void soln() {
    memset(ways, -1, sizeof ways);
    lli n;
    cin >> n;
    lli ans = countWays(n);
    cout << ans << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
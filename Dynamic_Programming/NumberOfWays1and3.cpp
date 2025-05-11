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
/* How many different way a number n can 
be a sum of 1 and 3 */
lli countWays(lli n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (ways[n] != -1)
        return ways[n];
    return ways[n] = (countWays(n - 1) + countWays(n - 3)) % MOD;
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
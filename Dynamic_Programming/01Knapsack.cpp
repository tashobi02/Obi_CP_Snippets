#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
lli n, W;
const lli N = 105;
const lli WN = 1e5 + 5;
vector<lli> w(N, 0), v(N, 0);
lli dp[N][WN];
lli knapsack(lli i, lli weight) {
    if (dp[i][weight] != -1)
        return dp[i][weight];
    if (i == n + 1)
        return 0;
    lli ans = knapsack(i + 1, weight);
    if (weight + w[i] <= W)
        ans = max(ans, knapsack(i + 1, weight + w[i]) + v[i]);
    return dp[i][weight] = ans;
}
void soln() {
    memset(dp, -1, sizeof dp);
    cin >> n >> W;
    for (lli i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << knapsack(1, 0) << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
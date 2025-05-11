#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* Given a cost matrix cost[][] of size n x m where cost[i][j] denotes the cost
of visiting cell with co-ordinates (i, j), find a min-cost path to reach the
cell (n, m) from the cell (1, 1) under the condition that you can only travel
one step right or one step down. (Costs are positive integers) */
const lli inf = LLONG_MAX;
const lli N = 100;
lli n, m;
lli dp[N][N], matrix[N][N];
lli minCost(lli i, lli j) {
    if (j > m || i > n)
        return inf;
    if (i == n && j == m)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    lli ans = matrix[i][j] + min(minCost(i + 1, j), minCost(i, j + 1));
    return dp[i][j] = ans;
}
void soln() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << minCost(1, 1) << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
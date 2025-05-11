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
void soln() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> matrix(n + 1, vector<lli>(m + 1));
    vector<vector<lli>> dp(n + 1, vector<lli>(m + 1, LLONG_MAX));
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }
    dp[1][1] = matrix[1][1];
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= m; j++) {
            if (i > 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + matrix[i][j]);
            if (j > 1)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + matrix[i][j]);
        }
    }
    cout << dp[n][m] << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli INF = 1e9;
const lli N = 5010;
lli dp[N][N];
void soln() {
    memset(dp, INF, sizeof dp);
    lli n, w;
    cin >> n >> w;
    vector<lli> coins(n);
    for (lli i = 0; i < n; i++)
        cin >> coins[i];
    for (lli j = coins[0]; j <= w; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
    }
    for (lli i = 0; i < n; i++)
        dp[i][0] = 0;
    for (lli i = 1; i < n; i++) {
        for (lli j = 1; j <= w; j++) {
            if (coins[i] > j)
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
            }
        }
    }
    lli ans = dp[n - 1][w];
    if (ans >= INF)
        cout << -1 << enl;
    else
        cout << ans << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
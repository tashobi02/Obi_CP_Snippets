#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 5010;
lli dp[N][N];
void soln() {
    memset(dp, 0, sizeof dp);
    lli n, w;
    cin >> n >> w;
    vector<lli> coins(n);
    for (lli i = 0; i < n; i++)
        cin >> coins[i];
    for (lli i = 0; i < n; i++)
        dp[i][0] = 1;
    for (lli j = 1; j <= w; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }
    for (lli i = 1; i < n; i++) {
        for (lli j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i])
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i]]);
        }
    }
    cout << dp[n - 1][w] << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void soln() {
    lli n, W;
    cin >> n >> W;
    const lli N = 105;
    vector<lli> w(N), v(N);
    vector<vector<lli>> dp(n + 1, vector<lli>(W + 1, 0));
    for (lli i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (lli i = 1; i <= n; i++) {
        for (lli j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][W] << enl;
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}

// Author: tashobi_02 //
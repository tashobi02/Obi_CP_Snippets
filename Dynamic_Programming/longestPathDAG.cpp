#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
vector<vector<lli>> graph(N);
lli dp[N];
lli lp(lli u) {
    if (dp[u] != -1) {
        return dp[u];
    }
    lli ans = 0;
    for (auto v : graph[u]) {
        ans = max(ans, 1 + lp(v));
    }
    return dp[u] = ans;
}
void soln() {
    lli n, q;
    cin >> n >> q;
    while (q--) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    lli ans = 0;
    for (lli i = 1; i <= n; i++) {
        ans = max(ans, lp(i));
    }
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
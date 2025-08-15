#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
vector<lli> graph[N];
lli dp[N];
lli ind[N];
void soln() {
    lli n, q;
    cin >> n >> q;
    while (q--) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        ind[v]++;
    }
    queue<lli> qn;
    for (lli i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            qn.push(i);
        }
    }
    fill(dp, dp + n + 1, 0);
    while (!qn.empty()) {
        lli u = qn.front();
        qn.pop();
        for (auto v : graph[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            ind[v]--;
            if (ind[v] == 0) {
                qn.push(v);
            }
        }
    }
    lli ans = 0;
    for (lli i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
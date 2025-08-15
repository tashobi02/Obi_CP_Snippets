#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Given a rooted tree with n nodes. Find the sizes of all Subtrees in O(n)
const lli N = 2e6 + 10;
lli dp[N];
vector<vector<lli>> graph(N);
void DFS(lli v, lli p) {
    dp[v] = 1;
    // cout << v << " ";
    for (auto u : graph[v]) {
        if (u != p) {
            DFS(u, v);
            dp[v] += dp[u];
        }
    }
}
void soln() {
    lli n, e;
    cin >> n >> e;
    for (lli i = 0; i < e; i++) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    lli start = 1;
    // cin >> start;
    DFS(start, 0);
    for (lli i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}
// Author: tashobi_02 //

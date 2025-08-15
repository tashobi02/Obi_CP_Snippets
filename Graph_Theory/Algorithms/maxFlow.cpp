#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<vector<lli>> capacity;
vector<vector<lli>> adj;
lli BFS(lli s, lli t, vector<lli>& parent) {
    const lli INF = 1e18;
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<lli, lli>> q;
    q.push({s, INF});
    while (!q.empty()) {
        lli cur = q.front().first;
        lli flow = q.front().second;
        q.pop();
        for (lli next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                lli newFlow = min(flow, capacity[cur][next]);
                if (next == t)
                    return newFlow;
                q.push({next, newFlow});
            }
        }
    }
    return 0;
}
lli maxFlow(lli s, lli t, lli n) {
    lli flow = 0;
    vector<lli> parent(n + 1);
    while (true) {
        lli newFlow = BFS(s, t, parent);
        if (newFlow == 0)
            break;
        flow += newFlow;
        lli cur = t;
        while (cur != s) {
            lli prev = parent[cur];
            capacity[prev][cur] -= newFlow;
            capacity[cur][prev] += newFlow;
            cur = prev;
        }
    }
    return flow;
}
void soln() {
    lli n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    capacity.assign(n + 1, vector<lli>(n + 1, 0));
    for (lli i = 0; i < m; ++i) {
        lli u, v, cap;
        cin >> u >> v >> cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += cap;
    }
    lli s, t;
    cin >> s >> t;
    cout << maxFlow(s, t, n) << enl;
}
int main() {
    fast();
    lli t = 1;
    //   cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
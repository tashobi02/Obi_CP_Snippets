#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
#define INF 1e18
const lli N = 2e6 + 10;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<vector<pair<lli, lli>>> graph(N);  // {node, weight}
vector<lli> dist(N + 1, INF);
priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>>
    pq;
void dijkstra(lli start) {
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        lli d = pq.top().first;
        lli u = pq.top().second;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &[v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void soln() {
    lli n, m;
    cin >> n >> m;
    for (lli i = 0; i <= n; i++) graph[i].clear();  // clear previous graph
    for (lli i = 0; i < m; i++) {
        lli u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    lli start = 1;  // default starting node
    dijkstra(start);
    for (lli i = 1; i <= n; i++) {
        if (dist[i] != INF)
            cout << dist[i] << enl;
    }
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}

// Author: tashobi_02 //
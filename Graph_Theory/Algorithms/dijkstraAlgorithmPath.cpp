#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
#define INF 1e18

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
vector<vector<pair<lli, lli>>> graph(N);  // {node, weight}
vector<lli> dist(N + 1, INF);
vector<lli> parent(N + 1, -1);
priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>>
    pq;
void dijkstra(lli start) {
    dist[start] = 0;
    parent[start] = -1;
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
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}
vector<lli> getPath(lli target) {
    vector<lli> path;
    while (target != -1) {
        path.push_back(target);
        target = parent[target];
    }
    reverse(path.begin(), path.end());
    return path;
}
void soln() {
    lli n, m;
    cin >> n >> m;
    for (lli i = 0; i < m; i++) {
        lli u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    lli source = 1, target = n;
    // cin >> source >> target;
    dijkstra(source);
    if (dist[target] == INF) {
        // cout << "No path from " << source << " to " << target << enl;
        cout << -1 << enl;
    } else {
        // cout << "Shortest distance from " << source << " to " << target << "
        // is: " << dist[target] << enl;
        vector<lli> path = getPath(target);
        // cout << "Path: ";
        for (lli node : path) {
            cout << node << " ";
        }
        cout << enl;
    }
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}

// Author: tashobi_02 //
